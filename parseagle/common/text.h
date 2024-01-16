#ifndef PARSEAGLE_TEXT_H
#define PARSEAGLE_TEXT_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Text final
{
    public:

        // Types
        using Alignment = parseagle::Alignment;  // [DEPRECATED] Backwards compatibility

        // Constructors / Destructor
        Text() = delete;
        explicit Text(const DomElement& root, QStringList* errors = nullptr);
        ~Text() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        Font getFont() const noexcept {return mFont;}
        double getSize() const noexcept {return mSize;}
        int getRatio() const noexcept {return mRatio;}
        const Point& getPosition() const noexcept {return mPosition;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        Alignment getAlignment() const noexcept {return mAlignment;}
        QString getValue() const noexcept {return mValue;}


    private:
        int mLayer;
        Font mFont = Font::Proportional;
        double mSize;
        int mRatio = 8;
        Point mPosition;
        Rotation mRotation;
        Alignment mAlignment = Alignment::BottomLeft;
        QString mValue;
};

} // namespace parseagle

#endif // PARSEAGLE_TEXT_H
