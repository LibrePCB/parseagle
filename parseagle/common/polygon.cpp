#include <QtCore>
#include "polygon.h"
#include "domelement.h"

namespace parseagle {

Polygon::Polygon(const DomElement& root, QStringList* errors)
{
    mLayer = root.getAttributeAsInt("layer");
    mWidth = root.getAttributeAsDouble("width");
    if (root.hasAttribute("spacing")) {
        mSpacing = root.getAttributeAsDouble("spacing");
    }
    if (root.hasAttribute("pour")) {
        mPour = parsePolygonPour(root.getAttributeAsString("pour"), errors);
    }
    if (root.hasAttribute("isolate")) {
        mIsolate = root.getAttributeAsDouble("isolate");
    }
    if (root.hasAttribute("orphans")) {
        mOrphans = root.getAttributeAsBool("orphans");
    }
    if (root.hasAttribute("thermals")) {
        mThermals = root.getAttributeAsBool("thermals");
    }
    if (root.hasAttribute("rank")) {
        mRank = root.getAttributeAsInt("rank");
    }
    foreach (const DomElement& child, root.getChilds()) {
        mVertices.append(Vertex(child));
    }
}

Polygon::~Polygon() noexcept
{
}

} // namespace parseagle
