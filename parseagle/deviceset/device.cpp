#include <QtCore>
#include "device.h"
#include "../common/domelement.h"

namespace parseagle {

Device::Device(const DomElement& root, QStringList* errors)
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
    if (root.hasChild("technologies")) {
        foreach (const DomElement& child, root.getFirstChild("technologies").getChilds()) {
            mTechnologies.append(Technology(child, errors));
        }
    }
}

Device::~Device() noexcept
{
}

} // namespace parseagle
