#ifndef PARSEAGLE_BUS_H
#define PARSEAGLE_BUS_H

#include <QtCore>

namespace parseagle {

class DomElement;

class Bus final
{
    public:

        // Constructors / Destructor
        Bus() = delete;
        explicit Bus(const DomElement& root);
        ~Bus() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}


    private:
        QString mName;
};

} // namespace parseagle

#endif // PARSEAGLE_BUS_H
