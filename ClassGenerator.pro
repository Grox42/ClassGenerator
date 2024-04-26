QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractFactorySource/ConcreteFactories/CppConstructionFactory.cpp \
    AbstractFactorySource/ConcreteFactories/CsConstructionFactory.cpp \
    AbstractFactorySource/ConcreteFactories/JavaConstructionFactory.cpp \
    LanguageConstructionsSource/Cpp/MethodCppUnit.cpp \
    LanguageConstructionsSource/Cpp/PrintOperatorCppUnit.cpp \
    LanguageConstructionsSource/Cs/MethodCsUnit.cpp \
    LanguageConstructionsSource/Cs/PrintOperatorCsUnit.cpp \
    LanguageConstructionsSource/Java/ClassJavaUnit.cpp \
    LanguageConstructionsSource/Java/MethodJavaUnit.cpp \
    LanguageConstructionsSource/Java/PrintOperatorJavaUnit.cpp \
    LanguageConstructionsSource/Unit.cpp \
    LanguageConstructionsSource/Cpp/ClassCppUnit.cpp \
    LanguageConstructionsSource/Cs/ClassCsUnit.cpp \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AbstractFactoryHeader/ConcreteFactories/CsConstructionFactory.h \
    AbstractFactoryHeader/ConcreteFactories/JavaConstructionFactory.h \
    LanguageConstructionsHeader/Cpp/MethodCppUnit.h \
    LanguageConstructionsHeader/Cpp/PrintOperatorCppUnit.h \
    LanguageConstructionsHeader/Cs/MethodCsUnit.h \
    LanguageConstructionsHeader/Cs/PrintOperatorCsUnit.h \
    LanguageConstructionsHeader/Java/ClassJavaUnit.h \
    LanguageConstructionsHeader/Java/MethodJavaUnit.h \
    LanguageConstructionsHeader/Java/PrintOperatorJavaUnit.h \
    LanguageConstructionsHeader/Unit.h \
    LanguageConstructionsHeader/Cpp/CppModifier.h \
    LanguageConstructionsHeader/Cpp/ClassCppUnit.h \
    LanguageConstructionsHeader/Cs/CsModifier.h \
    LanguageConstructionsHeader/Cs/ClassCsUnit.h \
    LanguageConstructionsHeader/Java/JavaModifiers.h \
    AbstractFactoryHeader/LanguageConstructionFactory.h \
    AbstractFactoryHeader/ConcreteFactories/CppConstructionFactory.h
