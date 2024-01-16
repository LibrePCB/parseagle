#ifndef PARSEAGLE_PINREF_H
#define PARSEAGLE_PINREF_H

#include <QtCore>

namespace parseagle {

class DomElement;

class PinRef final
{
    public:

        // Constructors / Destructor
        PinRef() = delete;
        explicit PinRef(const DomElement& root);
        ~PinRef() noexcept;

        // Getters
        const QString& getPart() const noexcept {return mPart;}
        const QString& getGate() const noexcept {return mGate;}
        const QString& getPin() const noexcept {return mPin;}


    private:
        QString mPart;
        QString mGate;
        QString mPin;
};

} // namespace parseagle

#endif // PARSEAGLE_PINREF_H
