#include <QtCore>
#include "pin.h"
#include "../common/domelement.h"

namespace parseagle {

Pin::Pin(const DomElement& root)
{
    mName = root.getAttributeAsString("name");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");

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
        } else {
            throw std::runtime_error("Unknown pin length: " + lengthStr.toStdString());
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
