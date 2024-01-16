#include <QtCore>
#include "text.h"
#include "../common/domelement.h"

namespace parseagle {

Text::Text(const DomElement& root, QStringList* errors)
{
    mLayer = root.getAttributeAsInt("layer");
    if (root.hasAttribute("font")) {
        mFont = parseFont(root.getAttributeAsString("font"), errors);
    }
    mSize = root.getAttributeAsDouble("size");
    if (root.hasAttribute("ratio")) {
        mRatio = root.getAttributeAsInt("ratio");
    }
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    if (root.hasAttribute("align")) {
        mAlignment = parseAlignment(root.getAttributeAsString("align"), errors);
    }
    mValue = root.getText();
}

Text::~Text() noexcept
{
}

} // namespace parseagle
