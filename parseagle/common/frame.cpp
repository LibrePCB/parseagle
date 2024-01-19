#include <QtCore>
#include "frame.h"
#include "../common/domelement.h"

namespace parseagle {

Frame::Frame(const DomElement& root)
{
    mLayer = root.getAttributeAsInt("layer");
    mP1.x = root.getAttributeAsDouble("x1");
    mP1.y = root.getAttributeAsDouble("y1");
    mP2.x = root.getAttributeAsDouble("x2");
    mP2.y = root.getAttributeAsDouble("y2");
    mColumns = root.getAttributeAsInt("columns");
    mRows = root.getAttributeAsInt("rows");
}

Frame::~Frame() noexcept
{
}

} // namespace parseagle
