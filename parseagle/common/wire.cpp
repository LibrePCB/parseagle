#include <QtCore>
#include "wire.h"
#include "../common/domelement.h"

namespace parseagle {

Wire::Wire(const DomElement& root)
{
    mLayer = root.getAttributeAsInt("layer");
    mWidth = root.getAttributeAsDouble("width");
    mP1.x = root.getAttributeAsDouble("x1");
    mP1.y = root.getAttributeAsDouble("y1");
    mP2.x = root.getAttributeAsDouble("x2");
    mP2.y = root.getAttributeAsDouble("y2");

    if (root.hasAttribute("curve")) {
        mCurve = root.getAttributeAsDouble("curve");
    } else {
        mCurve = 0.0;
    }
}

Wire::~Wire() noexcept
{
}

} // namespace parseagle
