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

Library::~Library() noexcept
{
}

void Library::load(const QByteArray& content, QStringList* errors) {
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

    if (library.hasChild("description")) {
        mDescription = library.getFirstChild("description").getText();
    }

    if (library.hasChild("symbols")) {
        foreach (const DomElement& child, library.getFirstChild("symbols").getChilds()) {
            try {
                mSymbols.append(Symbol(child, errors));
            } catch (const std::exception& e) {
                if (errors) {
                    errors->append(QString("Failed to parse symbol: %1").arg(e.what()));
                }
            }
        }
    }
    if (library.hasChild("packages")) {
        foreach (const DomElement& child, library.getFirstChild("packages").getChilds()) {
            try {
                mPackages.append(Package(child, errors));
            } catch (const std::exception& e) {
                if (errors) {
                    errors->append(QString("Failed to parse package: %1").arg(e.what()));
                }
            }
        }
    }
    if (library.hasChild("devicesets")) {
        foreach (const DomElement& child, library.getFirstChild("devicesets").getChilds()) {
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
