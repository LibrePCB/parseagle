#ifndef PARSEAGLE_TEXT_H
#define PARSEAGLE_TEXT_H

#include <QtCore>
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Text final
{
    public:

        // Types
        enum class Alignment {
            Unknown,  // Failed to parse XML attribute.
            BottomLeft,
            BottomCenter,
            BottomRight,
            CenterLeft,
            Center,
            CenterRight,
            TopLeft,
            TopCenter,
            TopRight,
        };

        // Constructors / Destructor
        Text() = delete;
        explicit Text(const DomElement& root, QStringList* errors = nullptr);
        ~Text() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        double getSize() const noexcept {return mSize;}
        const Point& getPosition() const noexcept {return mPosition;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        Alignment getAlignment() const noexcept {return mAlignment;}
        QString getValue() const noexcept {return mValue;}


    private:
        int mLayer;
        double mSize;
        Point mPosition;
        Rotation mRotation;
        Alignment mAlignment;
        QString mValue;
};

} // namespace parseagle

#endif // PARSEAGLE_TEXT_H
