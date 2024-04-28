#ifndef LANGUAGECONSTRUCTIONFACTORY_H
#define LANGUAGECONSTRUCTIONFACTORY_H

#include "LanguageConstructionsHeader/Unit.h"

class LanguageConstructionFactory
{
public:
    virtual QSharedPointer<Unit> createClass(const QString &name) const = 0;
    virtual QSharedPointer<Unit> createMethod(
        const QString &name,
        const QString &returnType = "void",
        Unit::Flags flags = 0) const = 0;
    virtual QSharedPointer<Unit> createStatement(const QString &text) const = 0;
    virtual ~LanguageConstructionFactory() = default;
};

#endif // LANGUAGECONSTRUCTIONFACTORY_H
