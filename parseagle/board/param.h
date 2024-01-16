#ifndef PARSEAGLE_PARAM_H
#define PARSEAGLE_PARAM_H

#include <QtCore>

namespace parseagle {

class DomElement;

class Param final
{
    public:

        // Constructors / Destructor
        Param() = delete;
        explicit Param(const DomElement& root);
        ~Param() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        const QString& getValue() const noexcept {return mValue;}
        bool tryGetValueAsInt(int& value) const noexcept;
        bool tryGetValueAsDouble(double& value) const noexcept;
        bool tryGetValueAsDoubleWithUnit(double& value, QString& unit) const noexcept;


    private:
        QString mName;
        QString mValue;
};

} // namespace parseagle

#endif // PARSEAGLE_PARAM_H
