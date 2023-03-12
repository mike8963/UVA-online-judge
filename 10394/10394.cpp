#include <iostream>
#include <cmath>
#include <vector>
#define upperbound 20000000

using namespace std;

bool prime[upperbound + 1];
vector<int> primeList;
vector<int> twinPrimeCenter;

void eratosthenes(){
    // initial
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i<=upperbound;i++){
        prime[i] = true;
    }
    int sqrt_upperbound = sqrt(upperbound);
    for(int i=2;i<=sqrt_upperbound;i++){ // sqrt(20000000) = 4472.14
        if(prime[i]){
            for(int k = upperbound/i, j= i*k; k>=i; k--,j-=i){
                if(prime[k]){
                    prime[j] = false;
                }
            }
        }
    }
}

void buildPrimeList(){
    for(int i=1;i<=upperbound;i++){
        if(prime[i]){
            primeList.push_back(i);
        }
    }
}
void buildTwinPrime(){
    twinPrimeCenter.push_back(-1); // twinPrimeCenter[0] 不用
    for(int i=0;i<primeList.size()-1;i++){
        if(primeList[i+1] - primeList[i] == 2){
            twinPrimeCenter.push_back(primeList[i]+1);
        }
    }
}

int main(){
    int n;
    eratosthenes();
    buildPrimeList();
    buildTwinPrime();
    while(cin >> n){
        cout << "(" << twinPrimeCenter[n]-1 << ", " << twinPrimeCenter[n]+1 << ")" << endl;
    }
    return 0;
}