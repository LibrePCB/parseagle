#include <QtCore>
#include "element.h"
#include "../common/domelement.h"

namespace parseagle {

Element::Element(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    mLibrary = root.getAttributeAsString("library");
    if (root.hasAttribute("library_urn")) {
        mLibraryUrn = root.getAttributeAsString("library_urn");
    }
    mPackage = root.getAttributeAsString("package");
    mValue = root.getAttributeAsString("value");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    if (root.hasAttribute("locked")) {
        mLocked = root.getAttributeAsBool("locked");
    }
    if (root.hasAttribute("populate")) {
        mPopulate = root.getAttributeAsBool("populate");
    }
    if (root.hasAttribute("smashed")) {
        mSmashed = root.getAttributeAsBool("smashed");
    }
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "attribute") {
            mAttributes.append(Attribute(child, errors));
        } else  if (errors) {
            errors->append("Unknown element child: " + child.getTagName());
        }
    }
}

Element::~Element() noexcept
{
}

} // namespace parseagle
