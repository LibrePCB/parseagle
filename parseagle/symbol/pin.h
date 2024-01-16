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
        PinLength getLength() const noexcept {return mLength;}
        double getLengthInMillimeters() const noexcept;
        const Rotation& getRotation() const noexcept {return mRotation;}


    private:
        QString mName;
        Point mPosition;
        PinLength mLength = PinLength::Long;
        Rotation mRotation;
};

} // namespace parseagle

#endif // PARSEAGLE_PIN_H
