#include "AbstractFactoryHeader/ConcreteFactories/CppConstructionFactory.h"
#include "AbstractFactoryHeader/ConcreteFactories/CsConstructionFactory.h"
#include "AbstractFactoryHeader/ConcreteFactories/JavaConstructionFactory.h"
#include "LanguageConstructionsHeader/Cpp/CppModifier.h"
#include "LanguageConstructionsHeader/Cs/CsModifier.h"
#include "LanguageConstructionsHeader/Java/JavaModifiers.h"
#include "LanguageConstructionsHeader/Unit.h"
#include <QTextStream>

QString generateCppProgram()
{
    QSharedPointer<LanguageConstructionFactory> factory {new CppConstructionFactory};

    QSharedPointer<Unit> cppClass {factory->createClass("MyClass")};
    cppClass->add(
        factory->createMethod(
            "testFunc2",
            "void",
            (Unit::Flags)CppModifier::BehaviorModifier::Static),
       (Unit::Flags)CppModifier::AccessModifier::Private);

    QSharedPointer<Unit> cppMethod = factory->createMethod(
        "testFunc4", "void", (Unit::Flags)CppModifier::BehaviorModifier::Static);
    cppMethod->add(factory->createStatement(R"(Hello, world!\n)"));

    cppClass->add(cppMethod, (Unit::Flags)CppModifier::AccessModifier::Protected);

    cppClass->add(
        factory->createMethod("testFunc1"),
        (Unit::Flags)CppModifier::AccessModifier::Public);

    cppClass->add(
        factory->createMethod(
            "testFunc3",
            "void",
            (Unit::Flags)CppModifier::BehaviorModifier::Virtual |
                (Unit::Flags)CppModifier::BehaviorModifier::Const),
        (Unit::Flags)CppModifier::AccessModifier::Public);

    return cppClass->compile();
}

QString generateCsProgram()
{
    QSharedPointer<LanguageConstructionFactory> factory {new CsConstructionFactory};

    QSharedPointer<Unit> csClass {factory->createClass("MyClass")};
    csClass->add(
        factory->createMethod(
            "testFunc2",
            "void",
            (Unit::Flags)CsModifier::BehaviorModifier::Static),
        (Unit::Flags)CsModifier::AccessModifier::Private);

    QSharedPointer<Unit> csMethod = factory->createMethod(
        "testFunc4", "void", (Unit::Flags)CsModifier::BehaviorModifier::Static);
    csMethod->add(factory->createStatement(R"(Hello, world!\n)"));

    csClass->add(csMethod, (Unit::Flags)CsModifier::AccessModifier::Protected);

    csClass->add(
        factory->createMethod("testFunc1"),
        (Unit::Flags)CsModifier::AccessModifier::Public);

    csClass->add(
        factory->createMethod(
            "testFunc3",
            "void",
            (Unit::Flags)CsModifier::BehaviorModifier::Virtual),
        (Unit::Flags)CsModifier::AccessModifier::Public);


    return csClass->compile();
}

QString generateJavaProgram()
{
    QSharedPointer<LanguageConstructionFactory> factory {new JavaConstructionFactory};

    QSharedPointer<Unit> javaClass {factory->createClass("MyClass")};
    javaClass->add(
        factory->createMethod(
            "testFunc2",
            "void",
            (Unit::Flags)JavaModifier::BehaviorModifier::Final),
        (Unit::Flags)JavaModifier::AccessModifier::Private);

    QSharedPointer<Unit> javaMethod = factory->createMethod(
        "testFunc4", "void", (Unit::Flags)JavaModifier::BehaviorModifier::Final);
    javaMethod->add(factory->createStatement(R"(Hello, world!\n)"));

    javaClass->add(javaMethod, (Unit::Flags)JavaModifier::AccessModifier::Protected);

    javaClass->add(
        factory->createMethod("testFunc1"),
        (Unit::Flags)JavaModifier::AccessModifier::Public);

    javaClass->add(
        factory->createMethod(
            "testFunc3",
            "void",
            (Unit::Flags)JavaModifier::BehaviorModifier::Final),
        (Unit::Flags)JavaModifier::AccessModifier::Public);


    return javaClass->compile();
}

int main()
{
    QTextStream out {stdout};
    out << generateCppProgram() << Qt::endl;
}
