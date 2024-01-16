#include <QtCore>
#include "part.h"
#include "../common/domelement.h"

namespace parseagle {

Part::Part(const DomElement& root)
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
}

Part::~Part() noexcept
{
}

} // namespace parseagle
