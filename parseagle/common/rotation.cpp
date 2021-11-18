#include <QtCore>
#include "rotation.h"

namespace parseagle {

Rotation::Rotation(const QString& str)
{
    mSpin = str.contains("S");
    mMirror = str.contains("M");
    mAngle = QString(str).remove("M").remove("S").remove("R").toDouble();
}

Rotation::~Rotation() noexcept
{
}

} // namespace parseagle
