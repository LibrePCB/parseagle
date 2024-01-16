#ifndef PARSEAGLE_SCHEMATIC_H
#define PARSEAGLE_SCHEMATIC_H

#include <QtCore>
#include "../common/grid.h"
#include "../library.h"
#include "module.h"
#include "part.h"
#include "sheet.h"

namespace parseagle {

class Schematic final
{
    public:

        // Constructors / Destructor
        Schematic() = delete;
        explicit Schematic(const QString& filepath, QStringList* errors = nullptr);
        explicit Schematic(const QByteArray& content, QStringList* errors = nullptr);
        ~Schematic() noexcept;

        // Getters
        const QString& getDescription() const noexcept {return mDescription;}
        const Grid& getGrid() const noexcept {return mGrid;}
        const QList<Library>& getLibraries() const noexcept {return mLibraries;}
        const QList<Module>& getModules() const noexcept {return mModules;}
        const QList<Part>& getParts() const noexcept {return mParts;}
        const QList<Sheet>& getSheets() const noexcept {return mSheets;}


    private:
        void load(const QByteArray& content, QStringList* errors = nullptr);


        QString mDescription;
        Grid mGrid;
        QList<Library> mLibraries;
        QList<Module> mModules;
        QList<Part> mParts;
        QList<Sheet> mSheets;
};

} // namespace parseagle

#endif // PARSEAGLE_SCHEMATIC_H
