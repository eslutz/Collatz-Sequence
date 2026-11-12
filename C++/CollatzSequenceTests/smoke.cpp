#include "Collatz.h"
#include <stdexcept>
int main() {
    if (Collatz("5").getSequenceLength() != 6) return 1;
    if (Collatz("5000000000000000000000000000000000000").getSequenceLength() != 653) return 2;
    try { Collatz invalid("-1"); return 3; } catch (const std::invalid_argument&) {}
    return 0;
}
