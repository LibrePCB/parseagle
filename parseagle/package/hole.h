#ifndef PARSEAGLE_HOLE_H
#define PARSEAGLE_HOLE_H

#include <QtCore>
#include "../common/point.h"

namespace parseagle {

class DomElement;

class Hole final
{
    public:

        // Constructors / Destructor
        Hole() = delete;
        explicit Hole(const DomElement& root);
        ~Hole() noexcept;

        // Getters
        const Point& getPosition() const noexcept {return mPosition;}
        double getDiameter() const noexcept {return mDiameter;}


    private:
        Point mPosition;
        double mDiameter;
};

} // namespace parseagle

#endif // PARSEAGLE_HOLE_H
