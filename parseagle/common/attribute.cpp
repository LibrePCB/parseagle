#include <QtCore>
#include "attribute.h"
#include "../common/domelement.h"

namespace parseagle {

Attribute::Attribute(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    if (root.hasAttribute("value")) {
        mValue = root.getAttributeAsString("value");
    }
    if (root.hasAttribute("x")) {
        mPosition.x = root.getAttributeAsDouble("x");
    }
    if (root.hasAttribute("y")) {
        mPosition.y = root.getAttributeAsDouble("y");
    }
    if (root.hasAttribute("size")) {
        mSize = root.getAttributeAsDouble("size");
    }
    if (root.hasAttribute("layer")) {
        mLayer = root.getAttributeAsInt("layer");
    }
    if (root.hasAttribute("font")) {
        mFont = parseFont(root.getAttributeAsString("font"), errors);
    }
    if (root.hasAttribute("ratio")) {
        mRatio = root.getAttributeAsInt("ratio");
    }
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    if (root.hasAttribute("display")) {
        mDisplay = parseAttributeDisplay(root.getAttributeAsString("display"), errors);
    }
    if (root.hasAttribute("constant")) {
        mConstant = root.getAttributeAsBool("constant");
    }
    if (root.hasAttribute("align")) {
        mAlignment = parseAlignment(root.getAttributeAsString("align"), errors);
    }
}

Attribute::~Attribute() noexcept
{
}

} // namespace parseagle
