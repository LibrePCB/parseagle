#include <QtCore>
#include "segment.h"
#include "../common/domelement.h"

namespace parseagle {

Segment::Segment(const DomElement& root, QStringList* errors)
{
  foreach (const DomElement& child, root.getChilds()) {
      if (child.getTagName() == "pinref") {
          mPinRefs.append(PinRef(child));
      } else if (child.getTagName() == "wire") {
          mWires.append(Wire(child));
      } else if (child.getTagName() == "junction") {
          mJunctions.append(Point{
              child.getAttributeAsDouble("x"),
              child.getAttributeAsDouble("y"),
          });
      } else if (child.getTagName() == "label") {
          mLabels.append(Label(child));
      } else  if (errors) {
          errors->append("Unknown net segment child: " + child.getTagName());
      }
  }
}

Segment::~Segment() noexcept
{
}

} // namespace parseagle
