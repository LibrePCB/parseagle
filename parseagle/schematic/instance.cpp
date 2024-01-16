#include <QtCore>
#include "instance.h"
#include "../common/domelement.h"

namespace parseagle {

Instance::Instance(const DomElement& root, QStringList* errors)
{
    mPart = root.getAttributeAsString("part");
    mGate = root.getAttributeAsString("gate");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    if (root.hasAttribute("smashed")) {
        mSmashed = root.getAttributeAsBool("smashed");
    }
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "attribute") {
            mAttributes.append(Attribute(child, errors));
        } else  if (errors) {
            errors->append("Unknown instance child: " + child.getTagName());
        }
    }
}

Instance::~Instance() noexcept
{
}

} // namespace parseagle
