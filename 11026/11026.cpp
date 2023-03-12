/*
author: Chang Min Wong
B073040050
date: 2021/5/11
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void product(int,int,int**);
int count_product(int,int);

int main(){
    int m,n;
    int **a;
    int *input;
    int *fitness;
    while(true){
        cin >> n >> m;
        if(n==0&&m==0){
            break;
        }
        a = new int*[n+1];// [0][0] 不用 方便記
        input = new int[n+1]{0}; //[0] 不用
        
        for(int i=1;i<=n;i++){
            a[i] = new int[i+1]{0}; // [i][0] 都不用
        }

        for(int i=1;i<=n;i++){
            cin >> input[i];
        }

        // count product and record in **a
        for(int i=1;i<=n;i++){
            for(int k=1;k<=i;k++){
                if(i==1){
                    a[i][k] = input[i];
                }
                else if(k == 1){
                    a[i][k] = a[i-1][1]+input[i];
                }
                else if(i>k){
                    a[i][k] = a[i-1][k];
                    for(int j=0;j<input[i];j++){
                        if(a[i][k] + a[i-1][k-1] < 0){
                            a[i][k] -= 2147483647;
                        }
                        a[i][k] += a[i-1][k-1];
                    }    
                }
                else{
                    for(int j=0;j<input[i];j++){
                        if(a[i][k] + a[i-1][i-1] < 0){ // overflow
                            a[i][k] -= 2147483647;
                        }
                        a[i][k] += a[i-1][i-1];
                    }
                }
                a[i][k] = a[i][k]%m; // mod
            }
        }

        fitness = new int[n+1]{0};
        for(int i=1;i<=n;i++){
            fitness[i] = a[n][i];
        }

        sort(fitness,fitness+n+1);
        cout << fitness[n] << endl;

        delete [] input;
        delete [] fitness;

        for(int i=1;i<=n;i++){
            delete [] a[i];
        }
        delete [] a;
    }
    return 0;
}

