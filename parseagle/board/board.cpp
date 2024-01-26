#include <QtCore>
#include "board.h"
#include "../common/domelement.h"

namespace parseagle {

Board::Board(const QString& filepath, QStringList* errors)
{
    QFile file(filepath);
    if (!file.exists()) {
        throw std::runtime_error("File does not exist: " + filepath.toStdString());
    }
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Cannot open file " + filepath.toStdString() +
                                 ": " + file.errorString().toStdString());
    }
    load(file.readAll(), errors);
}

Board::Board(const QByteArray& content, QStringList* errors)
{
    load(content, errors);
}

Board::~Board() noexcept
{
}

void Board::load(const QByteArray& content, QStringList* errors)
{
    QDomDocument doc;
    doc.implementation().setInvalidDataPolicy(QDomImplementation::ReturnNullNode);
    QString errMsg;
    if (!doc.setContent(content, &errMsg)) {
        throw std::runtime_error(
            "Error while parsing EAGLE board: " + errMsg.toStdString());
    }
    DomElement root(doc.documentElement());
    DomElement drawing = root.getFirstChild("drawing");

    if (drawing.hasChild("grid")) {
        mGrid = Grid(drawing.getFirstChild("grid"));
    }

    DomElement board = drawing.getFirstChild("board");
    if (board.hasChild("designrules")) {
        mDesignRules = DesignRules(board.getFirstChild("designrules"), errors);
    }
    if (board.hasChild("libraries")) {
        foreach (const DomElement& child, board.getFirstChild("libraries").getChilds()) {
            mLibraries.append(Library(child));
        }
    }
    if (board.hasChild("plain")) {
        foreach (const DomElement& child, board.getFirstChild("plain").getChilds()) {
            if (child.getTagName() == "wire") {
                mWires.append(Wire(child, errors));
            } else if (child.getTagName() == "rectangle") {
                mRectangles.append(Rectangle(child));
            } else if (child.getTagName() == "circle") {
                mCircles.append(Circle(child));
            } else if (child.getTagName() == "polygon") {
                mPolygons.append(Polygon(child, errors));
            } else if (child.getTagName() == "text") {
                mTexts.append(Text(child, errors));
            } else if (child.getTagName() == "hole") {
                mHoles.append(Hole(child));
            } else if (child.getTagName() == "dimension") {
                mDimensions.append(Dimension(child));
            } else if (errors) {
                errors->append("Unknown board child: " + child.getTagName());
            }
        }
    }
    if (board.hasChild("elements")) {
        foreach (const DomElement& child, board.getFirstChild("elements").getChilds()) {
            mElements.append(Element(child, errors));
        }
    }
    if (board.hasChild("signals")) {
        foreach (const DomElement& child, board.getFirstChild("signals").getChilds()) {
            mSignals.append(Signal(child, errors));
        }
    }
}

} // namespace parseagle
