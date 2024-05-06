#include "AbstractFactoryHeader/ConcreteFactories/CppConstructionFactory.h"
#include "AbstractFactoryHeader/ConcreteFactories/CsConstructionFactory.h"
#include "AbstractFactoryHeader/ConcreteFactories/JavaConstructionFactory.h"
#include "LanguageConstructionsHeader/Unit.h"
#include <QTextStream>

QString generateCppProgram()
{
    using namespace CppModifier;
    QSharedPointer<LanguageConstructionFactory> factory {new CppConstructionFactory};

    QSharedPointer<Unit> cppClass {factory->createClass("MyClass")};
    cppClass->add(
        factory->createMethod("testFunc2", "void", Static),
        Private);

    QSharedPointer<Unit> cppMethod = factory->createMethod("testFunc4", "void", Static);
    cppMethod->add(factory->createStatement(R"(Hello, world!\n)"));

    cppClass->add(cppMethod, Protected);

    cppClass->add(
        factory->createMethod("testFunc1"),
        Public);

    cppClass->add(
        factory->createMethod("testFunc3", "void", Virtual | Const),
        Public);

    return cppClass->compile();
}

QString generateCsProgram()
{
    using namespace CsModifier;
    QSharedPointer<LanguageConstructionFactory> factory {new CsConstructionFactory};

    QSharedPointer<Unit> csClass {factory->createClass("MyClass")};
    csClass->add(
        factory->createMethod("testFunc2", "void", Static),
        Private);

    QSharedPointer<Unit> csMethod = factory->createMethod("testFunc4", "void", Static);
    csMethod->add(factory->createStatement(R"(Hello, world!\n)"));

    csClass->add(csMethod, Protected);

    csClass->add(
        factory->createMethod("testFunc1"),
        Public);

    csClass->add(
        factory->createMethod("testFunc3", "void", Virtual),
        Public);

    return csClass->compile();
}

QString generateJavaProgram()
{
    using namespace JavaModifier;
    QSharedPointer<LanguageConstructionFactory> factory {new JavaConstructionFactory};

    QSharedPointer<Unit> javaClass {factory->createClass("MyClass")};
    javaClass->add(
        factory->createMethod("testFunc2", "void", Final),
        Private);

    QSharedPointer<Unit> javaMethod = factory->createMethod("testFunc4", "void", Final);
    javaMethod->add(factory->createStatement(R"(Hello, world!\n)"));

    javaClass->add(javaMethod, Protected);

    javaClass->add(
        factory->createMethod("testFunc1"),
        Public);

    javaClass->add(
        factory->createMethod("testFunc3", "void", Final),
        Public);

    return javaClass->compile();
}

int main()
{
    QTextStream out {stdout};
    out << generateCppProgram() << Qt::endl;
}
