#ifndef PARSEAGLE_BUS_H
#define PARSEAGLE_BUS_H

#include <QtCore>
#include "segment.h"

namespace parseagle {

class DomElement;

class Bus final
{
    public:

        // Constructors / Destructor
        Bus() = delete;
        explicit Bus(const DomElement& root, QStringList* errors = nullptr);
        ~Bus() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        const QList<Segment>& getSegments() const noexcept {return mSegments;}


    private:
        QString mName;
        QList<Segment> mSegments;
};

} // namespace parseagle

#endif // PARSEAGLE_BUS_H
