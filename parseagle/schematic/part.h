#ifndef PARSEAGLE_PART_H
#define PARSEAGLE_PART_H

#include <QtCore>
#include "../common/attribute.h"

namespace parseagle {

class DomElement;

class Part final
{
    public:

        // Constructors / Destructor
        Part() = delete;
        explicit Part(const DomElement& root, QStringList* errors = nullptr);
        ~Part() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        const QString& getLibrary() const noexcept {return mLibrary;}
        const QString& getLibraryUrn() const noexcept {return mLibraryUrn;}
        const QString& getDeviceSet() const noexcept {return mDeviceSet;}
        const QString& getDevice() const noexcept {return mDevice;}
        const QString& getTechnology() const noexcept {return mTechnology;}
        const QString& getValue() const noexcept {return mValue;}
        const QList<Attribute>& getAttributes() const noexcept {return mAttributes;}


    private:
        QString mName;
        QString mLibrary;
        QString mLibraryUrn;
        QString mDeviceSet;
        QString mDevice;
        QString mTechnology;
        QString mValue;
        QList<Attribute> mAttributes;
};

} // namespace parseagle

#endif // PARSEAGLE_PART_H
