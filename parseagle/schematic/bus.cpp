#include <QtCore>
#include "bus.h"
#include "../common/domelement.h"

namespace parseagle {

Bus::Bus(const DomElement& root)
{
    mName = root.getAttributeAsString("name");
}

Bus::~Bus() noexcept
{
}

} // namespace parseagle
