#ifndef METHODCSUNIT_H
#define METHODCSUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class MethodCsUnit : public Unit
{
private:
    QString _name;
    QString _returnType;
    Flags _flags;
    QVector<QSharedPointer<Unit>> units;
public:
    MethodCsUnit(const QString &name, const QString &returnType = "void", Flags flags = 0);
    ~MethodCsUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags flags = 0) override;
    QString compile(unsigned int level = 0) const override;
};

#endif // METHODCSUNIT_H
