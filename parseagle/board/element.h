#ifndef PARSEAGLE_ELEMENT_H
#define PARSEAGLE_ELEMENT_H

#include <QtCore>
#include "../common/attribute.h"
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Element final
{
    public:

        // Constructors / Destructor
        Element() = delete;
        explicit Element(const DomElement& root, QStringList* errors = nullptr);
        ~Element() noexcept;

        // Getters
        const QString& getName() const noexcept {return mName;}
        const QString& getLibrary() const noexcept {return mLibrary;}
        const QString& getLibraryUrn() const noexcept {return mLibraryUrn;}
        const QString& getPackage() const noexcept {return mPackage;}
        const QString& getValue() const noexcept {return mValue;}
        const Point& getPosition() const noexcept {return mPosition;}
        const Rotation& getRotation() const noexcept {return mRotation;}
        bool getLocked() const noexcept {return mLocked;}
        bool getPopulate() const noexcept {return mPopulate;}
        bool getSmashed() const noexcept {return mSmashed;}
        const QList<Attribute>& getAttributes() const noexcept {return mAttributes;}


    private:
        QString mName;
        QString mLibrary;
        QString mLibraryUrn;
        QString mPackage;
        QString mValue;
        Point mPosition;
        Rotation mRotation;
        bool mLocked = false;
        bool mPopulate = true;
        bool mSmashed = false;
        QList<Attribute> mAttributes;
};

} // namespace parseagle

#endif // PARSEAGLE_ELEMENT_H
