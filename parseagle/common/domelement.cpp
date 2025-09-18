#include <QtCore>
#include "domelement.h"

namespace parseagle {

DomElement::DomElement(QXmlStreamReader& reader)
{
    mName = reader.name().toString();
    for (const QXmlStreamAttribute& attr : reader.attributes()) {
        mAttributes.insert(attr.name().toString(), attr.value().toString());
    }

    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isCharacters()) {
            mText.append(reader.text().toString());
        } else if (reader.isStartElement()) {
            mChilds.append(DomElement(reader));
        } else if (reader.isEndElement()) {
            break;
        }
    }

    if (reader.hasError()) {
        const QString err = "Failed to parse XML: " + reader.errorString();
        throw std::runtime_error(err.toStdString());
    }
}

DomElement::~DomElement() noexcept
{
}

DomElement DomElement::parse(QXmlStreamReader& reader)
{
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isStartElement()) {
            break;
        }
    }
    if (reader.hasError() || (!reader.isStartElement())) {
        const QString err = "Failed to find XML root element: " + reader.errorString();
        throw std::runtime_error(err.toStdString());
    }
    const DomElement root(reader);
    if (reader.hasError() || (!reader.isEndElement())) {
        const QString err = "XML file seems incomplete: " + reader.errorString();
        throw std::runtime_error(err.toStdString());
    }
    return root;
}

DomElement DomElement::parse(const QString& data)
{
    QXmlStreamReader reader;
    reader.addData(data);
    return parse(reader);
}

DomElement DomElement::parse(const QByteArray& data)
{
    QXmlStreamReader reader;
    reader.addData(data);
    return parse(reader);
}

QString DomElement::getAttributeAsString(const QString& name) const
{
    if (mAttributes.contains(name)) {
        return mAttributes.value(name);
    } else {
        throw std::runtime_error(
            QString("Attribute '%1' not found in XML element '%2'.")
            .arg(name).arg(mName).toStdString());
    }
}

bool DomElement::getAttributeAsBool(const QString& name) const
{
  const QString value = getAttributeAsString(name);
  if (value == "yes") {
    return true;
  } else if (value == "no") {
    return false;
  } else {
    throw std::runtime_error("Invalid bool in attribute " + name.toStdString());
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
