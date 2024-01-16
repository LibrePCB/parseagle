#ifndef PARSEAGLE_BOARD_H
#define PARSEAGLE_BOARD_H

#include <QtCore>
#include "../common/grid.h"
#include "../common/wire.h"
#include "../common/rectangle.h"
#include "../common/circle.h"
#include "../common/polygon.h"
#include "../common/text.h"
#include "../common/dimension.h"
#include "../package/hole.h"
#include "../library.h"
#include "designrules.h"
#include "element.h"
#include "signal.h"

namespace parseagle {

class Board final
{
    public:

        // Constructors / Destructor
        Board() = delete;
        explicit Board(const QString& filepath, QStringList* errors = nullptr);
        explicit Board(const QByteArray& content, QStringList* errors = nullptr);
        ~Board() noexcept;

        // Getters
        const Grid& getGrid() const noexcept {return mGrid;}
        const DesignRules& getDesignRules() const noexcept {return mDesignRules;}
        const QList<Library>& getLibraries() const noexcept {return mLibraries;}
        const QList<Wire>& getWires() const noexcept {return mWires;}
        const QList<Rectangle>& getRectangles() const noexcept {return mRectangles;}
        const QList<Circle>& getCircles() const noexcept {return mCircles;}
        const QList<Polygon>& getPolygons() const noexcept {return mPolygons;}
        const QList<Text>& getTexts() const noexcept {return mTexts;}
        const QList<Hole>& getHoles() const noexcept {return mHoles;}
        const QList<Dimension>& getDimensions() const noexcept {return mDimensions;}
        const QList<Element>& getElements() const noexcept {return mElements;}
        const QList<Signal>& getSignals() const noexcept {return mSignals;}


    private:
        void load(const QByteArray& content, QStringList* errors = nullptr);


        Grid mGrid;
        DesignRules mDesignRules;
        QList<Library> mLibraries;
        QList<Wire> mWires;
        QList<Rectangle> mRectangles;
        QList<Circle> mCircles;
        QList<Polygon> mPolygons;
        QList<Text> mTexts;
        QList<Hole> mHoles;
        QList<Dimension> mDimensions;
        QList<Element> mElements;
        QList<Signal> mSignals;
};

} // namespace parseagle

#endif // PARSEAGLE_BOARD_H
