#include "LanguageConstructionsHeader/Cpp/ClassCppUnit.h"

ClassCppUnit::ClassCppUnit(const QString &name)
    : _name {name} {}

void ClassCppUnit::add(const QSharedPointer<Unit> &unit, Flags accessModifier)
{
    if (accessModifier >= static_cast<Flags>(accessModifierToString.size()))
        throw std::runtime_error("the access modifier does not exist");

    accessBlocks[accessModifier].append(unit);
}

QString ClassCppUnit::compile(unsigned int level) const
{
    QString result {generateShift(level) + "class" + _name + " {\n"};
    for (int i {0}; i < accessModifierToString.size(); i++) {
        if (accessBlocks[i].empty()) continue;
        result += generateShift(level) + accessModifierToString[i] + ":\n";
        for (const QSharedPointer<Unit> &unit : accessBlocks[i])
            result += unit->compile(level + 1);
        result += '\n';
    }
    result += generateShift(level) + "};\n";
    return result;
}
