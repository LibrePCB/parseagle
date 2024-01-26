#ifndef PARSEAGLE_WIRE_H
#define PARSEAGLE_WIRE_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"

namespace parseagle {

class DomElement;

class Wire final
{
    public:

        // Constructors / Destructor
        Wire() = delete;
        explicit Wire(const DomElement& root, QStringList* errors = nullptr);
        ~Wire() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        double getWidth() const noexcept {return mWidth;}
        const Point& getP1() const noexcept {return mP1;}
        const Point& getP2() const noexcept {return mP2;}
        WireStyle getWireStyle() const noexcept {return mWireStyle;}
        double getCurve() const noexcept {return mCurve;}
        WireCap getWireCap() const noexcept {return mWireCap;}


    private:
        int mLayer;
        double mWidth;
        Point mP1;
        Point mP2;
        WireStyle mWireStyle = WireStyle::Continuous;
        double mCurve = 0;
        WireCap mWireCap = WireCap::Round;
};

} // namespace parseagle

#endif // PARSEAGLE_WIRE_H
