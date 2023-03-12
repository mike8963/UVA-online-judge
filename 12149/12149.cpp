#include <iostream>

using namespace std;

int main(){
    int n,res;
    while(cin >> n && n != 0){
        res = 0;
        for(int i=1;i<=n;i++){
            res+=i*i;
        }
        cout << res << endl;
    }
    return 0;
}