#include "LanguageConstructionsHeader/Cs/MethodCsUnit.h"

MethodCsUnit::MethodCsUnit(const QString &name, const QString &returnType, Flags flags)
    : _name {name}, _returnType {returnType}, _flags {flags} {}

void MethodCsUnit::add(const QSharedPointer<Unit> &unit, Flags flags)
{
    units.append(unit);
}

QString MethodCsUnit::compile(unsigned int level) const
{
    const Flags Static {static_cast<Flags>(BehaviorModifier::Static)};
    const Flags Virtual {static_cast<Flags>(BehaviorModifier::Virtual)};
    //const Flags Abstract {static_cast<Flags>(BehaviorModifier::Abstract)};
    QString result;

    if (_flags & Static)
        result += behaviorModifierToString[Static] + ' ';
    else if (_flags & Virtual)
        result += behaviorModifierToString[Virtual] + ' ';
    //else if (_flags & Abstract)
    //    result += behaviorModifierToString[Abstract] + ' ';
    result += _returnType + ' ' + _name + "() {\n";

    if (units.empty()) return result + generateShift(level) + "}\n";
    for (const QSharedPointer<Unit> &unit : units)
        result += unit->compile(level + 1);

    result += generateShift(level) + "}\n";
    return result;
}
