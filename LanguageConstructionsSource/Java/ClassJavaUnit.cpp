#include "LanguageConstructionsHeader/Java/ClassJavaUnit.h"
#include "LanguageConstructionsHeader/Java/JavaModifiers.h"

using namespace JavaModifier;

ClassJavaUnit::ClassJavaUnit(const QString &name)
    : _name {name}
{
    _accessBlocks = QVector<QVector<QSharedPointer<Unit>>>(accessModifierToString.size());
}

void ClassJavaUnit::add(const QSharedPointer<Unit> &unit, Flags accessModifier)
{
    if (accessModifier >= static_cast<Flags>(accessModifierToString.size()))
        throw std::runtime_error("the access modifier does not exist");

    _accessBlocks[accessModifier].append(unit);
}

QString ClassJavaUnit::compile(unsigned int level) const
{
    QString result {generateShift(level) + "class " + _name + " {\n"};

    for (int i {0}; i < accessModifierToString.size(); i++) {
        if (_accessBlocks[i].empty()) continue;
        for (const QSharedPointer<Unit> &unit : _accessBlocks[i])
            result += generateShift(level + 1) + accessModifierToString[i] + ' ' + unit->compile(level + 1);
        result += '\n';
    }

    result += generateShift(level) + "}\n";
    return result;
}
