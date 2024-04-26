#include "AbstractFactoryHeader/ConcreteFactories/JavaConstructionFactory.h"
#include "LanguageConstructionsHeader/Java/ClassJavaUnit.h"
#include "LanguageConstructionsHeader/Java/MethodJavaUnit.h"
#include "LanguageConstructionsHeader/Java/PrintOperatorJavaUnit.h"

QSharedPointer<Unit> JavaConstructionFactory::createClass(const QString &name) const
{
    return QSharedPointer<Unit> {new ClassJavaUnit(name)};
}

QSharedPointer<Unit> JavaConstructionFactory::createMethod(const QString &name, const QString &returnType, Unit::Flags flags ) const
{
    return QSharedPointer<Unit> {new MethodJavaUnit(name, returnType, flags)};
}

QSharedPointer<Unit> JavaConstructionFactory::createStatement(const QString &text) const
{
    return QSharedPointer<Unit> {new PrintOperatorJavaUnit(text)};
}
