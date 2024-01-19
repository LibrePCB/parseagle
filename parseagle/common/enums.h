#ifndef PARSEAGLE_ENUMS_H
#define PARSEAGLE_ENUMS_H

#include <QtCore>

namespace parseagle {

enum class Alignment
{
    Unknown,  // Failed to parse XML attribute.
    BottomLeft,
    BottomCenter,
    BottomRight,
    CenterLeft,
    Center,
    CenterRight,
    TopLeft,
    TopCenter,
    TopRight,
};

inline Alignment parseAlignment(const QString& s, QStringList* errors = nullptr)
{
    if (s == "bottom-left") {
        return Alignment::BottomLeft;
    } else if (s == "bottom-center") {
        return Alignment::BottomCenter;
    } else if (s == "bottom-right") {
        return Alignment::BottomRight;
    } else if (s == "center-left") {
        return Alignment::CenterLeft;
    } else if (s == "center") {
        return Alignment::Center;
    } else if (s == "center-right") {
        return Alignment::CenterRight;
    } else if (s == "top-left") {
        return Alignment::TopLeft;
    } else if (s == "top-center") {
        return Alignment::TopCenter;
    } else if (s == "top-right") {
        return Alignment::TopRight;
    } else if (errors) {
        errors->append("Unknown alignment: " + s);
    }
    return Alignment::Unknown;
}

enum class AttributeDisplay
{
    Unknown,  // Failed to parse XML attribute.
    Off,
    Value,
    Name,
    Both,
};

inline AttributeDisplay parseAttributeDisplay(const QString& s, QStringList* errors = nullptr)
{
    if (s == "off") {
        return AttributeDisplay::Off;
    } else if (s == "value") {
        return AttributeDisplay::Value;
    } else if (s == "name") {
        return AttributeDisplay::Name;
    } else if (s == "both") {
        return AttributeDisplay::Both;
    } else if (errors) {
        errors->append("Unknown attribute display: " + s);
    }
    return AttributeDisplay::Unknown;
}

enum class Font
{
    Unknown,  // Failed to parse XML attribute.
    Fixed,
    Proportional,
    Vector,
};

inline Font parseFont(const QString& s, QStringList* errors = nullptr)
{
    if (s == "fixed") {
        return Font::Fixed;
    } else if (s == "proportional") {
        return Font::Proportional;
    } else if (s == "vector") {
        return Font::Vector;
    } else if (errors) {
        errors->append("Unknown font: " + s);
    }
    return Font::Unknown;
}

enum class GateAddLevel
{
    Unknown,  // Failed to parse XML attribute.
    Must,
    Can,
    Next,
    Request,
    Always,
};

inline GateAddLevel parseGateAddLevel(const QString& s, QStringList* errors = nullptr)
{
    if (s == "must") {
        return GateAddLevel::Must;
    } else if (s == "can") {
        return GateAddLevel::Can;
    } else if (s == "next") {
        return GateAddLevel::Next;
    } else if (s == "request") {
        return GateAddLevel::Request;
    } else if (s == "always") {
        return GateAddLevel::Always;
    } else if (errors) {
        errors->append("Unknown gate add level: " + s);
    }
    return GateAddLevel::Unknown;
}

enum class GridStyle
{
    Unknown,  // Failed to parse XML attribute.
    Lines,
    Dots,
};

inline GridStyle parseGridStyle(const QString& s, QStringList* errors = nullptr)
{
    if (s == "lines") {
        return GridStyle::Lines;
    } else if (s == "dots") {
        return GridStyle::Dots;
    } else if (errors) {
        errors->append("Unknown grid style: " + s);
    }
    return GridStyle::Unknown;
}

enum class GridUnit
{
    Unknown,  // Failed to parse XML attribute.
    Micrometers,
    Millimeters,
    Mils,
    Inches,
};

inline GridUnit parseGridUnit(const QString& s, QStringList* errors = nullptr)
{
    if (s == "mic") {
        return GridUnit::Micrometers;
    } else if (s == "mm") {
        return GridUnit::Millimeters;
    } else if (s == "mil") {
        return GridUnit::Mils;
    } else if (s == "inch") {
        return GridUnit::Inches;
    } else if (errors) {
        errors->append("Unknown grid unit: " + s);
    }
    return GridUnit::Unknown;
}

enum class PadShape
{
    Unknown,  // Failed to parse XML attribute.
    Square,
    Round,
    Octagon,
    Long,
    Offset,
};

inline PadShape parsePadShape(const QString& s, QStringList* errors = nullptr)
{
    if (s == "square") {
        return PadShape::Square;
    } else if (s == "round") {
        return PadShape::Round;
    } else if (s == "octagon") {
        return PadShape::Octagon;
    } else if (s == "long") {
        return PadShape::Long;
    } else if (s == "offset") {
        return PadShape::Offset;
    } else if (errors) {
        errors->append("Unknown pad shape: " + s);
    }
    return PadShape::Unknown;
}

enum class PinDirection
{
    Unknown,  // Failed to parse XML attribute.
    NotConnected,
    Input,
    Output,
    IO,
    OpenCollector,
    Power,
    Passive,
    HighZ,
    Supply,
};

inline PinDirection parsePinDirection(const QString& s, QStringList* errors = nullptr)
{
    if (s == "nc") {
        return PinDirection::NotConnected;
    } else if (s == "in") {
        return PinDirection::Input;
    } else if (s == "out") {
        return PinDirection::Output;
    } else if (s == "io") {
        return PinDirection::IO;
    } else if (s == "oc") {
        return PinDirection::OpenCollector;
    } else if (s == "pwr") {
        return PinDirection::Power;
    } else if (s == "pas") {
        return PinDirection::Passive;
    } else if (s == "hiz") {
        return PinDirection::HighZ;
    } else if (s == "sup") {
        return PinDirection::Supply;
    } else if (errors) {
        errors->append("Unknown pin direction: " + s);
    }
    return PinDirection::Unknown;
}

enum class PinFunction
{
    Unknown,  // Failed to parse XML attribute.
    None,
    Dot,
    Clock,
    DotClock,
};

inline PinFunction parsePinFunction(const QString& s, QStringList* errors = nullptr)
{
    if (s == "none") {
        return PinFunction::None;
    } else if (s == "dot") {
        return PinFunction::Dot;
    } else if (s == "clk") {
        return PinFunction::Clock;
    } else if (s == "dotclk") {
        return PinFunction::DotClock;
    } else if (errors) {
        errors->append("Unknown pin function: " + s);
    }
    return PinFunction::Unknown;
}

enum class PinLength
{
    Unknown,  // Failed to parse XML attribute.
    Point,
    Short,
    Middle,
    Long,
};

inline PinLength parsePinLength(const QString& s, QStringList* errors = nullptr)
{
    if (s == "point") {
        return PinLength::Point;
    } else if (s == "short") {
        return PinLength::Short;
    } else if (s == "middle") {
        return PinLength::Middle;
    } else if (s == "long") {
        return PinLength::Long;
    } else if (errors) {
        errors->append("Unknown pin length: " + s);
    }
    return PinLength::Unknown;
}

enum class PinVisibility
{
    Unknown,  // Failed to parse XML attribute.
    Off,
    Pad,
    Pin,
    Both,
};

inline PinVisibility parsePinVisibility(const QString& s, QStringList* errors = nullptr)
{
    if (s == "off") {
        return PinVisibility::Off;
    } else if (s == "pad") {
        return PinVisibility::Pad;
    } else if (s == "pin") {
        return PinVisibility::Pin;
    } else if (s == "both") {
        return PinVisibility::Both;
    } else if (errors) {
        errors->append("Unknown pin visibility: " + s);
    }
    return PinVisibility::Unknown;
}

enum class PolygonPour
{
    Unknown,  // Failed to parse XML attribute.
    Solid,
    Hatch,
    Cutout,
};

inline PolygonPour parsePolygonPour(const QString& s, QStringList* errors = nullptr)
{
    if (s == "solid") {
        return PolygonPour::Solid;
    } else if (s == "hatch") {
        return PolygonPour::Hatch;
    } else if (s == "cutout") {
        return PolygonPour::Cutout;
    } else if (errors) {
        errors->append("Unknown polygon pour: " + s);
    }
    return PolygonPour::Unknown;
}

enum class ViaShape
{
    Unknown,  // Failed to parse XML attribute.
    Square,
    Round,
    Octagon,
};

inline ViaShape parseViaShape(const QString& s, QStringList* errors = nullptr)
{
    if (s == "square") {
        return ViaShape::Square;
    } else if (s == "round") {
        return ViaShape::Round;
    } else if (s == "octagon") {
        return ViaShape::Octagon;
    } else if (errors) {
        errors->append("Unknown via shape: " + s);
    }
    return ViaShape::Unknown;
}

} // namespace parseagle

#endif // PARSEAGLE_ENUMS_H
