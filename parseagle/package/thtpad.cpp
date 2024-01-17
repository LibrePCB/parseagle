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
    } else {
        mOuterDiameter = 0.0;
    }

    if (root.hasAttribute("shape")) {
        mShape = parsePadShape(root.getAttributeAsString("shape"), errors);
    }
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
}

ThtPad::~ThtPad() noexcept
{
}

} // namespace parseagle
