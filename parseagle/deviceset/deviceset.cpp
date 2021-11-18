#include <QtCore>
#include "deviceset.h"
#include "../common/domelement.h"

namespace parseagle {

DeviceSet::DeviceSet(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");

    if (root.hasAttribute("prefix")) {
        mPrefix = root.getAttributeAsString("prefix");
    }

    if (root.hasChild("description")) {
        mDescription = root.getFirstChild("description").getText();
    }

    if (root.hasChild("gates")) {
        foreach (const DomElement& child, root.getFirstChild("gates").getChilds()) {
            mGates.append(Gate(child, errors));
        }
    }
    if (root.hasChild("devices")) {
        foreach (const DomElement& child, root.getFirstChild("devices").getChilds()) {
            mDevices.append(Device(child));
        }
    }
}

DeviceSet::~DeviceSet() noexcept
{
}

} // namespace parseagle
