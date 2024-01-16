#ifndef PARSEAGLE_CONTACTREF_H
#define PARSEAGLE_CONTACTREF_H

#include <QtCore>

namespace parseagle {

class DomElement;

class ContactRef final
{
    public:

        // Constructors / Destructor
        ContactRef() = delete;
        explicit ContactRef(const DomElement& root);
        ~ContactRef() noexcept;

        // Getters
        const QString& getElement() const noexcept {return mElement;}
        const QString& getPad() const noexcept {return mPad;}


    private:
        QString mElement;
        QString mPad;
};

} // namespace parseagle

#endif // PARSEAGLE_CONTACTREF_H
