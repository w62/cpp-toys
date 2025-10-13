#pragma once
#include "Base.h"

class Derived: public Base {
    public:
        void someFunction() override;
        void someOtherFunction();
};
