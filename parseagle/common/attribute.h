#ifndef PARSEAGLE_ATTRIBUTE_H
#define PARSEAGLE_ATTRIBUTE_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Attribute final
{
    public:

        // Constructors / Destructor
        Attribute() = delete;
        explicit Attribute(const DomElement& root, QStringList* errors = nullptr);
        ~Attribute() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        QString getValue() const noexcept {return mValue;}
        const Point& getPosition() const noexcept {return mPosition;}
        double getSize() const noexcept {return mSize;}
        int getLayer() const noexcept {return mLayer;}
        Font getFont() const noexcept {return mFont;}
        int getRatio() const noexcept {return mRatio;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        AttributeDisplay getDisplay() const noexcept {return mDisplay;}
        bool getConstant() const noexcept {return mConstant;}
        Alignment getAlignment() const noexcept {return mAlignment;}


    private:
        QString mName;
        QString mValue;
        Point mPosition;
        double mSize = 0;
        int mLayer = 0;
        Font mFont = Font::Unknown;
        int mRatio = 0;
        Rotation mRotation;
        AttributeDisplay mDisplay = AttributeDisplay::Value;
        bool mConstant = false;
        Alignment mAlignment = Alignment::BottomLeft;
};

} // namespace parseagle

#endif // PARSEAGLE_ATTRIBUTE_H
