#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define upperbound 5000001
#define deprimebound 5000001

using namespace std;

bool prime[upperbound] = {0};
vector<int> primeList;
int primeSum[deprimebound] = {0};
int DePrime[deprimebound] = {0};



void eratosthenes(){
    // initial

    memset(prime,1,sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for(int i=2;i<upperbound;i++){ 
        if(prime[i]==true){
            primeSum[i] = i;
            primeList.push_back(i);
        }
        int len = primeList.size();

        for(int j=0;j<len && i*primeList[j]<upperbound; j++){
            prime[i*primeList[j]] = false;
            if(i%primeList[j]==0){
                primeSum[i*primeList[j]] = primeSum[i];
                break;
            }
            else{
                primeSum[i*primeList[j]] = primeSum[i] + primeList[j];
            }
        }

        if(prime[primeSum[i]]==true){
            DePrime[i] = DePrime[i-1]+1;
        }
        else{
            DePrime[i] = DePrime[i-1];
        }
    }
}

int main(){
    int a,b;
    eratosthenes();
    while(cin >> a && a!=0){
        cin >> b;
        cout << DePrime[b] - DePrime[a-1] << endl;
    }
    return 0;
}