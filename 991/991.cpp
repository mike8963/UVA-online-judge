/*
author: Chang Min Wong
B073040050
date: 2021/5/6
*/


#include <iostream>

using namespace std;

int arr[11] = {0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int count(int);

int main(){
    int n;
    bool flag = false;
    for(int i=1;i<11;i++){
        arr[i] = count(i);
    }
    cin >> n;
    do{
        if(flag){
            cout << endl;
        }
        else{
            flag = true;
        }
        cout << arr[n] << endl;
    }while(cin >> n);

    return 0;
}

int count(int n){
    int total = 0;
    if(n==1){ // 2 people
        return 1;
    }
    else{
        if(arr[n]!=-1){
            return arr[n];
        }
        else{
            for(int i=0;i<n;i++){
                if(i==0||i==n-1){
                    total+= count(n-1);
                }
                else{
                    total+= count(i)*count(n-i-1);
                }
            }
            return total;
        }
    }
}