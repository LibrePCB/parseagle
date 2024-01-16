#ifndef PARSEAGLE_POLYGON_H
#define PARSEAGLE_POLYGON_H

#include <QtCore>
#include "enums.h"
#include "vertex.h"

namespace parseagle {

class DomElement;

class Polygon final
{
    public:

        // Constructors / Destructor
        Polygon() = delete;
        explicit Polygon(const DomElement& root, QStringList* errors = nullptr);
        ~Polygon() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        double getWidth() const noexcept {return mWidth;}
        double getSpacing() const noexcept {return mSpacing;}
        PolygonPour getPour() const noexcept {return mPour;}
        double getIsolate() const noexcept {return mIsolate;}
        bool getOrphans() const noexcept {return mOrphans;}
        bool getThermals() const noexcept {return mThermals;}
        int getRank() const noexcept {return mRank;}
        const QList<Vertex>& getVertices() const noexcept {return mVertices;}


    private:
        int mLayer;
        double mWidth;
        double mSpacing = 0;
        PolygonPour mPour = PolygonPour::Solid;
        double mIsolate = 0;
        bool mOrphans = false;
        bool mThermals = true;
        int mRank = 0;
        QList<Vertex> mVertices;
};

} // namespace parseagle

#endif // PARSEAGLE_POLYGON_H
