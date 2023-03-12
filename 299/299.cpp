#include <iostream>

using namespace std;



int main(){
    int c,n,count,temp;
    int arr[100];
    cin >> c;
    while(c--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        count = 0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    count ++;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps." << endl;
    }
    return 0;
}