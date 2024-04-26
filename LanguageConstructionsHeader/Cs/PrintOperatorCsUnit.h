#ifndef PRINTOPERATORCSUNIT_H
#define PRINTOPERATORCSUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class PrintOperatorCsUnit : public Unit
{
private:
    QString _text;
public:
    PrintOperatorCsUnit(const QString &text);
    QString compile(unsigned int level = 0) const override;
};

#endif // PRINTOPERATORCSUNIT_H
