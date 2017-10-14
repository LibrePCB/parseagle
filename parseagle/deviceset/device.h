#ifndef PARSEAGLE_DEVICE_H
#define PARSEAGLE_DEVICE_H

#include <QtCore>
#include "connection.h"

namespace parseagle {

class DomElement;

class Device final
{
    public:

        // Constructors / Destructor
        Device() = delete;
        explicit Device(const DomElement& root);
        ~Device() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        QString getPackage() const noexcept {return mPackage;}
        const QList<Connection>& getConnections() const noexcept {return mConnections;}


    private:
        QString mName;
        QString mPackage;
        QList<Connection> mConnections;
};

} // namespace parseagle

#endif // PARSEAGLE_DEVICE_H
