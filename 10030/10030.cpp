/*

author: Chang Min Wong
B073040050
date:2021/4/20

*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef struct{
    string fullname;
    string name;
    string extension;
    bool is_candidate;
}FILELIST;

int main(){
    int N,M,testcase,count;
    map<string,int> map_name;
    map<string,int> map_extension;
    map<string,int>::iterator iter;
    string input_file;
    
    // test data num
    cin >> testcase;
    
    for(int k=1;k<=testcase;k++){
        // map 初始化
        
        map_name.clear();
        map_extension.clear();

        // 讀檔，建表
        
        cin >> N >> M;
        
        FILELIST list[N];

        for(int i=0;i<N;i++){
            cin >> input_file;
            list[i].fullname = input_file;
            
            bool extension_flag = 0;
            // 檔名分割儲存
            for(int j=0;j<list[i].fullname.length();j++){
                // 偵測有無副檔名
                
                // 有副檔名
                if(list[i].fullname[j] == '.' && j != list[i].fullname.length() -1 ){
                    extension_flag = 1;
                    list[i].name = list[i].fullname.substr(0,j);
                    list[i].extension = list[i].fullname.substr(j+1);
                    break;
                }
            }
            
            // 沒有副檔名
            if(!extension_flag){
                if(list[i].fullname[list[i].fullname.length()-1] == '.'){
                    list[i].name = list[i].fullname.substr(0,list[i].fullname.length() -1);
                }
                else{
                    list[i].name = list[i].fullname.substr(0);
                }     
                list[i].extension = " ";
            }

            // 檔名/副檔名分別加入map建表
            iter = map_name.find(list[i].name);
            // 檔名還未加入map
            if(iter == map_name.end()){
                map_name[list[i].name] = 1;
            }
            else{   // 檔名已在map中
                map_name[list[i].name] += 1;
            }

            iter = map_extension.find(list[i].extension);
            // 副檔名還未加入map
            if(iter == map_extension.end()){
                map_extension[list[i].extension] = 1;
            }
            else{   // 副檔名已在map中
                map_extension[list[i].extension] += 1;
            }

            // 初始化 bool = 1
            list[i].is_candidate = 1;
        }
        count = N;
        for (int i=0;i<M;i++){
            // 都從 extension 部分開始 => i%2 == 0 做extension部分
            for(int j=0;j<N;j++){
                if(list[j].is_candidate){
                    if(i%2 == 0){
                        // extension part
                        
                        // 有這個副檔名的data只有一筆 => 去除
                        if(map_extension[list[j].extension] == 1){
                            list[j].is_candidate = 0;
                            if(map_name[list[j].name] > 1){
                                map_name[list[j].name] --;
                            }
                            count --;
                        }        
                    }
                    else{
                        // name part

                        // 有這個檔名的data只有一筆 => 去除
                        if(map_name[list[j].name] == 1){
                            list[j].is_candidate = 0;
                            if(map_extension[list[j].extension] > 1){
                                map_extension[list[j].extension] --;
                            }
                            count --;
                        }
                    }    
                }
            }
        }

        cout << count << endl;
        if(count>0){
            for(int i=0;i<N;i++){
                if(list[i].is_candidate){
                    cout << list[i].fullname << endl;
                }
            }
        }
        // 麻煩的格式 搞人 最後一行不吃空白還給我presentation error
        if(k != testcase){
            cout << endl;
        } 
    }
   
    return 0;
}