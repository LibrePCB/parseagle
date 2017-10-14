#ifndef PARSEAGLE_DOMELEMENT_H
#define PARSEAGLE_DOMELEMENT_H

#include <memory>
#include <QtCore>
#include <QtXml/QtXml>

namespace parseagle {

class DomElement final
{
    public:

        // Constructors / Destructor
        DomElement() = delete;
        explicit DomElement(const QDomElement& root);
        ~DomElement() noexcept;

        // Getters
        const QString& getTagName() const noexcept {return mName;}
        const QString& getText() const noexcept {return mText;}
        bool hasAttribute(const QString& name) const noexcept {return mAttributes.contains(name);}
        QString getAttributeAsString(const QString& name) const;
        int getAttributeAsInt(const QString& name) const;
        double getAttributeAsDouble(const QString& name) const;
        bool hasChild(const QString& tagName = QString()) const noexcept;
        const QList<DomElement>& getChilds() const noexcept {return mChilds;}
        DomElement getFirstChild(const QString& tagName = QString()) const;


    private:
        QString mName;
        QString mText;
        QHash<QString, QString> mAttributes;
        QList<DomElement> mChilds;
};

} // namespace parseagle

#endif // PARSEAGLE_DOMELEMENT_H
