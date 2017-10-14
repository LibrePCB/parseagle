#include <QtCore>
#include "device.h"
#include "../common/domelement.h"

namespace parseagle {

Device::Device(const DomElement& root)
{
    if (root.hasAttribute("name")) {
        mName = root.getAttributeAsString("name");
    }

    if (root.hasAttribute("package")) {
        mPackage = root.getAttributeAsString("package");
    }

    if (root.hasChild("connects")) {
        foreach (const DomElement& child, root.getFirstChild("connects").getChilds()) {
            mConnections.append(Connection(child));
        }
    }
}

Device::~Device() noexcept
{
}

} // namespace parseagle
