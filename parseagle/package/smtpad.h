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
        int getRoundness() const noexcept {return mRoundness;}
        bool getStop() const noexcept {return mStop;}
        bool getCream() const noexcept {return mCream;}


    private:
        QString mName;
        int mLayer;
        Point mPosition;
        Rotation mRotation;
        double mWidth;
        double mHeight;
        int mRoundness = 0;
        bool mStop = true;
        bool mCream = true;
};

} // namespace parseagle

#endif // PARSEAGLE_SMTPAD_H
