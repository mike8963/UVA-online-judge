/*
author: Chang Min Wong
B073040050
date: 2021/3/24
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double a,b,c,ans,s,area;
    while(cin >> a >> b >> c){
        if(a==0 || b==0 || c==0){
            ans = 0;
        }
        else{
            s = (a+b+c)/2;
            area = sqrt(s*(s-a)*(s-b)*(s-c));
            ans = area/s;
        }
        cout << "The radius of the round table is: " << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}