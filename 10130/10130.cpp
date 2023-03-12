#include <iostream>
#include <algorithm>

using namespace std;

int P[1001],W[1001],MW[1001],dp[1001][31];


int dp_sol(int N,int G);

int main(){
    int T,N,G;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1;i<=N;i++){
            cin >> P[i] >> W[i];
        }
        cin >> G;
        for(int i=1;i<=G;i++){
            cin >> MW[i];
        }
        cout << dp_sol(N,G) << endl;
    }
    return 0;
}

int dp_sol(int N,int G){
    int sum = 0;

    int maxw = 0;
    for(int i=1;i<=G;i++){
        maxw = max(maxw,MW[i]);
    }
    
    for (int i=0;i<=N;i++){
        for(int j=0;j<=G;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
        
    for (int i=1;i<=N;i++) {
        for (int j=1; j<=maxw;j++){
            if (W[i]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],P[i]+dp[i-1][j-W[i]]);
        }
    }

    for (int p = 1; p <= G; p++)
        sum += dp[N][MW[p]];

    return sum; 
}