#include <QtCore>
#include "circle.h"
#include "../common/domelement.h"

namespace parseagle {

Circle::Circle(const DomElement& root)
{
    mLayer = root.getAttributeAsInt("layer");
    mWidth = root.getAttributeAsDouble("width");
    mRadius = root.getAttributeAsDouble("radius");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
}

Circle::~Circle() noexcept
{
}

} // namespace parseagle
