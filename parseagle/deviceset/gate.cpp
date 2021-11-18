#include <QtCore>
#include "gate.h"
#include "../common/domelement.h"

namespace parseagle {

Gate::Gate(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    mSymbol = root.getAttributeAsString("symbol");
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");

    mAddLevel = AddLevel::Unknown;
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
        } else if (errors) {
            errors->append("Unknown gate addlevel: " + addLevelStr);
        }
    } else {
        mAddLevel = AddLevel::Next;
    }
}

Gate::~Gate() noexcept
{
}

} // namespace parseagle
