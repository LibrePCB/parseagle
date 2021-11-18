#ifndef PARSEAGLE_PIN_H
#define PARSEAGLE_PIN_H

#include <QtCore>
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Pin final
{
    public:

        // Types
        enum class Length {
            Unknown,  // Failed to parse XML attribute.
            Point,
            Short,
            Middle,
            Long,
        };

        // Constructors / Destructor
        Pin() = delete;
        explicit Pin(const DomElement& root, QStringList* errors = nullptr);
        ~Pin() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        const Point& getPosition() const noexcept {return mPosition;}
        Length getLength() const noexcept {return mLength;}
        double getLengthInMillimeters() const noexcept;
        const Rotation& getRotation() const noexcept {return mRotation;}


    private:
        QString mName;
        Point mPosition;
        Length mLength;
        Rotation mRotation;
};

} // namespace parseagle

#endif // PARSEAGLE_PIN_H
