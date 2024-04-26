#ifndef METHODCPPUNIT_H
#define METHODCPPUNIT_H

#include "LanguageConstructionsHeader/Unit.h"
#include "LanguageConstructionsHeader/Cpp/CppModifier.h"

class MethodCppUnit : public Unit, public CppModifier
{
private:
    QString _name;
    QString _returnType;
    Flags _flags;
    QVector<QSharedPointer<Unit>> units;
public:
    MethodCppUnit(const QString &name, const QString &returnType = "void", Flags flags = 0);
    ~MethodCppUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags flags = 0) override;
    QString compile(unsigned int level = 0) const override;
};

#endif // METHODCPPUNIT_H
