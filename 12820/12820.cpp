#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

int main(){
    int n,count,a;
    string s;
    bool flag;
    map<char,int> list;
    map<char,int>::iterator iter;
    map<int,int> v;
    map<int,int>::iterator iter_v;

    a = 1;
    while(cin >> n){
        count = 0;
        for(int j=0;j<n;j++){
            cin >> s;
            list.clear();
            v.clear();
            flag = true;

            for(int i=0;i<s.length();i++){
                iter = list.find(s[i]);
                if(iter != list.end()){
                    list[s[i]] +=1;
                }
                else{
                    list[s[i]] = 1;
                }
            }
            for(int i='a';i<='z';i++){
                iter = list.find(i);
                if(iter != list.end()){
                    iter_v = v.find(list[i]);
                    if(iter_v != v.end()){
                        flag = false;
                    }
                    else{
                        v[list[i]] = 1;
                    }
                }    
            }
            if(flag&&v.size()>1){
                count++;
            }
        }
        cout << "Case " << a << ": " << count << endl;
        a++;
    }
    return 0;
}