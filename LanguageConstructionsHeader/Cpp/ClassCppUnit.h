#ifndef CLASSCPPUNIT_H
#define CLASSCPPUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class ClassCppUnit : public Unit
{
private:
    QString _name;
    QVector<QVector<QSharedPointer<Unit>>> _accessBlocks;
public:
    ClassCppUnit(const QString &name);
    ~ClassCppUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags accessModifier) override;
    QString compile(unsigned int level = 0) const override;
};

#endif // CLASSCPPUNIT_H
