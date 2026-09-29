#include "menu.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    Menu m;
    m.executar();

    return 0;
}
