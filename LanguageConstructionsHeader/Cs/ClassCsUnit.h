#ifndef CLASSCSUNIT_H
#define CLASSCSUNIT_H

#include "LanguageConstructionsHeader/Unit.h"
#include "LanguageConstructionsHeader/Cs/CsModifier.h"

class ClassCsUnit : public Unit, public CsModifier
{
private:
    QString _name;
    QVector<QVector<QSharedPointer<Unit>>> accessBlocks;
public:
    ClassCsUnit(const QString &name);
    ~ClassCsUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags accessModifier) override;
    QString compile(unsigned int level) const override;
};

#endif // CLASSCSUNIT_H
