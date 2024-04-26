#ifndef JAVACONSTRUCTIONFACTORY_H
#define JAVACONSTRUCTIONFACTORY_H

#include "AbstractFactoryHeader/LanguageConstructionFactory.h"

class JavaConstructionFactory : public LanguageConstructionFactory
{
public:
    QSharedPointer<Unit> createClass(const QString &name) const override;
    QSharedPointer<Unit> createMethod(
        const QString &name,
        const QString &returnType = "void",
        Unit::Flags flags = 0) const override;
    QSharedPointer<Unit> createStatement(const QString &text) const override;
};

#endif // JAVACONSTRUCTIONFACTORY_H
