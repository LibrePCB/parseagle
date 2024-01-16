#include <QtCore>
#include "grid.h"
#include "../common/domelement.h"

namespace parseagle {


Grid::Grid(const DomElement& root, QStringList* errors)
{
    if (root.hasAttribute("distance")) {
        mDistance = root.getAttributeAsDouble("distance");
    }
    if (root.hasAttribute("unitdist")) {
        mUnitDistance = parseGridUnit(root.getAttributeAsString("unitdist"), errors);
    }
    if (root.hasAttribute("unit")) {
        mUnit = parseGridUnit(root.getAttributeAsString("unit"), errors);
    }
    if (root.hasAttribute("style")) {
        mStyle = parseGridStyle(root.getAttributeAsString("style"), errors);
    }
    if (root.hasAttribute("multiple")) {
        mMultiple = root.getAttributeAsInt("multiple");
    }
    if (root.hasAttribute("display")) {
        mDisplay = root.getAttributeAsBool("display");
    }
    if (root.hasAttribute("altdistance")) {
        mAltDistance = root.getAttributeAsDouble("altdistance");
    }
    if (root.hasAttribute("altunitdist")) {
        mAltUnitDistance = parseGridUnit(root.getAttributeAsString("altunitdist"), errors);
    }
    if (root.hasAttribute("altunit")) {
        mAltUnit = parseGridUnit(root.getAttributeAsString("altunit"), errors);
    }
}

Grid::~Grid() noexcept
{
}

} // namespace parseagle
