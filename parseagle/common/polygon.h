#ifndef PARSEAGLE_POLYGON_H
#define PARSEAGLE_POLYGON_H

#include <QtCore>
#include "vertex.h"

namespace parseagle {

class DomElement;

class Polygon final
{
    public:

        // Constructors / Destructor
        Polygon() = delete;
        explicit Polygon(const DomElement& root);
        ~Polygon() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        double getWidth() const noexcept {return mWidth;}
        const QList<Vertex>& getVertices() const noexcept {return mVertices;}


    private:
        int mLayer;
        double mWidth;
        QList<Vertex> mVertices;
};

} // namespace parseagle

#endif // PARSEAGLE_POLYGON_H
