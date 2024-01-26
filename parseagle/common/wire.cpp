#include <QtCore>
#include "wire.h"
#include "../common/domelement.h"

namespace parseagle {

Wire::Wire(const DomElement& root, QStringList* errors)
{
    mLayer = root.getAttributeAsInt("layer");
    mWidth = root.getAttributeAsDouble("width");
    mP1.x = root.getAttributeAsDouble("x1");
    mP1.y = root.getAttributeAsDouble("y1");
    mP2.x = root.getAttributeAsDouble("x2");
    mP2.y = root.getAttributeAsDouble("y2");
    if (root.hasAttribute("style")) {
        mWireStyle = parseWireStyle(root.getAttributeAsString("style"), errors);
    }
    if (root.hasAttribute("curve")) {
        mCurve = root.getAttributeAsDouble("curve");
    }
    if (root.hasAttribute("cap")) {
        mWireCap = parseWireCap(root.getAttributeAsString("cap"), errors);
    }
}

Wire::~Wire() noexcept
{
}

} // namespace parseagle
