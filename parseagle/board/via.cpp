#include <QtCore>
#include "via.h"
#include "../common/domelement.h"

namespace parseagle {

Via::Via(const DomElement& root, QStringList* errors)
{
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");
    mExtent = root.getAttributeAsString("extent");
    mDrill = root.getAttributeAsDouble("drill");
    if (root.hasAttribute("diameter")) {
        mDiameter = root.getAttributeAsDouble("diameter");
    }
    if (root.hasAttribute("shape")) {
        mShape = parseViaShape(root.getAttributeAsString("shape"), errors);
    }
    if (root.hasAttribute("alwaysstop")) {
        mAlwaysStop = root.getAttributeAsBool("alwaysstop");
    }
}

Via::~Via() noexcept
{
}

bool Via::tryGetStartLayer(int& layer) const noexcept
{
    bool ok = false;
    layer = mExtent.section('-', 0, 0).toInt(&ok);
    return ok;
}

bool Via::tryGetEndLayer(int& layer) const noexcept
{
    bool ok = false;
    layer = mExtent.section('-', 1, 1).toInt(&ok);
    return ok;
}

} // namespace parseagle
