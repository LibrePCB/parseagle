#ifndef PARSEAGLE_MODULE_H
#define PARSEAGLE_MODULE_H

#include <QtCore>

namespace parseagle {

class DomElement;

class Module final
{
    public:

        // Constructors / Destructor
        Module() = delete;
        explicit Module(const DomElement& root);
        ~Module() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}


    private:
        QString mName;
        // Other attributes not implemented yet.
};

} // namespace parseagle

#endif // PARSEAGLE_MODULE_H
