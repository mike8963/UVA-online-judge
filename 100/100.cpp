/*
author: Chang Min Wong
B073040050
date:2021/3/4

*/
#include <iostream>
#include <cstdlib>

using namespace std;


int main(){
    int a,b,n,max,temp;
    while(cin >> a >> b){
        max = 1;
        cout << a << " " << b << " ";
        if(b < a){
            temp = a;
            a = b;
            b = temp;
        }
        for(int i=a;i<=b;i++){
            temp = i;
            n = 1;
            while(temp != 1){
                if(temp%2 == 0){
                    temp = temp/2;
                }
                else{
                    temp = temp*3 + 1;
                }
                n+=1;
            }
            if(n>=max){
                max = n;
            }
        }
        cout << max <<endl; 
    }


    return 0;
}