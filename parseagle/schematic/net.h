#ifndef PARSEAGLE_NET_H
#define PARSEAGLE_NET_H

#include <QtCore>
#include "segment.h"

namespace parseagle {

class DomElement;

class Net final
{
    public:

        // Constructors / Destructor
        Net() = delete;
        explicit Net(const DomElement& root, QStringList* errors = nullptr);
        ~Net() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        int getClass() const noexcept {return mClass;}
        const QList<Segment>& getSegments() const noexcept {return mSegments;}


    private:
        QString mName;
        int mClass = 0;
        QList<Segment> mSegments;
};

} // namespace parseagle

#endif // PARSEAGLE_NET_H
