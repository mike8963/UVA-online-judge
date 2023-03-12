#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> y;
    vector<int> x;
    vector<int> result4;
    vector<int> result6;
    vector<int> result8;
    vector<int>::iterator iter;
    
    int n;

    result4.clear();
    result6.clear();
    result8.clear();

    /*
    
    i*j = n
     x    y
    
    */

    // result 4
    for(int i=10;i<100;i++){
        for(int j=10;j<100;j+=2){
            if(!((i%10 == 0)&&(j%10 == 0))){
                n = i*j;
                if(n>=1000){
                    x.clear();
                    y.clear();
                    x.push_back(i%10);
                    x.push_back(i/10);
                    
                    x.push_back(j%10);
                    x.push_back(j/10);
                                        
                    y.push_back(n%10);
                    y.push_back((n/10)%10);
                    y.push_back((n/100)%10);
                    y.push_back(n/1000);
                    
                    std::sort(x.begin(),x.begin()+x.size());
                    std::sort(y.begin(),y.begin()+y.size());
                    
                    if(x == y){
                        iter = find(result4.begin(),result4.end(),n);
                        if(iter == result4.end()){
                            result4.push_back(n);
                        }
                    }
                }
            }    
        }
    }

    //result 6

    for(int i=100;i<1000;i++){
        for(int j=100;j<1000;j+=2){
            if(!((i%10 == 0)&&(j%10 == 0))){
                n = i*j;
                if(n>=100000){
                    x.clear();
                    y.clear();

                    x.push_back(i%10);
                    x.push_back((i/10)%10);
                    x.push_back(i/100);

                    x.push_back(j%10);
                    x.push_back((j/10)%10);
                    x.push_back(j/100);

                    
                    y.push_back(n%10);
                    y.push_back((n/10)%10);
                    y.push_back((n/100)%10);
                    y.push_back((n/1000)%10);
                    y.push_back((n/10000)%10);
                    y.push_back(n/100000);

                    std::sort(x.begin(),x.begin()+x.size());
                    std::sort(y.begin(),y.begin()+y.size());
                    
                    if(x == y){
                        iter = find(result6.begin(),result6.end(),n);
                        if(iter == result6.end()){
                            result6.push_back(n);
                        }
                    }
                }
            }    
        }
    }

    //result 8

    for(int i=1000;i<10000;i++){
        for(int j=1000;j<10000;j+=2){
            if(!((i%10 == 0)&&(j%10 == 0))){
                n = i*j;
                if(n>=10000000){
                    x.clear();
                    y.clear();

                    x.push_back(i%10);
                    x.push_back((i/10)%10);
                    x.push_back((i/100)%10);
                    x.push_back(i/1000);

                    x.push_back(j%10);
                    x.push_back((j/10)%10);
                    x.push_back((j/100)%10);
                    x.push_back(j/1000);

                    
                    y.push_back(n%10);
                    y.push_back((n/10)%10);
                    y.push_back((n/100)%10);
                    y.push_back((n/1000)%10);
                    y.push_back((n/10000)%10);
                    y.push_back((n/100000)%10);
                    y.push_back((n/1000000)%10);
                    y.push_back(n/10000000);

                    std::sort(x.begin(),x.begin()+x.size());
                    std::sort(y.begin(),y.begin()+y.size());
                    
                    if(x == y){
                        iter = find(result8.begin(),result8.end(),n);
                        if(iter == result8.end()){
                            result8.push_back(n);
                        }
                    }
                }
            }    
        }
    }

    std::sort(result4.begin(),result4.begin()+result4.size());
    std::sort(result6.begin(),result6.begin()+result6.size());
    std::sort(result8.begin(),result8.begin()+result8.size());
    
    while(cin >> n){
        switch (n)
        {
        case 4:
            for(int i:result4){
                cout << i << endl;
            }
            break;
        case 6:
            for(int i:result6){
                cout << i << endl;
            }
            break;
        case 8:
            for(int i:result8){
                cout << i << endl;
            }
            break;
        default:
            break;
        }
        cout << endl;
    }
    
    return 0;
}