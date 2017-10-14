#ifndef PARSEAGLE_SMTPAD_H
#define PARSEAGLE_SMTPAD_H

#include <QtCore>
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class SmtPad final
{
    public:

        // Constructors / Destructor
        SmtPad() = delete;
        explicit SmtPad(const DomElement& root);
        ~SmtPad() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        int getLayer() const noexcept {return mLayer;}
        const Point& getPosition() const noexcept {return mPosition;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        double getWidth() const noexcept {return mWidth;}
        double getHeight() const noexcept {return mHeight;}


    private:
        QString mName;
        int mLayer;
        Point mPosition;
        Rotation mRotation;
        double mWidth;
        double mHeight;
};

} // namespace parseagle

#endif // PARSEAGLE_SMTPAD_H
