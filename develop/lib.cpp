#include <iostream>
using namespace std;

void check_elephant (int x1, y1, x2, y2){
    if ( ads(x1-x2) == abs(y1-y2) ){
        cout << "Шах от слона";
    }
}

void check_rook (int x1, y1, x2, y2){
    if ( x1 == x2 || y1 == y2){
        cout << "Шах от ладьи";
    }
}

int main(){
    return(0);
}