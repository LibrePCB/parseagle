#include <QtCore>
#include "hole.h"
#include "../common/domelement.h"

namespace parseagle {

Hole::Hole(const DomElement& root)
{
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    mDiameter = root.getAttributeAsDouble("drill");
}

Hole::~Hole() noexcept
{
}

} // namespace parseagle
