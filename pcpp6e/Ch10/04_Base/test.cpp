#include "Derived.h"

int main (void) {
    Base b;
    Derived d;
    b.someFunction();
    d.someFunction();
    b.someOtherFunction();
    d.someOtherFunction();
}
