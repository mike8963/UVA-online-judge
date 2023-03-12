#include <iostream>

using namespace std;


int main(){
    unsigned long long x,n,m;
    unsigned long long result;
    cin >> x;
    for(int i=0;i<x;i++){
        cin >> n >> m;
        result = (m - 1 + m - n) * n / 2;
        cout << result << endl;
    }


    return 0;
}