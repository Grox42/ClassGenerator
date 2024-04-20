QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractFactorySource/ConcreteFactories/CppConstructionFactory.cpp \
    LanguageConstructionsSource/Unit.cpp \
    ##
    LanguageConstructionsSource/Cpp/ClassCppUnit.cpp \
    LanguageConstructionsSource/Cpp/MethodUnit.cpp \
    LanguageConstructionsSource/Cpp/PrintOperatorUnit.cpp \
    #
    LanguageConstructionsSource/Cs/ClassCsUnit.cpp \
    ###
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    LanguageConstructionsHeader/Unit.h \
    ##
    LanguageConstructionsHeader/Cpp/CppModifier.h \
    LanguageConstructionsHeader/Cpp/ClassCppUnit.h \
    LanguageConstructionsHeader/Cpp/MethodUnit.h \
    LanguageConstructionsHeader/Cpp/PrintOperatorUnit.h \
    #
    LanguageConstructionsHeader/Cs/CsModifier.h \
    LanguageConstructionsHeader/Cs/ClassCsUnit.h \
    #
    LanguageConstructionsHeader/Java/JavaModifiers.h \
    ##
    AbstractFactoryHeader/LanguageConstructionFactory.h \
    #
    AbstractFactoryHeader/ConcreteFactories/CppConstructionFactory.h \
    behaviorModifier.h
