#include <QtCore>
#include "bus.h"
#include "../common/domelement.h"

namespace parseagle {

Bus::Bus(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "segment") {
            mSegments.append(Segment(child, errors));
        } else if (errors) {
            errors->append("Unknown bus child: " + child.getTagName());
        }
    }
}

Bus::~Bus() noexcept
{
}

} // namespace parseagle
