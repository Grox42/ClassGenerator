#include "LanguageConstructionsHeader/Cs/PrintOperatorCsUnit.h"

PrintOperatorCsUnit::PrintOperatorCsUnit(const QString &text)
    : _text {text} {}

QString PrintOperatorCsUnit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.Write(\"" + _text + "\");\n";
}
