#include "AbstractFactoryHeader/ConcreteFactories/CppConstructionFactory.h"
#include "LanguageConstructionsHeader/Cpp/ClassCppUnit.h"
#include "LanguageConstructionsHeader/Cpp/MethodUnit.h"
#include "LanguageConstructionsHeader/Cpp/PrintOperatorUnit.h"

QSharedPointer<Unit> CppConstructionFactory::createClass(const QString &name) const
{
    return QSharedPointer<Unit> {new ClassCppUnit(name)};
}

QSharedPointer<Unit> CppConstructionFactory::createMethod(const QString &name, const QString &returnType, Unit::Flags flags ) const
{
    return QSharedPointer<Unit> {new MethodUnit(name, returnType, flags)};
}

QSharedPointer<Unit> CppConstructionFactory::createStatement(const QString &text) const
{
    return QSharedPointer<Unit> {new PrintOperatorUnit(text)};
}
