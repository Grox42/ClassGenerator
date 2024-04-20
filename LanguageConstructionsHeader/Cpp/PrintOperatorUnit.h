#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class PrintOperatorUnit : public Unit
{
private:
    QString _text;
public:
    PrintOperatorUnit(const QString &text);
    QString compile(unsigned int level = 0) const override;
};

#endif // PRINTOPERATORUNIT_H
