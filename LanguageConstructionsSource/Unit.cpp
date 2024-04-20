#include "LanguageConstructionsHeader/Unit.h"

void Unit::add(const QSharedPointer<Unit> &unit, Flags flags)
{
    throw std::runtime_error("Nesting in this component is not supported");
}

QString Unit::generateShift(unsigned int level) const
{
    return QString(4 * level, ' ');
}
