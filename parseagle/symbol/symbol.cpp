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
            mWires.append(Wire(child));
        } else if (child.getTagName() == "rectangle") {
            mRectangles.append(Rectangle(child));
        } else if (child.getTagName() == "circle") {
            mCircles.append(Circle(child));
        } else if (child.getTagName() == "polygon") {
            mPolygons.append(Polygon(child));
        } else if (child.getTagName() == "text") {
            mTexts.append(Text(child, errors));
        } else if (child.getTagName() == "pin") {
            mPins.append(Pin(child, errors));
        } else if (errors) {
            errors->append("Unknown symbol child: " + child.getTagName());
        }
    }
}

Symbol::~Symbol() noexcept
{
}

} // namespace parseagle
