#ifndef PARSEAGLE_LABEL_H
#define PARSEAGLE_LABEL_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Label final
{
    public:

        // Constructors / Destructor
        Label() = delete;
        explicit Label(const DomElement& root, QStringList* errors = nullptr);
        ~Label() noexcept;

        // Getters
        const Point& getPosition() const noexcept {return mPosition;}
        double getSize() const noexcept {return mSize;}
        int getLayer() const noexcept {return mLayer;}
        int getRatio() const noexcept {return mRatio;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        Alignment getAlignment() const noexcept {return mAlignment;}
        bool getXref() const noexcept {return mXref;}


    private:
        Point mPosition;
        double mSize;
        int mLayer;
        int mRatio = 8;
        Rotation mRotation;
        Alignment mAlignment = Alignment::BottomLeft;
        bool mXref = false;
};

} // namespace parseagle

#endif // PARSEAGLE_LABEL_H
