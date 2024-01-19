#ifndef PARSEAGLE_PIN_H
#define PARSEAGLE_PIN_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Pin final
{
    public:

        // Types
        using Length = parseagle::PinLength;  // [DEPRECATED] Backwards compatibility

        // Constructors / Destructor
        Pin() = delete;
        explicit Pin(const DomElement& root, QStringList* errors = nullptr);
        ~Pin() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        const Point& getPosition() const noexcept {return mPosition;}
        PinVisibility getVisibility() const noexcept {return mVisibility;}
        PinLength getLength() const noexcept {return mLength;}
        double getLengthInMillimeters() const noexcept;
        PinDirection getDirection() const noexcept {return mDirection;}
        PinFunction getFunction() const noexcept {return mFunction;}
        int getSwapLevel() const noexcept {return mSwapLevel;}
        const Rotation& getRotation() const noexcept {return mRotation;}


    private:
        QString mName;
        Point mPosition;
        PinVisibility mVisibility = PinVisibility::Both;
        PinLength mLength = PinLength::Long;
        PinDirection mDirection = PinDirection::IO;
        PinFunction mFunction = PinFunction::None;
        int mSwapLevel = 0;
        Rotation mRotation;
};

} // namespace parseagle

#endif // PARSEAGLE_PIN_H
