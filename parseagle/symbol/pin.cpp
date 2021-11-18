#include <QtCore>
#include "pin.h"
#include "../common/domelement.h"

namespace parseagle {

Pin::Pin(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");

    mLength = Length::Unknown;
    if (root.hasAttribute("length")) {
        QString lengthStr = root.getAttributeAsString("length");
        if (lengthStr == "point") {
            mLength = Length::Point;
        } else if (lengthStr == "short") {
            mLength = Length::Short;
        } else if (lengthStr == "middle") {
            mLength = Length::Middle;
        } else if (lengthStr == "long") {
            mLength = Length::Long;
        } else if (errors) {
            errors->append("Unknown pin length: " + lengthStr);
        }
    } else {
        mLength = Length::Long;
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
        case Length::Point:     return 0.0;
        case Length::Short:     return 2.54;
        case Length::Middle:    return 5.08;
        case Length::Long:      return 7.62;
        default:                return 0.0;
    }
}

} // namespace parseagle
