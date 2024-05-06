#ifndef CPPCONSTRUCTIONFACTORY_H
#define CPPCONSTRUCTIONFACTORY_H

#include "AbstractFactoryHeader/LanguageConstructionFactory.h"
#include "LanguageConstructionsHeader/Cpp/CppModifier.h"

class CppConstructionFactory : public LanguageConstructionFactory
{
public:
    QSharedPointer<Unit> createClass(const QString &name) const override;
    QSharedPointer<Unit> createMethod(
        const QString &name,
        const QString &returnType = "void",
        Unit::Flags flags = 0) const override;
    QSharedPointer<Unit> createStatement(const QString &text) const override;
    ~CppConstructionFactory() override = default;
};

#endif // CPPCONSTRUCTIONFACTORY_H
