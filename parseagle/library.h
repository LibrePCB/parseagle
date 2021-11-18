#ifndef PARSEAGLE_LIBRARY_H
#define PARSEAGLE_LIBRARY_H

#include <QtCore>
#include "symbol/symbol.h"
#include "package/package.h"
#include "deviceset/deviceset.h"

namespace parseagle {

class Library final
{
    public:

        // Constructors / Destructor
        Library() = delete;
        explicit Library(const QString& filepath, QStringList* errors = nullptr);
        explicit Library(const QByteArray& content, QStringList* errors = nullptr);
        ~Library() noexcept;

        // Getters
        QString getDescription() const noexcept {return mDescription;}
        const QList<Symbol>& getSymbols() const noexcept {return mSymbols;}
        const QList<Package>& getPackages() const noexcept {return mPackages;}
        const QList<DeviceSet>& getDeviceSets() const noexcept {return mDeviceSets;}


    private:
        void load(const QByteArray& content, QStringList* errors = nullptr);


        QString mDescription;
        QList<Symbol> mSymbols;
        QList<Package> mPackages;
        QList<DeviceSet> mDeviceSets;
};

} // namespace parseagle

#endif // PARSEAGLE_LIBRARY_H
