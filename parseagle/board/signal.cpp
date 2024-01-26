#include <QtCore>
#include "signal.h"
#include "../common/domelement.h"

namespace parseagle {

Signal::Signal(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    if (root.hasAttribute("class")) {
        mClass = root.getAttributeAsInt("class");
    }
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "contactref") {
            mContactRefs.append(ContactRef(child));
        } else if (child.getTagName() == "polygon") {
            mPolygons.append(Polygon(child, errors));
        } else if (child.getTagName() == "wire") {
            mWires.append(Wire(child, errors));
        } else if (child.getTagName() == "via") {
            mVias.append(Via(child));
        } else if (errors) {
            errors->append("Unknown signal child: " + child.getTagName());
        }
    }
}

Signal::~Signal() noexcept
{
}

} // namespace parseagle
