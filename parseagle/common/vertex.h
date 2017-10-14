#ifndef PARSEAGLE_VERTEX_H
#define PARSEAGLE_VERTEX_H

#include <QtCore>
#include "point.h"

namespace parseagle {

class DomElement;

class Vertex final
{
    public:

        // Constructors / Destructor
        Vertex() = delete;
        explicit Vertex(const DomElement& root);
        ~Vertex() noexcept;

        // Getters
        const Point& getPosition() const noexcept {return mPosition;}
        double getCurve() const noexcept {return mCurve;}


    private:
        Point mPosition;
        double mCurve;
};

} // namespace parseagle

#endif // PARSEAGLE_VERTEX_H
