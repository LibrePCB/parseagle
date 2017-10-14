#include <QtCore>
#include "smtpad.h"
#include "../common/domelement.h"

namespace parseagle {

SmtPad::SmtPad(const DomElement& root)
{
    mName = root.getAttributeAsString("name");
    mLayer = root.getAttributeAsInt("layer");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    mWidth = root.getAttributeAsDouble("dx");
    mHeight = root.getAttributeAsDouble("dy");
}

SmtPad::~SmtPad() noexcept
{
}

} // namespace parseagle
