#include <QtCore>
#include "sheet.h"
#include "../common/domelement.h"

namespace parseagle {

Sheet::Sheet(const DomElement& root, QStringList* errors)
{
    foreach (const DomElement& child, root.getChilds()) {
        if (child.getTagName() == "description") {
            mDescription = child.getText();
        } else if (child.getTagName() == "plain") {
            foreach (const DomElement& plainChild, child.getChilds()) {
                if (plainChild.getTagName() == "wire") {
                    mWires.append(Wire(plainChild, errors));
                } else if (plainChild.getTagName() == "rectangle") {
                    mRectangles.append(Rectangle(plainChild));
                } else if (plainChild.getTagName() == "circle") {
                    mCircles.append(Circle(plainChild));
                } else if (plainChild.getTagName() == "polygon") {
                    mPolygons.append(Polygon(plainChild, errors));
                } else if (plainChild.getTagName() == "text") {
                    mTexts.append(Text(plainChild, errors));
                } else if (plainChild.getTagName() == "frame") {
                    mFrames.append(Frame(plainChild));
                } else if (plainChild.getTagName() == "dimension") {
                    mDimensions.append(Dimension(plainChild));
                } else if (errors) {
                    errors->append("Unknown sheet plain child: " + plainChild.getTagName());
                }
            }
        } else if (child.getTagName() == "instances") {
            foreach (const DomElement& instanceChild, child.getChilds()) {
                mInstances.append(Instance(instanceChild, errors));
            }
        } else if (child.getTagName() == "busses") {
            foreach (const DomElement& busChild, child.getChilds()) {
                mBuses.append(Bus(busChild));
            }
        } else if (child.getTagName() == "nets") {
            foreach (const DomElement& netChild, child.getChilds()) {
                mNets.append(Net(netChild, errors));
            }
        } else if (errors) {
            errors->append("Unknown sheet child: " + child.getTagName());
        }
    }
}

Sheet::~Sheet() noexcept
{
}

} // namespace parseagle
