#include <QtCore>
#include "rectangle.h"
#include "../common/domelement.h"

namespace parseagle {

Rectangle::Rectangle(const DomElement& root)
{
    mLayer = root.getAttributeAsInt("layer");
    mP1.x = root.getAttributeAsDouble("x1");
    mP1.y = root.getAttributeAsDouble("y1");
    mP2.x = root.getAttributeAsDouble("x2");
    mP2.y = root.getAttributeAsDouble("y2");
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
}

Rectangle::~Rectangle() noexcept
{
}

} // namespace parseagle
