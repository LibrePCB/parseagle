#ifndef PARSEAGLE_GATE_H
#define PARSEAGLE_GATE_H

#include <QtCore>
#include "../common/enums.h"
#include "../common/point.h"

namespace parseagle {

class DomElement;

class Gate final
{
    public:

        // Types
        using AddLevel = parseagle::GateAddLevel;  // [DEPRECATED] Backwards compatibility

        // Constructors / Destructor
        Gate() = delete;
        explicit Gate(const DomElement& root, QStringList* errors = nullptr);
        ~Gate() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        QString getSymbol() const noexcept {return mSymbol;}
        const Point& getPosition() const noexcept {return mPosition;}
        GateAddLevel getAddLevel() const noexcept {return mAddLevel;}


    private:
        QString mName;
        QString mSymbol;
        Point mPosition;
        GateAddLevel mAddLevel = GateAddLevel::Next;
};

} // namespace parseagle

#endif // PARSEAGLE_GATE_H
