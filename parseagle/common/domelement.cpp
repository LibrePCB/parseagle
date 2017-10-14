#include <QtCore>
#include "domelement.h"

namespace parseagle {

DomElement::DomElement(const QDomElement& root)
{
    if (root.isNull()) {
        throw std::runtime_error("Invalid XML node!");
    }

    mName = root.tagName();
    mText = root.text();

    QDomNamedNodeMap map = root.attributes();
    for (int i = 0; i < map.count(); i++) {
        mAttributes.insert(map.item(i).nodeName(), map.item(i).nodeValue());
    }

    for (QDomElement c = root.firstChildElement(); !c.isNull(); c = c.nextSiblingElement()) {
        mChilds.append(DomElement(c));
    }
}

DomElement::~DomElement() noexcept
{
}

QString DomElement::getAttributeAsString(const QString& name) const
{
    if (mAttributes.contains(name)) {
        return mAttributes.value(name);
    } else {
        throw std::runtime_error("Attribute not found: " + name.toStdString());
    }
}

int DomElement::getAttributeAsInt(const QString& name) const
{
    bool ok = false;
    int value = getAttributeAsString(name).toInt(&ok);
    if (ok) {
        return value;
    } else {
        throw std::runtime_error("Invalid integer in attribute " + name.toStdString());
    }
}

double DomElement::getAttributeAsDouble(const QString& name) const
{
    bool ok = false;
    double value = getAttributeAsString(name).toDouble(&ok);
    if (ok) {
        return value;
    } else {
        throw std::runtime_error("Invalid double in attribute " + name.toStdString());
    }
}

bool DomElement::hasChild(const QString& tagName) const noexcept
{
    foreach (const DomElement& child, mChilds) {
        if (tagName.isEmpty() || (child.getTagName() == tagName)) {
            return true;
        }
    }
    return false;
}

DomElement DomElement::getFirstChild(const QString& tagName) const
{
    foreach (const DomElement& child, mChilds) {
        if (tagName.isEmpty() || (child.getTagName() == tagName)) {
            return child;
        }
    }
    throw std::runtime_error("Child not found: " + tagName.toStdString());
}

} // namespace parseagle
