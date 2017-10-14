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

        // Constructors / Destructor
        Text() = delete;
        explicit Text(const DomElement& root);
        ~Text() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        double getSize() const noexcept {return mSize;}
        const Point& getPosition() const noexcept {return mPosition;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        QString getValue() const noexcept {return mValue;}


    private:
        int mLayer;
        double mSize;
        Point mPosition;
        Rotation mRotation;
        QString mValue;
};

} // namespace parseagle

#endif // PARSEAGLE_TEXT_H
