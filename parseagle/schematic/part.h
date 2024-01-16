#ifndef PARSEAGLE_PART_H
#define PARSEAGLE_PART_H

#include <QtCore>

namespace parseagle {

class DomElement;

class Part final
{
    public:

        // Constructors / Destructor
        Part() = delete;
        explicit Part(const DomElement& root);
        ~Part() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        const QString& getLibrary() const noexcept {return mLibrary;}
        const QString& getLibraryUrn() const noexcept {return mLibraryUrn;}
        const QString& getDeviceSet() const noexcept {return mDeviceSet;}
        const QString& getDevice() const noexcept {return mDevice;}
        const QString& getTechnology() const noexcept {return mTechnology;}
        const QString& getValue() const noexcept {return mValue;}


    private:
        QString mName;
        QString mLibrary;
        QString mLibraryUrn;
        QString mDeviceSet;
        QString mDevice;
        QString mTechnology;
        QString mValue;
};

} // namespace parseagle

#endif // PARSEAGLE_PART_H
