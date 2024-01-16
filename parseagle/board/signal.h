#ifndef PARSEAGLE_SIGNAL_H
#define PARSEAGLE_SIGNAL_H

#include <QtCore>
#include "../common/wire.h"
#include "../common/polygon.h"
#include "contactref.h"
#include "via.h"

namespace parseagle {

class DomElement;

class Signal final
{
    public:

        // Constructors / Destructor
        Signal() = delete;
        explicit Signal(const DomElement& root, QStringList* errors = nullptr);
        ~Signal() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        int getClass() const noexcept {return mClass;}
        const QList<ContactRef>& getContactRefs() const noexcept {return mContactRefs;}
        const QList<Polygon>& getPolygons() const noexcept {return mPolygons;}
        const QList<Wire>& getWires() const noexcept {return mWires;}
        const QList<Via>& getVias() const noexcept {return mVias;}


    private:
        QString mName;
        int mClass = 0;
        QList<ContactRef> mContactRefs;
        QList<Polygon> mPolygons;
        QList<Wire> mWires;
        QList<Via> mVias;
};

} // namespace parseagle

#endif // PARSEAGLE_SIGNAL_H
