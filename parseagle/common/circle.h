#ifndef PARSEAGLE_CIRCLE_H
#define PARSEAGLE_CIRCLE_H

#include <QtCore>
#include "../common/point.h"

namespace parseagle {

class DomElement;

class Circle final
{
    public:

        // Constructors / Destructor
        Circle() = delete;
        explicit Circle(const DomElement& root);
        ~Circle() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        double getWidth() const noexcept {return mWidth;}
        double getRadius() const noexcept {return mRadius;}
        const Point& getPosition() const noexcept {return mPosition;}


    private:
        int mLayer;
        double mWidth;
        double mRadius;
        Point mPosition;
};

} // namespace parseagle

#endif // PARSEAGLE_CIRCLE_H
