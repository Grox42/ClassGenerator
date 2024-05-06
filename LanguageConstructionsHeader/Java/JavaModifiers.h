#ifndef JAVAMODIFIERS_H
#define JAVAMODIFIERS_H

#include "LanguageConstructionsHeader/Unit.h"
#include <QVector>
#include <QMap>

namespace JavaModifier
{
    /*extern*/ const QVector<QString> accessModifierToString {
        "private",  "protected", "public" };
    /*extern*/ const QMap<Unit::Flags, QString> behaviorModifierToString {
        /*{ 1 << 0, "static" },
        { 1 << 1, "abstract" },*/
        { 1 << 0/*2*/, "final" }};
    enum AccessModifier {
        Private, Protected, Public };
    enum BehaviorModifier : Unit::Flags {
        /*Static = 1 << 0,
        Abstract = 1 << 1,*/
        Final = 1 << 0/*2*/ };
}

#endif // JAVAMODIFIERS_H
