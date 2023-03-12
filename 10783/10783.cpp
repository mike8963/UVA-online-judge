#include <iostream>

using namespace std;

int main(){
    int n,a,b,result;
    cin >> n;
    for(int i=1;i<=n;i++){
        result = 0;
        cin >> a >> b;
        for(int j=1;j<=b;j+=2){
            if(j>=a){
                result+=j;
            }
        }
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}