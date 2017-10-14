#include <QtCore>
#include "connection.h"
#include "../common/domelement.h"

namespace parseagle {

Connection::Connection(const DomElement& root)
{
    mGate = root.getAttributeAsString("gate");
    mPin = root.getAttributeAsString("pin");
    mPad = root.getAttributeAsString("pad");
}

Connection::~Connection() noexcept
{
}

} // namespace parseagle
