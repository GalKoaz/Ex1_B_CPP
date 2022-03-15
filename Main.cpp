#include <iostream>
#include "mat.hpp"
using namespace std;

int main() {
    char symbol_1, symbol_2;
    int COL, ROW;

    cout << "Enter COL ROW SYMBOL_1 SYMBOL_2 by this order: ";
    cin >> COL >> ROW >> symbol_1 >> symbol_2;
    cout << ariel::mat(COL, ROW, symbol_1, symbol_2);

    return 0;
}
