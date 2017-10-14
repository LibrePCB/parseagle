#include <QtCore>
#include "library.h"
#include "common/domelement.h"

namespace parseagle {

Library::Library(const QString& filepath)
{
    QFile file(filepath);
    if (!file.exists()) {
        throw std::runtime_error("File does not exist: " + filepath.toStdString());
    }
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Cannot open file " + filepath.toStdString() +
                                 ": " + file.errorString().toStdString());
    }

    QDomDocument doc;
    doc.implementation().setInvalidDataPolicy(QDomImplementation::ReturnNullNode);
    QString errMsg;
    if (!doc.setContent(file.readAll(), &errMsg)) {
        throw std::runtime_error("Error while parsing file " + filepath.toStdString() +
                                 ": " + errMsg.toStdString());
    }
    DomElement root(doc.documentElement());
    DomElement drawing = root.getFirstChild("drawing");
    DomElement library = drawing.getFirstChild("library");

    if (library.hasChild("description")) {
        mDescription = library.getFirstChild("description").getText();
    }

    if (library.hasChild("symbols")) {
        foreach (const DomElement& child, library.getFirstChild("symbols").getChilds()) {
            mSymbols.append(Symbol(child));
        }
    }
    if (library.hasChild("packages")) {
        foreach (const DomElement& child, library.getFirstChild("packages").getChilds()) {
            mPackages.append(Package(child));
        }
    }
    foreach (const DomElement& child, library.getFirstChild("devicesets").getChilds()) {
        mDeviceSets.append(DeviceSet(child));
    }
}

Library::~Library() noexcept
{
}

} // namespace parseagle
