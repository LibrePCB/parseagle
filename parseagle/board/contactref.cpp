#include <QtCore>
#include "contactref.h"
#include "../common/domelement.h"

namespace parseagle {

ContactRef::ContactRef(const DomElement& root)
{
    mElement = root.getAttributeAsString("element");
    mPad = root.getAttributeAsString("pad");
}

ContactRef::~ContactRef() noexcept
{
}

} // namespace parseagle
