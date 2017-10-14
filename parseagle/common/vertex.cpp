#include <QtCore>
#include "vertex.h"
#include "domelement.h"

namespace parseagle {

Vertex::Vertex(const DomElement& root)
{
    mPosition.x = root.getAttributeAsDouble("x");
    mPosition.y = root.getAttributeAsDouble("y");

    if (root.hasAttribute("curve")) {
        mCurve = root.getAttributeAsDouble("curve");
    } else {
        mCurve = 0.0;
    }
}

Vertex::~Vertex() noexcept
{
}

} // namespace parseagle
