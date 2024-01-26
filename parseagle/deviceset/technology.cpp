#include <QtCore>
#include "technology.h"
#include "../common/domelement.h"

namespace parseagle {

Technology::Technology(const DomElement& root, QStringList* errors)
{
    mName = root.getAttributeAsString("name");
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "attribute") {
            mAttributes.append(Attribute(child, errors));
        } else if (errors) {
            errors->append("Unknown technology child: " + child.getTagName());
        }
    }
}

Technology::~Technology() noexcept
{
}

} // namespace parseagle
