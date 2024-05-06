#ifndef CLASSCSUNIT_H
#define CLASSCSUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class ClassCsUnit : public Unit
{
private:
    QString _name;
    QVector<QVector<QSharedPointer<Unit>>> _accessBlocks;
public:
    ClassCsUnit(const QString &name);
    ~ClassCsUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags accessModifier) override;
    QString compile(unsigned int level) const override;
};

#endif // CLASSCSUNIT_H
