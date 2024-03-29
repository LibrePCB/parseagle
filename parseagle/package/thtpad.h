#ifndef PARSEAGLE_THTPAD_H
#define PARSEAGLE_THTPAD_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class ThtPad final
{
    public:

        // Types
        using Shape = parseagle::PadShape;  // [DEPRECATED] Backwards compatibility

        // Constructors / Destructor
        ThtPad() = delete;
        explicit ThtPad(const DomElement& root, QStringList* errors = nullptr);
        ~ThtPad() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        const Point& getPosition() const noexcept {return mPosition;}
        double getDrillDiameter() const noexcept {return mDrillDiameter;}
        double getOuterDiameter() const noexcept {return mOuterDiameter;}
        PadShape getShape() const noexcept {return mShape;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        bool getStop() const noexcept {return mStop;}


    private:
        QString mName;
        Point mPosition;
        double mDrillDiameter;
        double mOuterDiameter = 0;
        PadShape mShape = PadShape::Round;
        Rotation mRotation;
        bool mStop = true;
};

} // namespace parseagle

#endif // PARSEAGLE_THTPAD_H
