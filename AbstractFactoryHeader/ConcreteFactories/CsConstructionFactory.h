#ifndef CSCONSTRUCTIONFACTORY_H
#define CSCONSTRUCTIONFACTORY_H

#include "AbstractFactoryHeader/LanguageConstructionFactory.h"
#include "LanguageConstructionsHeader/Cs/CsModifier.h"

class CsConstructionFactory : public LanguageConstructionFactory
{
public:
    QSharedPointer<Unit> createClass(const QString &name) const override;
    QSharedPointer<Unit> createMethod(
        const QString &name,
        const QString &returnType = "void",
        Unit::Flags flags = 0) const override;
    QSharedPointer<Unit> createStatement(const QString &text) const override;
    ~CsConstructionFactory() override = default;
};

#endif // CSCONSTRUCTIONFACTORY_H
