#include <QtCore>
#include "text.h"
#include "../common/domelement.h"

namespace parseagle {

Text::Text(const DomElement& root, QStringList* errors)
{
    mLayer = root.getAttributeAsInt("layer");
    mSize = root.getAttributeAsDouble("size");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    if (root.hasAttribute("rot")) {
        mRotation = Rotation(root.getAttributeAsString("rot"));
    }
    mAlignment = Alignment::Unknown;
    if (root.hasAttribute("align")) {
        QString alignStr = root.getAttributeAsString("align");
        if (alignStr == "bottom-left") {
            mAlignment = Alignment::BottomLeft;
        } else if (alignStr == "bottom-center") {
            mAlignment = Alignment::BottomCenter;
        } else if (alignStr == "bottom-right") {
            mAlignment = Alignment::BottomRight;
        } else if (alignStr == "center-left") {
            mAlignment = Alignment::CenterLeft;
        } else if (alignStr == "center") {
            mAlignment = Alignment::Center;
        } else if (alignStr == "center-right") {
            mAlignment = Alignment::CenterRight;
        } else if (alignStr == "top-left") {
            mAlignment = Alignment::TopLeft;
        } else if (alignStr == "top-center") {
            mAlignment = Alignment::TopCenter;
        } else if (alignStr == "top-right") {
            mAlignment = Alignment::TopRight;
        } else if (errors) {
            errors->append("Unknown text alignment: " + alignStr);
        }
    } else {
        mAlignment = Alignment::BottomLeft;
    }
    mValue = root.getText();
}

Text::~Text() noexcept
{
}

} // namespace parseagle
