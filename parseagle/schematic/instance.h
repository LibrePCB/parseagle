#ifndef PARSEAGLE_INSTANCE_H
#define PARSEAGLE_INSTANCE_H

#include <QtCore>
#include "../common/attribute.h"
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Instance final
{
    public:

        // Constructors / Destructor
        Instance() = delete;
        explicit Instance(const DomElement& root, QStringList* errors = nullptr);
        ~Instance() noexcept;

        // Getters
        const QString& getPart() const noexcept {return mPart;}
        const QString& getGate() const noexcept {return mGate;}
        const Point& getPosition() const noexcept {return mPosition;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        bool getSmashed() const noexcept {return mSmashed;}
        const QList<Attribute>& getAttributes() const noexcept {return mAttributes;}


    private:
        QString mPart;
        QString mGate;
        Point mPosition;
        Rotation mRotation;
        bool mSmashed = false;
        QList<Attribute> mAttributes;
};

} // namespace parseagle

#endif // PARSEAGLE_INSTANCE_H
