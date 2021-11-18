#ifndef PARSEAGLE_ROTATION_H
#define PARSEAGLE_ROTATION_H

#include <QtCore>

namespace parseagle {

class Rotation final
{
    public:

        // Constructors / Destructor
        Rotation() noexcept : mSpin(false), mMirror(false), mAngle(0.0) {}
        explicit Rotation(const QString& str);
        ~Rotation() noexcept;

        // Getters
        bool getSpin() const noexcept {return mSpin;}
        bool getMirror() const noexcept {return mMirror;}
        double getAngle() const noexcept {return mAngle;}


    private:
        bool mSpin;
        bool mMirror;
        double mAngle;
};

} // namespace parseagle

#endif // PARSEAGLE_ROTATION_H
