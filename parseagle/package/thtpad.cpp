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

    mShape = Shape::Unknown;
    if (root.hasAttribute("shape")) {
        QString shapeStr = root.getAttributeAsString("shape");
        if (shapeStr == "square") {
            mShape = Shape::Square;
        } else if (shapeStr == "octagon") {
            mShape = Shape::Octagon;
        } else if (shapeStr == "round") {
            mShape = Shape::Round;
        } else if (shapeStr == "long") {
            mShape = Shape::Long;
        } else if (shapeStr == "offset") {
            mShape = Shape::Offset;
        } else if (errors) {
            errors->append("Unknown pad shape: " + shapeStr);
        }
    } else {
        mShape = Shape::Round;
    }

    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
}

ThtPad::~ThtPad() noexcept
{
}

} // namespace parseagle
