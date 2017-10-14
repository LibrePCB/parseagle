#ifndef PARSEAGLE_RECTANGLE_H
#define PARSEAGLE_RECTANGLE_H

#include <QtCore>
#include "../common/point.h"

namespace parseagle {

class DomElement;

class Rectangle final
{
    public:

        // Constructors / Destructor
        Rectangle() = delete;
        explicit Rectangle(const DomElement& root);
        ~Rectangle() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        const Point& getP1() const noexcept {return mP1;}
        const Point& getP2() const noexcept {return mP2;}


    private:
        int mLayer;
        Point mP1;
        Point mP2;
};

} // namespace parseagle

#endif // PARSEAGLE_RECTANGLE_H
