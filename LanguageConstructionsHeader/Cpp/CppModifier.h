#ifndef CPPMODIFIER_H
#define CPPMODIFIER_H

#include "LanguageConstructionsHeader/Unit.h"
#include <QVector>
#include <QMap>

class CppModifier
{
protected:
    inline static const QVector<QString> accessModifierToString {
        "private", "protected", "public" };
    inline static const QMap<Unit::Flags, QString> behaviorModifierToString {
        { 1 << 0, "static" },
        { 1 << 1, "virtual" },
        { 1 << 2, "const" }};
public:
    enum class AccessModifier {
        Private, Protected, Public };
    enum class BehaviorModifier : Unit::Flags {
        Static = 1 << 0,
        Virtual = 1 << 1,
        Const = 1 << 2 };
};

#endif // CPPMODIFIER_H
