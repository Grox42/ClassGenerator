#include "LanguageConstructionsHeader/Cs/MethodCsUnit.h"
#include "LanguageConstructionsHeader/Cs/CsModifier.h"

using namespace CsModifier;

MethodCsUnit::MethodCsUnit(const QString &name, const QString &returnType, Flags flags)
    : _name {name}, _returnType {returnType}, _flags {flags} {}

void MethodCsUnit::add(const QSharedPointer<Unit> &unit, Flags flags)
{
    units.append(unit);
}

QString MethodCsUnit::compile(unsigned int level) const
{
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
