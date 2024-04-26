#ifndef PRINTOPERATORCPPUNIT_H
#define PRINTOPERATORCPPUNIT_H

#include "LanguageConstructionsHeader/Unit.h"

class PrintOperatorCppUnit : public Unit
{
private:
    QString _text;
public:
    PrintOperatorCppUnit(const QString &text);
    QString compile(unsigned int level = 0) const override;
};

#endif // PRINTOPERATORCPPUNIT_H
