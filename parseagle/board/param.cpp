#include <QtCore>
#include "param.h"
#include "../common/domelement.h"

namespace parseagle {

Param::Param(const DomElement& root)
{
    mName = root.getAttributeAsString("name");
    mValue = root.getAttributeAsString("value");
}

Param::~Param() noexcept
{
}

bool Param::tryGetValueAsInt(int& value) const noexcept
{
    bool ok = false;
    value = mValue.toInt(&ok);
    return ok;
}

bool Param::tryGetValueAsDouble(double& value) const noexcept
{
    bool ok = false;
    value = mValue.toDouble(&ok);
    return ok;
}

bool Param::tryGetValueAsDoubleWithUnit(double& value, QString& unit) const noexcept
{
    int unitLength = 0;
    for (int i = mValue.count()-1; i >= 0; --i) {
      if (mValue.at(i).isLetter()) {
        ++unitLength;
      } else {
        break;
      }
    }

    bool ok = false;
    value = mValue.left(mValue.length() - unitLength).toDouble(&ok);
    unit = mValue.right(unitLength);
    return ok;
}

} // namespace parseagle
