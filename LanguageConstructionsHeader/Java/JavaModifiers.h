#ifndef JAVAMODIFIERS_H
#define JAVAMODIFIERS_H

#include "LanguageConstructionsHeader/Unit.h"
#include <QVector>
#include <QMap>

class JavaModifier
{
protected:
    inline static const QVector<QString> accessModifierToString {
        "private",  "protected", "public" };
    inline static const QMap<Unit::Flags, QString> behaviorModifierToString {
        { 1 << 0, "static" },
        { 1 << 1, "abstract" },
        { 1 << 2, "final" }};
public:
    enum class AccessModifier {
        Private, Protected, Public };
    enum class BehaviorModifier : Unit::Flags {
        Static = 1 << 0,
        Abstract = 1 << 1,
        Final = 1 << 2 };
};

#endif // JAVAMODIFIERS_H
