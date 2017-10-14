#include <QtCore>
#include "rotation.h"

namespace parseagle {

Rotation::Rotation(const QString& str)
{
    if (!str.startsWith("R")) {
        throw std::runtime_error("Invalid rotation: " + str.toStdString());
    }

    bool ok = false;
    mAngle = str.mid(1, -1).toDouble(&ok);
    if (!ok) {
        throw std::runtime_error("Invalid rotation: " + str.toStdString());
    }
}

Rotation::~Rotation() noexcept
{
}

} // namespace parseagle
