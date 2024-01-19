#include <QtCore>
#include "library.h"
#include "common/domelement.h"

namespace parseagle {

Library::Library(const QString& filepath, QStringList* errors)
{
    QFile file(filepath);
    if (!file.exists()) {
        throw std::runtime_error("File does not exist: " + filepath.toStdString());
    }
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Cannot open file " + filepath.toStdString() +
                                 ": " + file.errorString().toStdString());
    }
    load(file.readAll(), errors);
}

Library::Library(const QByteArray& content, QStringList* errors)
{
    load(content, errors);
}

Library::Library(const DomElement& root, QStringList* errors)
{
  load(root, errors);
}

Library::~Library() noexcept
{
}

void Library::load(const QByteArray& content, QStringList* errors)
{
    QDomDocument doc;
    doc.implementation().setInvalidDataPolicy(QDomImplementation::ReturnNullNode);
    QString errMsg;
    if (!doc.setContent(content, &errMsg)) {
        throw std::runtime_error(
            "Error while parsing EAGLE library: " + errMsg.toStdString());
    }
    DomElement root(doc.documentElement());
    DomElement drawing = root.getFirstChild("drawing");
    DomElement library = drawing.getFirstChild("library");
    load(library, errors);
}

void Library::load(const DomElement& root, QStringList* errors)
{
    if (root.hasAttribute("name")) {
        mEmbeddedName = root.getAttributeAsString("name");
    }
    if (root.hasAttribute("urn")) {
        mEmbeddedUrn = root.getAttributeAsString("urn");
    }
    if (root.hasChild("description")) {
        mDescription = root.getFirstChild("description").getText();
    }
    if (root.hasChild("symbols")) {
        foreach (const DomElement& child, root.getFirstChild("symbols").getChilds()) {
            try {
                mSymbols.append(Symbol(child, errors));
            } catch (const std::exception& e) {
                if (errors) {
                    errors->append(QString("Failed to parse symbol: %1").arg(e.what()));
                }
            }
        }
    }
    if (root.hasChild("packages")) {
        foreach (const DomElement& child, root.getFirstChild("packages").getChilds()) {
            try {
                mPackages.append(Package(child, errors));
            } catch (const std::exception& e) {
                if (errors) {
                    errors->append(QString("Failed to parse package: %1").arg(e.what()));
                }
            }
        }
    }
    if (root.hasChild("devicesets")) {
        foreach (const DomElement& child, root.getFirstChild("devicesets").getChilds()) {
            try {
                mDeviceSets.append(DeviceSet(child, errors));
            } catch (const std::exception& e) {
                if (errors) {
                    errors->append(QString("Failed to parse deviceset: %1").arg(e.what()));
                }
            }
        }
    }
}

} // namespace parseagle
