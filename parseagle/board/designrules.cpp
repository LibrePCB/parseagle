#include <QtCore>
#include "designrules.h"
#include "../common/domelement.h"

namespace parseagle {

DesignRules::DesignRules(const DomElement& root, QStringList* errors)
{
    // Note: Although the EAGLE DTD files specify the "name" attribute as
    // required, there seem to be EAGLE boards without this attribute and
    // EAGLE opens them anyway. So we have to support this case too.
    if (root.hasAttribute("name")) {
        mName = root.getAttributeAsString("name");
    }
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "description") {
            mDescription = child.getText();
        } else if (child.getTagName() == "param") {
            mParams.append(Param(child));
        } else if (errors) {
            errors->append("Unknown design rules child: " + child.getTagName());
        }
    }
}

DesignRules::~DesignRules() noexcept
{
}

const Param* DesignRules::tryGetParam(const QString& name) const noexcept
{
    foreach (const Param& param, mParams) {
        if (param.getName() == name) {
            return &param;
        }
    }
    return nullptr;
}

} // namespace parseagle
