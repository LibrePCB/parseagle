#include <QtCore>
#include "pin.h"
#include "../common/domelement.h"

namespace parseagle {

Pin::Pin(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    if (root.hasAttribute("length")) {
        mLength = parsePinLength(root.getAttributeAsString("length"), errors);
    }
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
}

Pin::~Pin() noexcept
{
}

double Pin::getLengthInMillimeters() const noexcept
{
    switch (mLength) {
        case PinLength::Point:     return 0.0;
        case PinLength::Short:     return 2.54;
        case PinLength::Middle:    return 5.08;
        case PinLength::Long:      return 7.62;
        default:                   return 0.0;
    }
}

} // namespace parseagle
