//
// Created by Gal on 04/03/2022.
//

#include <iostream>
#include "mat.hpp"

using namespace std;
string ariel::mat(int column, int row, char a, char b) {
    const int ascii_ = 33;
    const int ascii = 126;
    if (column < 1 || row < 1) { // check if the values are not negative
        throw invalid_argument("Mat size is always positive");
    }
    if (column % 2 == 0 || row % 2 == 0) { // check if mat is even.
        throw invalid_argument("Mat size is always odd");
    }
    if (!((a >=ascii_ && a <=ascii) && (b >= ascii_ && b <=ascii))) { // check spaces value
        throw invalid_argument("the char is over the boundary of ascii");
    }
    string matrix;
    int iterator = 0;
    int i = 0;
    int j = 0;
    while(i < row){
        iterator = min(min(i, j), min(row-1-i, column-1-j)) % 2; // take the minimum from the index i,j and from the transpose matrix.
        if(iterator == 0){ matrix += a;} // if the iterator after %2 is = 0 them add the symbol "a" to the string
        else{ matrix += b;}
        if (j == column - 1){
            j = 0;
            i++;
            if(i != row) { // the last end line space
                matrix += '\n';
            }
            continue;
        }
        j++;
    }
    return matrix;
}