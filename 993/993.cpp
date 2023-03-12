/*

author: Chang Min Wong
B073040050
date:2021/5/7

*/


#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int,vector<int>> list;
map<int,vector<int>>::iterator iter;
vector<int> divided_num;
int index;
void find_num(int);

int main(){
    int n,m,result;
    bool d_flag; // check if it can be divided
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> n;
        divided_num.clear();
        index = n;
        find_num(n);
    }
    return 0;
}

void find_num(int n){
    int max_divided = 1;
    iter = list.find(n);
    if(n == 0){
        cout << 0 << endl;
    }
    else if(iter != list.end()){
        if(iter->second[0] == -1){
            cout << -1 << endl;
            divided_num.clear();
            divided_num.push_back(-1);
            list[index] = divided_num;
        }
        else{
            if(divided_num.empty()){ 
                for(int i=0;i<iter->second.size();i++){
                    cout << iter->second[i];
                }
                cout << endl;
            }
            else{
                for(int i=0;i<iter->second.size();i++){
                    divided_num.push_back(iter->second[i]);
                }
                sort(divided_num.begin(),divided_num.end());
                for(int i=0;i<divided_num.size();i++){
                    cout << divided_num[i];
                }
                cout << endl;
                list[index] = divided_num;
            }
        }
    }
    else if(n < 10){
        if(divided_num.empty()){// the first n which entry find_num() is < 10 
            cout << n << endl;
            divided_num.push_back(n);
            list[index] = divided_num;
        }
        else{
            divided_num.push_back(n);
            sort(divided_num.begin(),divided_num.end());
            for(int i=0;i<divided_num.size();i++){
                cout << divided_num[i];
            }
            cout << endl;
            list[index] = divided_num;
        }
    }
    else{
        for(int i=2;i<=9;i++){ // try to divide 2~9
            if(n%i==0){
                max_divided = i;
            }
        }
        if(max_divided==1){
            cout << -1 << endl;
            divided_num.clear();
            divided_num.push_back(-1);
            list[index] = divided_num;
        }
        else{
            divided_num.push_back(max_divided);
            find_num(n/max_divided);
        } 
    }
}