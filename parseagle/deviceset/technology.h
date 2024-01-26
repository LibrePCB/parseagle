#ifndef PARSEAGLE_TECHNOLOGY_H
#define PARSEAGLE_TECHNOLOGY_H

#include <QtCore>
#include "../common/attribute.h"

namespace parseagle {

class DomElement;

class Technology final
{
    public:

        // Constructors / Destructor
        Technology() = delete;
        explicit Technology(const DomElement& root, QStringList* errors = nullptr);
        ~Technology() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        const QList<Attribute>& getAttributes() const noexcept {return mAttributes;}


    private:
        QString mName;
        QList<Attribute> mAttributes;
};

} // namespace parseagle

#endif // PARSEAGLE_TECHNOLOGY_H
