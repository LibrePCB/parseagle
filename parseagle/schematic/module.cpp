#include <QtCore>
#include "module.h"
#include "../common/domelement.h"

namespace parseagle {

Module::Module(const DomElement& root)
{
    mName = root.getAttributeAsString("name");
}

Module::~Module() noexcept
{
}

} // namespace parseagle
