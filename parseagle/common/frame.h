#ifndef PARSEAGLE_FRAME_H
#define PARSEAGLE_FRAME_H

#include <QtCore>
#include "../common/point.h"
#include "../common/rotation.h"

namespace parseagle {

class DomElement;

class Frame final
{
    public:

        // Constructors / Destructor
        Frame() = delete;
        explicit Frame(const DomElement& root);
        ~Frame() noexcept;

        // Getters
        int getLayer() const noexcept {return mLayer;}
        const Point& getP1() const noexcept {return mP1;}
        const Point& getP2() const noexcept {return mP2;}
        int getColumns() const noexcept {return mColumns;}
        int getRows() const noexcept {return mRows;}


    private:
        int mLayer;
        Point mP1;
        Point mP2;
        int mColumns;
        int mRows;
};

} // namespace parseagle

#endif // PARSEAGLE_FRAME_H
