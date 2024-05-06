#ifndef CSMODIFIER_H
#define CSMODIFIER_H

#include "LanguageConstructionsHeader/Unit.h"
#include <QVector>
#include <QMap>

namespace CsModifier
{
    /*extern*/ const QVector<QString> accessModifierToString {
        "private", "private protected", "protected",
        "internal", "protected internal", "public" };
    /*extern*/ const QMap<Unit::Flags, QString> behaviorModifierToString {
        { 1 << 0, "static" },
        { 1 << 1, "virtual" },
        /*{ 1 << 2, "abstract" }*/};
    enum AccessModifier {
        Private, PrivateProtected, Protected,
        Internal, ProtectedInternal, Public };
    enum BehaviorModifier : Unit::Flags {
        Static = 1 << 0,
        Virtual = 1 << 1,
        /*Abstract = 1 << 2*/ };
}

#endif // CSMODIFIER_H
