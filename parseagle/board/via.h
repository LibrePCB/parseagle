#ifndef PARSEAGLE_VIA_H
#define PARSEAGLE_VIA_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"

namespace parseagle {

class DomElement;

class Via final
{
    public:

        // Constructors / Destructor
        Via() = delete;
        explicit Via(const DomElement& root, QStringList* errors = nullptr);
        ~Via() noexcept;

        // Getters
        const Point& getPosition() const noexcept {return mPosition;}
        const QString& getExtent() const noexcept {return mExtent;}
        bool tryGetStartLayer(int& layer) const noexcept;
        bool tryGetEndLayer(int& layer) const noexcept;
        double getDrill() const noexcept {return mDrill;}
        double getDiameter() const noexcept {return mDiameter;}
        ViaShape getShape() const noexcept {return mShape;}
        bool getAlwaysStop() const noexcept {return mAlwaysStop;}


    private:
        Point mPosition;
        QString mExtent;
        double mDrill;
        double mDiameter = 0;
        ViaShape mShape = ViaShape::Round;
        bool mAlwaysStop = false;
};

} // namespace parseagle

#endif // PARSEAGLE_VIA_H
