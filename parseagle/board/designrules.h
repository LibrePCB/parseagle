#ifndef PARSEAGLE_DESIGNRULES_H
#define PARSEAGLE_DESIGNRULES_H

#include <QtCore>
#include "param.h"

namespace parseagle {

class DomElement;

class DesignRules final
{
    public:

        // Constructors / Destructor
        DesignRules() = default;
        explicit DesignRules(const DomElement& root, QStringList* errors = nullptr);
        ~DesignRules() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        const QString& getDescription() const noexcept {return mDescription;}
        const QList<Param>& getParams() const noexcept {return mParams;}
        const Param* tryGetParam(const QString& name) const noexcept;


    private:
        QString mName;
        QString mDescription;
        QList<Param> mParams;
};

} // namespace parseagle

#endif // PARSEAGLE_DESIGNRULES_H
