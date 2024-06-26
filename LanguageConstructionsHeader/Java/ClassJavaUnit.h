#ifndef CLASSJAVAUNIT_H
#define CLASSJAVAUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class ClassJavaUnit : public Unit
{
private:
    QString _name;
    QVector<QVector<QSharedPointer<Unit>>> _accessBlocks;
public:
    ClassJavaUnit(const QString &name);
    ~ClassJavaUnit() override = default;
    void add(const QSharedPointer<Unit> &unit, Flags accessModifier) override;
    QString compile(unsigned int level) const override;
};

#endif // CLASSJAVAUNIT_H
