#include <iostream>

using namespace std;

int main(){
    int n,x;
    while(cin>>n && n!=0){
        for(int i=1;i<n;i++){
            x = 0; // initial
            for(int j=1;j<n;j++){
                x = (x+i)%j;
            }
            if(x == 11){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}