#include "AbstractFactoryHeader/ConcreteFactories/CppConstructionFactory.h"
#include "LanguageConstructionsHeader/Cpp/ClassCppUnit.h"
#include "LanguageConstructionsHeader/Cpp/MethodCppUnit.h"
#include "LanguageConstructionsHeader/Cpp/PrintOperatorCppUnit.h"

QSharedPointer<Unit> CppConstructionFactory::createClass(const QString &name) const
{
    return QSharedPointer<Unit> {new ClassCppUnit(name)};
}

QSharedPointer<Unit> CppConstructionFactory::createMethod(const QString &name, const QString &returnType, Unit::Flags flags ) const
{
    return QSharedPointer<Unit> {new MethodCppUnit(name, returnType, flags)};
}

QSharedPointer<Unit> CppConstructionFactory::createStatement(const QString &text) const
{
    return QSharedPointer<Unit> {new PrintOperatorCppUnit(text)};
}
