#ifndef CPPMODIFIER_H
#define CPPMODIFIER_H

#include "LanguageConstructionsHeader/Unit.h"
#include <QVector>
#include <QMap>

namespace CppModifier
{
    /*extern*/ const QVector<QString> accessModifierToString {
        "private", "protected", "public" };
    /*extern*/ const QMap<Unit::Flags, QString> behaviorModifierToString {
        { 1 << 0, "static" },
        { 1 << 1, "virtual" },
        { 1 << 2, "const" }};
    enum AccessModifier {
        Private, Protected, Public };
    enum BehaviorModifier : Unit::Flags {
        Static = 1 << 0,
        Virtual = 1 << 1,
        Const = 1 << 2 };
}
#endif // CPPMODIFIER_H
