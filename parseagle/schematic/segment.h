#ifndef PARSEAGLE_SEGMENT_H
#define PARSEAGLE_SEGMENT_H

#include <QtCore>
#include "../common/point.h"
#include "../common/wire.h"
#include "pinref.h"
#include "label.h"

namespace parseagle {

class DomElement;

class Segment final
{
    public:

        // Constructors / Destructor
        Segment() = delete;
        explicit Segment(const DomElement& root, QStringList* errors = nullptr);
        ~Segment() noexcept;

        // Getters
        const QList<PinRef>& getPinRefs() const noexcept {return mPinRefs;}
        const QList<Wire>& getWires() const noexcept {return mWires;}
        const QList<Point>& getJunctions() const noexcept {return mJunctions;}
        const QList<Label>& getLabels() const noexcept {return mLabels;}


    private:
        QList<PinRef> mPinRefs;
        QList<Wire> mWires;
        QList<Point> mJunctions;
        QList<Label> mLabels;
};

} // namespace parseagle

#endif // PARSEAGLE_SEGMENT_H
