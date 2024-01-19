#ifndef PARSEAGLE_GRID_H
#define PARSEAGLE_GRID_H

#include <QtCore>
#include "enums.h"

namespace parseagle {

class DomElement;

class Grid final
{
    public:

        // Constructors / Destructor
        Grid() noexcept = default;
        explicit Grid(const DomElement& root, QStringList* errors = nullptr);
        ~Grid() noexcept;

        // Getters
        double getDistance() const noexcept {return mDistance;}
        GridUnit getUnitDistance() const noexcept {return mUnitDistance;}
        GridUnit getUnit() const noexcept {return mUnit;}
        GridStyle getStyle() const noexcept {return mStyle;}
        int getMultiple() const noexcept {return mMultiple;}
        bool getDisplay() const noexcept {return mDisplay;}
        double getAltDistance() const noexcept {return mAltDistance;}
        GridUnit getAltUnitDistance() const noexcept {return mAltUnitDistance;}
        GridUnit getAltUnit() const noexcept {return mAltUnit;}


    private:
        double mDistance = 0;
        GridUnit mUnitDistance = GridUnit::Unknown;
        GridUnit mUnit = GridUnit::Unknown;
        GridStyle mStyle = GridStyle::Lines;
        int mMultiple = 1;
        bool mDisplay = false;
        double mAltDistance = 0;
        GridUnit mAltUnitDistance = GridUnit::Unknown;
        GridUnit mAltUnit = GridUnit::Unknown;
};

} // namespace parseagle

#endif // PARSEAGLE_GRID_H
