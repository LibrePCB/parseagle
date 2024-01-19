#include <QtCore>
#include "pinref.h"
#include "../common/domelement.h"

namespace parseagle {

PinRef::PinRef(const DomElement& root)
{
    mPart = root.getAttributeAsString("part");
    mGate = root.getAttributeAsString("gate");
    mPin = root.getAttributeAsString("pin");
}

PinRef::~PinRef() noexcept
{
}

} // namespace parseagle
