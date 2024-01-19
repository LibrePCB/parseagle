#include <QtCore>
#include "net.h"
#include "../common/domelement.h"

namespace parseagle {

Net::Net(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    if (root.hasAttribute("class")) {
        mClass = root.getAttributeAsInt("class");
    }
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "segment") {
            mSegments.append(Segment(child, errors));
        } else  if (errors) {
            errors->append("Unknown net child: " + child.getTagName());
      }
    }
}

Net::~Net() noexcept
{
}

} // namespace parseagle
