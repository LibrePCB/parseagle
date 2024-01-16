#include <QtCore>
#include "schematic.h"
#include "../common/domelement.h"

namespace parseagle {

Schematic::Schematic(const QString& filepath, QStringList* errors)
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

Schematic::Schematic(const QByteArray& content, QStringList* errors)
{
    load(content, errors);
}

Schematic::~Schematic() noexcept
{
}

void Schematic::load(const QByteArray& content, QStringList* errors) {
    QDomDocument doc;
    doc.implementation().setInvalidDataPolicy(QDomImplementation::ReturnNullNode);
    QString errMsg;
    if (!doc.setContent(content, &errMsg)) {
        throw std::runtime_error(
            "Error while parsing EAGLE schematic: " + errMsg.toStdString());
    }
    DomElement root(doc.documentElement());
    DomElement drawing = root.getFirstChild("drawing");

    if (drawing.hasChild("grid")) {
        mGrid = Grid(drawing.getFirstChild("grid"));
    }

    DomElement schematic = drawing.getFirstChild("schematic");
    if (schematic.hasChild("description")) {
        mDescription = schematic.getFirstChild("description").getText();
    }
    if (schematic.hasChild("libraries")) {
        foreach (const DomElement& child, schematic.getFirstChild("libraries").getChilds()) {
            mLibraries.append(Library(child, errors));
        }
    }
    if (schematic.hasChild("modules")) {
        foreach (const DomElement& child, schematic.getFirstChild("modules").getChilds()) {
            mModules.append(Module(child));
        }
    }
    if (schematic.hasChild("parts")) {
        foreach (const DomElement& child, schematic.getFirstChild("parts").getChilds()) {
            mParts.append(Part(child));
        }
    }
    if (schematic.hasChild("sheets")) {
        foreach (const DomElement& child, schematic.getFirstChild("sheets").getChilds()) {
            mSheets.append(Sheet(child, errors));
        }
    }
}

} // namespace parseagle
