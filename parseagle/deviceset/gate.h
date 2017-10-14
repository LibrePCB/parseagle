#ifndef PARSEAGLE_GATE_H
#define PARSEAGLE_GATE_H

#include <QtCore>
#include "../common/point.h"

namespace parseagle {

class DomElement;

class Gate final
{
    public:

        // Types
        enum class AddLevel {
            Must,
            Can,
            Next,
            Request,
            Always,
        };

        // Constructors / Destructor
        Gate() = delete;
        explicit Gate(const DomElement& root);
        ~Gate() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        QString getSymbol() const noexcept {return mSymbol;}
        const Point& getPosition() const noexcept {return mPosition;}
        AddLevel getAddLevel() const noexcept {return mAddLevel;}


    private:
        QString mName;
        QString mSymbol;
        Point mPosition;
        AddLevel mAddLevel;
};

} // namespace parseagle

#endif // PARSEAGLE_GATE_H
