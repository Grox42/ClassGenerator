#include "LanguageConstructionsHeader/Cpp/MethodCppUnit.h"
#include "LanguageConstructionsHeader/Cpp/CppModifier.h"

using namespace CppModifier;

MethodCppUnit::MethodCppUnit(const QString &name, const QString &returnType, Flags flags)
    : _name {name}, _returnType {returnType}, _flags {flags} {}

void MethodCppUnit::add(const QSharedPointer<Unit> &unit, Flags flags)
{
    _units.append(unit);
}

QString MethodCppUnit::compile(unsigned int level) const
{
    QString result {generateShift(level)};

    if (_flags & Static)
        result += behaviorModifierToString[Static] + ' ';
    else if (_flags & Virtual)
        result += behaviorModifierToString[Virtual] + ' ';
    result += _returnType + ' ' + _name + "()";

    if (_flags & Const)
        result += ' ' + behaviorModifierToString[Const];
    result += " {\n";

    if (_units.empty()) return result + generateShift(level) + "}\n";
    for (const QSharedPointer<Unit> &unit : _units)
        result += unit->compile(level + 1);

    result += generateShift(level) + "}\n";
    return result;
}
