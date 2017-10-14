#include <QtCore>
#include "package.h"
#include "../common/domelement.h"

namespace parseagle {

Package::Package(const DomElement& root)
{
    mName = root.getAttributeAsString("name");
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "description") {
            mDescription = child.getText();
        } else if (child.getTagName() == "wire") {
            mWires.append(Wire(child));
        } else if (child.getTagName() == "rectangle") {
            mRectangles.append(Rectangle(child));
        } else if (child.getTagName() == "circle") {
            mCircles.append(Circle(child));
        } else if (child.getTagName() == "polygon") {
            mPolygons.append(Polygon(child));
        } else if (child.getTagName() == "text") {
            mTexts.append(Text(child));
        } else if (child.getTagName() == "hole") {
            mHoles.append(Hole(child));
        } else if (child.getTagName() == "pad") {
            mThtPads.append(ThtPad(child));
        } else if (child.getTagName() == "smd") {
            mSmtPads.append(SmtPad(child));
        } else {
            throw std::runtime_error("Unknown package child: " + child.getTagName().toStdString());
        }
    }
}

Package::~Package() noexcept
{
}

} // namespace parseagle
