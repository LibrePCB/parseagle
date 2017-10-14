#include <QtCore>
#include "text.h"
#include "../common/domelement.h"

namespace parseagle {

Text::Text(const DomElement& root)
{
    mLayer = root.getAttributeAsInt("layer");
    mSize = root.getAttributeAsDouble("size");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    mValue = root.getText();
}

Text::~Text() noexcept
{
}

} // namespace parseagle
