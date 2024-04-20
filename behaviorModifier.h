#ifndef BEHAVIORMODIFIER_H
#define BEHAVIORMODIFIER_H

#include <QString>

enum class BehaviorModifier : QString {
    Static = "static",
    Virtual = "virtual",
    Abstract = "abstract",
    Const = "const",
    Readonly = "readonly",
    Sealed  = "sealed ",
    Final = "final"
};

#endif // BEHAVIORMODIFIER_H