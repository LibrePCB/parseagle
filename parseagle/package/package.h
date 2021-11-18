#ifndef PARSEAGLE_PACKAGE_H
#define PARSEAGLE_PACKAGE_H

#include <QtCore>
#include "../common/wire.h"
#include "../common/rectangle.h"
#include "../common/circle.h"
#include "../common/polygon.h"
#include "../common/text.h"
#include "hole.h"
#include "thtpad.h"
#include "smtpad.h"

namespace parseagle {

class DomElement;

class Package final
{
    public:

        // Constructors / Destructor
        Package() = delete;
        explicit Package(const DomElement& root, QStringList* errors = nullptr);
        ~Package() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        QString getDescription() const noexcept {return mDescription;}
        const QList<Wire>& getWires() const noexcept {return mWires;}
        const QList<Rectangle>& getRectangles() const noexcept {return mRectangles;}
        const QList<Circle>& getCircles() const noexcept {return mCircles;}
        const QList<Polygon>& getPolygons() const noexcept {return mPolygons;}
        const QList<Text>& getTexts() const noexcept {return mTexts;}
        const QList<Hole>& getHoles() const noexcept {return mHoles;}
        const QList<ThtPad>& getThtPads() const noexcept {return mThtPads;}
        const QList<SmtPad>& getSmtPads() const noexcept {return mSmtPads;}


    private:
        QString mName;
        QString mDescription;
        QList<Wire> mWires;
        QList<Rectangle> mRectangles;
        QList<Circle> mCircles;
        QList<Polygon> mPolygons;
        QList<Text> mTexts;
        QList<Hole> mHoles;
        QList<ThtPad> mThtPads;
        QList<SmtPad> mSmtPads;
};

} // namespace parseagle

#endif // PARSEAGLE_PACKAGE_H
