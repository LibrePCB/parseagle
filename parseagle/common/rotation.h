#ifndef PARSEAGLE_ROTATION_H
#define PARSEAGLE_ROTATION_H

#include <QtCore>

namespace parseagle {

class Rotation final
{
    public:

        // Constructors / Destructor
        Rotation() noexcept : mAngle(0.0) {}
        explicit Rotation(const QString& str);
        ~Rotation() noexcept;

        // Getters
        double getAngle() const noexcept {return mAngle;}


    private:
        double mAngle;
};

} // namespace parseagle

#endif // PARSEAGLE_ROTATION_H
