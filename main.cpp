#include "RPNCalc.h"

int main(int argc, char** argv)
{
    RPNCalc *test = new RPNCalc();
    test->prompt();
    test->createStack();
    test->calculate();

    return 0;
}