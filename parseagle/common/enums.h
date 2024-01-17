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

} // namespace parseagle

#endif // PARSEAGLE_ENUMS_H
