#include "LanguageConstructionsHeader/Cpp/PrintOperatorUnit.h"

PrintOperatorUnit::PrintOperatorUnit(const QString &text)
    : _text {text} {}

QString PrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf(\"" + _text + "\");\n";
}
