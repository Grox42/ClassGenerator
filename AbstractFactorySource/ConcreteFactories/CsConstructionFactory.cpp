#include "AbstractFactoryHeader/ConcreteFactories/CsConstructionFactory.h"
#include "LanguageConstructionsHeader/Cs/ClassCsUnit.h"
#include "LanguageConstructionsHeader/Cs/MethodCsUnit.h"
#include "LanguageConstructionsHeader/Cs/PrintOperatorCsUnit.h"

QSharedPointer<Unit> CsConstructionFactory::createClass(const QString &name) const
{
    return QSharedPointer<Unit> {new ClassCsUnit(name)};
}

QSharedPointer<Unit> CsConstructionFactory::createMethod(const QString &name, const QString &returnType, Unit::Flags flags ) const
{
    return QSharedPointer<Unit> {new MethodCsUnit(name, returnType, flags)};
}

QSharedPointer<Unit> CsConstructionFactory::createStatement(const QString &text) const
{
    return QSharedPointer<Unit> {new PrintOperatorCsUnit(text)};
}
