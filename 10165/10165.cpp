#include <iostream>

using namespace std;

int main(){
    int n,in,ans;
    while(cin >> n && n){
        ans = 0;
        for(int i=0;i<n;i++){
            cin >> in;
            ans^=in;
        }
        cout << (ans ? "Yes\n" : "No\n" );
    }

    return 0;
}
