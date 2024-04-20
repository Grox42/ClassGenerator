#include "LanguageConstructionsHeader/Cs/ClassCsUnit.h"

ClassCsUnit::ClassCsUnit(const QString &name)
    : _name {name} {}

void ClassCsUnit::add(const QSharedPointer<Unit> &unit, Flags accessModifier)
{
    if (accessModifier >= static_cast<Flags>(accessModifierToString.size()))
        throw std::runtime_error("the access modifier does not exist");

    accessBlocks[accessModifier].append(unit);
}

QString ClassCsUnit::compile(unsigned int level) const
{
    QString result {generateShift(level) + "class" + _name + " {\n"};
    //
    return result;
}
