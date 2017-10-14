#include <QtCore>
#include "polygon.h"
#include "domelement.h"

namespace parseagle {

Polygon::Polygon(const DomElement& root)
{
    mLayer = root.getAttributeAsInt("layer");
    mWidth = root.getAttributeAsDouble("width");
    foreach (const DomElement& child, root.getChilds()) {
        mVertices.append(Vertex(child));
    }
}

Polygon::~Polygon() noexcept
{
}

} // namespace parseagle
