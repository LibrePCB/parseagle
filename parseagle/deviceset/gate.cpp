#include <QtCore>
#include "gate.h"
#include "../common/domelement.h"

namespace parseagle {

Gate::Gate(const DomElement& root)
{
    mName = root.getAttributeAsString("name");
    mSymbol = root.getAttributeAsString("symbol");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");

    if (root.hasAttribute("addlevel")) {
        QString addLevelStr = root.getAttributeAsString("addlevel");
        if (addLevelStr == "must") {
            mAddLevel = AddLevel::Must;
        } else if (addLevelStr == "can") {
            mAddLevel = AddLevel::Can;
        } else if (addLevelStr == "next") {
            mAddLevel = AddLevel::Next;
        } else if (addLevelStr == "request") {
            mAddLevel = AddLevel::Request;
        } else if (addLevelStr == "always") {
            mAddLevel = AddLevel::Always;
        } else {
            throw std::runtime_error("Unknown add level: " + addLevelStr.toStdString());
        }
    } else {
        mAddLevel = AddLevel::Next;
    }
}

Gate::~Gate() noexcept
{
}

} // namespace parseagle
