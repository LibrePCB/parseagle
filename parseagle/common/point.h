#ifndef PARSEAGLE_POINT_H
#define PARSEAGLE_POINT_H

namespace parseagle {

struct Point {
    double x;
    double y;

    bool operator==(const Point& rhs) const noexcept {return (x == rhs.x) && (y == rhs.y);}
    bool operator!=(const Point& rhs) const noexcept {return !(*this == rhs);}
};

} // namespace parseagle

#endif // PARSEAGLE_POINT_H

