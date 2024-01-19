#ifndef PARSEAGLE_DEVICESET_H
#define PARSEAGLE_DEVICESET_H

#include <QtCore>
#include "gate.h"
#include "device.h"

namespace parseagle {

class DomElement;

class DeviceSet final
{
    public:

        // Constructors / Destructor
        DeviceSet() = delete;
        explicit DeviceSet(const DomElement& root, QStringList* errors = nullptr);
        ~DeviceSet() noexcept;

        // Getters
        QString getName() const noexcept {return mName;}
        QString getDescription() const noexcept {return mDescription;}
        QString getPrefix() const noexcept {return mPrefix;}
        bool getUserValue() const noexcept {return mUserValue;}
        const QList<Gate>& getGates() const noexcept {return mGates;}
        const QList<Device>& getDevices() const noexcept {return mDevices;}


    private:
        QString mName;
        QString mDescription;
        QString mPrefix;
        bool mUserValue = false;
        QList<Gate> mGates;
        QList<Device> mDevices;
};

} // namespace parseagle

#endif // PARSEAGLE_DEVICESET_H
