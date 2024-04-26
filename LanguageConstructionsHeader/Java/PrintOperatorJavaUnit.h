#ifndef PRINTOPERATORJAVAUNIT_H
#define PRINTOPERATORJAVAUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class PrintOperatorJavaUnit : public Unit
{
private:
    QString _text;
public:
    PrintOperatorJavaUnit(const QString &text);
    QString compile(unsigned int level = 0) const override;
};

#endif // PRINTOPERATORJAVAUNIT_H
