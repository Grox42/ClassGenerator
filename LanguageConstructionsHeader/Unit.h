#ifndef UNIT_H
#define UNIT_H

#include <QSharedPointer>
#include <QString>

class Unit
{
protected:
    virtual QString generateShift(unsigned int level) const;
public:
    using Flags = unsigned int;

    virtual ~Unit() = default;
    virtual void add(const QSharedPointer<Unit> &unit, Flags flags = 0);
    virtual QString compile(unsigned int level = 0) const = 0;
};

#endif // UNIT_H
