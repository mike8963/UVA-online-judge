#include <iostream>

using namespace std;

long long int fib[100] = {0};


long long int fibonacci(int n){
    if(n == 0){
        fib[n] = 1;
        return 1;
    }
    if(n == 1){
        fib[n] = 1;
        return 1;
    }
    if(fib[n] == 0){
        fib[n] = fibonacci(n-1) + fibonacci(n-2);
        return fib[n];
    }
}

int main(){
    int n;
    fib[0] = 1;
    while(cin >> n && n != 0){
        cout << fibonacci(n) << endl;
    }
    return 0;
}