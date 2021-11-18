#ifndef PARSEAGLE_SYMBOL_H
#define PARSEAGLE_SYMBOL_H

#include <QtCore>
#include "../common/wire.h"
#include "../common/rectangle.h"
#include "../common/circle.h"
#include "../common/polygon.h"
#include "../common/text.h"
#include "pin.h"

namespace parseagle {

class DomElement;

class Symbol final
{
    public:

        // Constructors / Destructor
        Symbol() = delete;
        explicit Symbol(const DomElement& root, QStringList* errors = nullptr);
        ~Symbol() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        QString getDescription() const noexcept {return mDescription;}
        const QList<Wire>& getWires() const noexcept {return mWires;}
        const QList<Rectangle>& getRectangles() const noexcept {return mRectangles;}
        const QList<Circle>& getCircles() const noexcept {return mCircles;}
        const QList<Polygon>& getPolygons() const noexcept {return mPolygons;}
        const QList<Text>& getTexts() const noexcept {return mTexts;}
        const QList<Pin>& getPins() const noexcept {return mPins;}


    private:
        QString mName;
        QString mDescription;
        QList<Wire> mWires;
        QList<Rectangle> mRectangles;
        QList<Circle> mCircles;
        QList<Polygon> mPolygons;
        QList<Text> mTexts;
        QList<Pin> mPins;
};

} // namespace parseagle

#endif // PARSEAGLE_SYMBOL_H
