//
// Created by Gal on 04/03/2022.
//

#include <iostream>
#include "mat.hpp"

string ariel::mat(int column, int row, char a, char b) {
    if (column < 0 || row < 0) { // check if the values are not negative
        throw std::invalid_argument("Mat size is always positive");
    }
    if (column % 2 == 0 || row % 2 == 0) { // check if mat is even.
        throw std::invalid_argument("Mat size is always odd");
    }
    if (a == ' ' || b == ' ' || a == '\n' || b == '\n' || a == '\r' || b == '\r' || a == '\t' || b == '\t') { // check spaces value
        throw std::invalid_argument("Mat is always with no spaces");
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