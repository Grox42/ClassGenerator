#ifndef METHODJAVAUNIT_H
#define METHODJAVAUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class MethodJavaUnit : public Unit
{
private:
    QString _name;
    QString _returnType;
    Flags _flags;
    QVector<QSharedPointer<Unit>> units;
public:
    MethodJavaUnit(const QString &name, const QString &returnType = "void", Flags flags = 0);
    ~MethodJavaUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags flags = 0) override;
    QString compile(unsigned int level = 0) const override;
};

#endif // METHODJAVAUNIT_H
