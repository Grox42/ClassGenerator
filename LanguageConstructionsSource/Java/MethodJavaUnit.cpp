#include "LanguageConstructionsHeader/Java/MethodJavaUnit.h"

MethodJavaUnit::MethodJavaUnit(const QString &name, const QString &returnType, Flags flags)
    : _name {name}, _returnType {returnType}, _flags {flags} {}

void MethodJavaUnit::add(const QSharedPointer<Unit> &unit, Flags flags)
{
    units.append(unit);
}

QString MethodJavaUnit::compile(unsigned int level) const
{
    //const Flags Static {static_cast<Flags>(BehaviorModifier::Static)};
    //const Flags Abstract {static_cast<Flags>(BehaviorModifier::Abstract)};
    const Flags Final {static_cast<Flags>(BehaviorModifier::Final)};
    QString result;

    //if (_flags & Static)
    //    result += behaviorModifierToString[Static] + ' ';
    //else if (_flags & Abstract)
    //    result += behaviorModifierToString[Abstract] + ' ';
    /*else*/ if (_flags & Final)
        result += behaviorModifierToString[Final] + ' ';
    result += _returnType + ' ' + _name + "() {\n";

    if (units.empty()) return result + generateShift(level) + "}\n";
    for (const QSharedPointer<Unit> &unit : units)
        result += unit->compile(level + 1);

    result += generateShift(level) + "}\n";
    return result;
}
