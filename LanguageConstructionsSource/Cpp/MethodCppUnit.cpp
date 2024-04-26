#include "LanguageConstructionsHeader/Cpp/MethodCppUnit.h"

MethodCppUnit::MethodCppUnit(const QString &name, const QString &returnType, Flags flags)
    : _name {name}, _returnType {returnType}, _flags {flags} {}

void MethodCppUnit::add(const QSharedPointer<Unit> &unit, Flags flags)
{
    units.append(unit);
}

QString MethodCppUnit::compile(unsigned int level) const
{
    const Flags Static {static_cast<Flags>(BehaviorModifier::Static)};
    const Flags Virtual {static_cast<Flags>(BehaviorModifier::Virtual)};
    const Flags Const {static_cast<Flags>(BehaviorModifier::Const)};
    QString result {generateShift(level)};
    if (_flags & Static && _flags & Virtual)
        throw std::runtime_error("static and virtual modifiers cannot be used together");

    if (_flags & Static)
        result += behaviorModifierToString[Static];
    else if (_flags & Virtual)
        result += behaviorModifierToString[Virtual];
    result += ' ' + _returnType + ' ' + _name + "()";

    if (_flags & Const)
        result += ' ' + behaviorModifierToString[Const];
    result += "\n{\n";

    for (const QSharedPointer<Unit> &unit : units)
        result += unit->compile(level + 1);
    result += generateShift(level) + "}\n\n";

    return result;
}
