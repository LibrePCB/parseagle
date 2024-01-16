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
    if (root.hasAttribute("addlevel")) {
        mAddLevel = parseGateAddLevel(root.getAttributeAsString("addlevel"), errors);
    }
}

Gate::~Gate() noexcept
{
}

} // namespace parseagle
