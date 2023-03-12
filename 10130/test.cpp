#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int MW[50];
    for(int i=0;i<30;i++){
        MW[i] = i;
    }
    int maxw = *max_element(MW+1,MW+1+30);
    cout << maxw;
    return 0;
}