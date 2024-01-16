#include <QtCore>
#include "label.h"
#include "../common/domelement.h"

namespace parseagle {

Label::Label(const DomElement& root, QStringList* errors)
{
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    mSize = root.getAttributeAsDouble("size");
    mLayer = root.getAttributeAsInt("layer");
    if (root.hasAttribute("ratio")) {
        mRatio = root.getAttributeAsInt("ratio");
    }
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    if (root.hasAttribute("align")) {
        mAlignment = parseAlignment(root.getAttributeAsString("align"), errors);
    }
    if (root.hasAttribute("xref")) {
        mXref = root.getAttributeAsBool("xref");
    }
}

Label::~Label() noexcept
{
}

} // namespace parseagle
