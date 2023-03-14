#include "lib.h"
using namespace std;

//int two_false = 0;

int check_elephant (int x1, int y1, int x2, int y2){
    if ( x1+y1 == x2+y2 || x1-y1 == x2-y2 ){
        cout << "Ўах от слона";
    }
    else return 1;
    return 0;
}

int check_rook (int x1, int y1, int x2, int y2){
    if (x1 == x2 || y1 == y2) {
        cout << "Ўах от ладьи";
    }
    else return 1;
    return 0;
}