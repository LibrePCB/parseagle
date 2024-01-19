#ifndef PARSEAGLE_Sheet_H
#define PARSEAGLE_Sheet_H

#include <QtCore>
#include "../common/wire.h"
#include "../common/rectangle.h"
#include "../common/circle.h"
#include "../common/polygon.h"
#include "../common/text.h"
#include "../common/frame.h"
#include "../common/dimension.h"
#include "bus.h"
#include "instance.h"
#include "net.h"

namespace parseagle {

class DomElement;

class Sheet final
{
    public:

        // Constructors / Destructor
        Sheet() = delete;
        explicit Sheet(const DomElement& root, QStringList* errors = nullptr);
        ~Sheet() noexcept;

        // Getters
        const QString& getDescription() const noexcept {return mDescription;}
        const QList<Wire>& getWires() const noexcept {return mWires;}
        const QList<Rectangle>& getRectangles() const noexcept {return mRectangles;}
        const QList<Circle>& getCircles() const noexcept {return mCircles;}
        const QList<Polygon>& getPolygons() const noexcept {return mPolygons;}
        const QList<Text>& getTexts() const noexcept {return mTexts;}
        const QList<Frame>& getFrames() const noexcept {return mFrames;}
        const QList<Dimension>& getDimensions() const noexcept {return mDimensions;}
        const QList<Instance>& getInstances() const noexcept {return mInstances;}
        const QList<Bus>& getBuses() const noexcept {return mBuses;}
        const QList<Net>& getNets() const noexcept {return mNets;}


    private:
        QString mDescription;
        QList<Wire> mWires;
        QList<Rectangle> mRectangles;
        QList<Circle> mCircles;
        QList<Polygon> mPolygons;
        QList<Text> mTexts;
        QList<Frame> mFrames;
        QList<Dimension> mDimensions;
        QList<Instance> mInstances;
        QList<Bus> mBuses;
        QList<Net> mNets;
};

} // namespace parseagle

#endif // PARSEAGLE_SHEET_H
