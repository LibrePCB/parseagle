#ifndef PARSEAGLE_CONNECTION_H
#define PARSEAGLE_CONNECTION_H

#include <QtCore>

namespace parseagle {

class DomElement;

class Connection final
{
    public:

        // Constructors / Destructor
        Connection() = delete;
        explicit Connection(const DomElement& root);
        ~Connection() noexcept;

        // Getters
        QString getGate() const noexcept {return mGate;}
        QString getPin() const noexcept {return mPin;}
        QString getPad() const noexcept {return mPad;}


    private:
        QString mGate;
        QString mPin;
        QString mPad;
};

} // namespace parseagle

#endif // PARSEAGLE_CONNECTION_H
