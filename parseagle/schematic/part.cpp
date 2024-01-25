#include <QtCore>
#include "part.h"
#include "../common/domelement.h"

namespace parseagle {

Part::Part(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    mLibrary = root.getAttributeAsString("library");
    if (root.hasAttribute("library_urn")) {
        mLibraryUrn = root.getAttributeAsString("library_urn");
    }
    mDeviceSet = root.getAttributeAsString("deviceset");
    mDevice = root.getAttributeAsString("device");
    if (root.hasAttribute("technology")) {
        mTechnology = root.getAttributeAsString("technology");
    }
    if (root.hasAttribute("value")) {
        mValue = root.getAttributeAsString("value");
    }
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "attribute") {
            mAttributes.append(Attribute(child, errors));
        } else  if (errors) {
            errors->append("Unknown part child: " + child.getTagName());
        }
    }
}

Part::~Part() noexcept
{
}

} // namespace parseagle
