#ifndef PARSEAGLE_DIMENSION_H
#define PARSEAGLE_DIMENSION_H

#include <QtCore>

namespace parseagle {

class DomElement;

class Dimension final
{
    public:

        // Constructors / Destructor
        Dimension() = delete;
        explicit Dimension(const DomElement& root);
        ~Dimension() noexcept;


    private:
        // Not implemented yet.
};

} // namespace parseagle

#endif // PARSEAGLE_DIMENSION_H
