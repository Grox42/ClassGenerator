#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "LanguageConstructionsHeader/Unit.h"
#include "LanguageConstructionsHeader/Cpp/CppModifier.h"

class MethodUnit : public Unit, public CppModifier
{
private:
    QString _name;
    QString _returnType;
    Flags _flags;
    QVector<QSharedPointer<Unit>> units;
public:
    MethodUnit(const QString &name, const QString &returnType = "void", Flags flags = 0);
    ~MethodUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags flags = 0) override;
    QString compile(unsigned int level = 0) const override;
};

#endif // METHODUNIT_H
