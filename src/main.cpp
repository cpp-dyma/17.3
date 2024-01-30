#include <iostream>
#include <stdexcept>
#include <array>
#include "tableau.h"

using std::cout;
using std::endl;


int main(){

    const int taille {5};
    
    Tableau<double, taille> t;

    t[0] = 1.1;
    t[1] = 2.2;
    t[2] = 3.3;
    t[3] = 4.4;
    t[4] = 5.5;

    t.afficher();

    return 0;
}

