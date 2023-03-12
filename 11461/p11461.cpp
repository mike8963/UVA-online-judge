/*
author: Chang Min Wong
B073040050
date: 2021/3/4
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    int a,b,i,n,temp;
    while(cin >> a >> b){
        if(a==0&&b==0){
            break;
        }
        a = ceil(sqrt(a));
        b = floor(sqrt(b));
        cout << b - a + 1 << endl;
    }

    return 0;
}