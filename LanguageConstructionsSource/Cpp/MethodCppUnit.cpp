#include "LanguageConstructionsHeader/Cpp/MethodCppUnit.h"

MethodCppUnit::MethodCppUnit(const QString &name, const QString &returnType, Flags flags)
    : _name {name}, _returnType {returnType}, _flags {flags} {}

void MethodCppUnit::add(const QSharedPointer<Unit> &unit, Flags flags)
{
    _units.append(unit);
}

QString MethodCppUnit::compile(unsigned int level) const
{
    const Flags Static {static_cast<Flags>(BehaviorModifier::Static)};
    const Flags Virtual {static_cast<Flags>(BehaviorModifier::Virtual)};
    const Flags Const {static_cast<Flags>(BehaviorModifier::Const)};
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
