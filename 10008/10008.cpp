#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<char,int> Pair;

bool compare_p1(const Pair &p1,const Pair &p2){
    return int(p1.first) > int(p2.first);
}

bool compare_p2(const Pair &p1,const Pair &p2){
    return p1.second < p2.second;
}

int main(){
    int n;
    map<char,int> list;
    vector<Pair> v;
    string s;
    for(int i=65;i<91;i++){
        list[i] = 0;
    }
    cin >> n;
    string str="\n";
    getline(cin,str);

    for(int i=0;i<n;i++){
        getline(cin,s);
        for(int j=0;j<s.length();j++){
            if(s[j] >= 65 && s[j] <= 90){
                list[s[j]] ++;
            }
            else if(s[j] >= 97 && s[j] <= 122){
                list[s[j] - 32] ++;
            }
        }
    }
    
    for(auto i = list.begin(); i != list.end(); i++){
        if(i->second != 0){
            v.push_back(make_pair(i->first,i->second));
        }    
    }
    sort(v.begin(),v.end(),compare_p1);
    sort(v.begin(),v.end(),compare_p2);
    reverse(v.begin(),v.end());

    for(auto i = v.begin();i != v.end(); i++){
        cout << i->first << " " << i->second << endl;
    }

    return 0;
}