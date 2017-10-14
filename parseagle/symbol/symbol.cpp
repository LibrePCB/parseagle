#include <QtCore>
#include "symbol.h"
#include "../common/domelement.h"

namespace parseagle {

Symbol::Symbol(const DomElement& root)
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
        } else if (child.getTagName() == "pin") {
            mPins.append(Pin(child));
        } else {
            throw std::runtime_error("Unknown symbol child: " + child.getTagName().toStdString());
        }
    }
}

Symbol::~Symbol() noexcept
{
}

} // namespace parseagle
