#include <QtCore>
#include "thtpad.h"
#include "../common/domelement.h"

namespace parseagle {

ThtPad::ThtPad(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    mDrillDiameter = root.getAttributeAsDouble("drill");
    if (root.hasAttribute("diameter")) {
        mOuterDiameter = root.getAttributeAsDouble("diameter");
    }
    if (root.hasAttribute("shape")) {
        mShape = parsePadShape(root.getAttributeAsString("shape"), errors);
    }
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    if (root.hasAttribute("stop")) {
        mStop = root.getAttributeAsBool("stop");
    }
}

ThtPad::~ThtPad() noexcept
{
}

} // namespace parseagle
