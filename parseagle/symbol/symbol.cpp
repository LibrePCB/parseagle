#include <QtCore>
#include "symbol.h"
#include "../common/domelement.h"

namespace parseagle {

Symbol::Symbol(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "description") {
            mDescription = child.getText();
        } else if (child.getTagName() == "wire") {
            mWires.append(Wire(child, errors));
        } else if (child.getTagName() == "rectangle") {
            mRectangles.append(Rectangle(child));
        } else if (child.getTagName() == "circle") {
            mCircles.append(Circle(child));
        } else if (child.getTagName() == "polygon") {
            mPolygons.append(Polygon(child, errors));
        } else if (child.getTagName() == "text") {
            mTexts.append(Text(child, errors));
        } else if (child.getTagName() == "pin") {
            mPins.append(Pin(child, errors));
        } else if (child.getTagName() == "frame") {
            mFrames.append(Frame(child));
        } else if (child.getTagName() == "dimension") {
            mDimensions.append(Dimension(child));
        } else if (errors) {
            errors->append("Unknown symbol child: " + child.getTagName());
        }
    }
}

Symbol::~Symbol() noexcept
{
}

} // namespace parseagle
