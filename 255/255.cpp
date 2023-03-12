#include <iostream>

using namespace std;

int state[8][8] = {0};

int main(){
    int Q, K, move_to;
    while(cin >> K >> Q >> move_to){
        if(Q == K){
            cout << "Illegal state" << endl;
        }
        else{
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    state[i][j] = 0;
                }
            }
            
            // queen move
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(i == Q/8){
                        state[i][j] += 2;// queen move
                    }
                    if(j == Q%8){
                        state[i][j] += 2;
                    }
                }
            }
            if( K/8 > 0){
                state[K/8 - 1][K%8] += 1;// king move
            }
            if( K/8 < 7){
                state[K/8 + 1][K%8] += 1;// king move
            }
            if( K%8 > 0){
                state[K/8][K%8 - 1] += 1;// king move
            }
            if( K%8 < 7){
                state[K/8][K%8 + 1] += 1;// king move
            }
            state[Q/8][Q%8] = 12;
            state[K/8][K%8] = 13;
            
            if(K/8 == Q/8){
                if(K > Q){
                    for(int i=0;i<8;i++){
                        if(i > K%8){
                            state[K/8][i] = -1;
                        }
                    }
                }
                else{
                    for(int i=0;i<8;i++){
                        if(i < K%8){
                            state[K/8][i] = -1;
                        }
                    }
                }
            }

            if(K%8 == Q%8){
                if(K > Q){
                    for(int i=0;i<8;i++){
                        if(i > K/8){
                            state[i][K%8] = -1;
                        }
                    }
                }
                else{
                    for(int i=0;i<8;i++){
                        if(i < K/8){
                            state[i][K%8] = -1;
                        }
                    }
                }
            }
            
            if((K == 0 && move_to == 9) || (K == 7 && move_to == 14) || (K == 56 && move_to == 49) || (K == 63 && move_to == 54)){
                cout << "Stop" << endl;
            }
            else if(state[move_to/8][move_to%8] == 3){
                cout << "Move not allowed" << endl;
            }
            else if(state[move_to/8][move_to%8] == 2){
                cout << "Continue" << endl;
            }
            else{
                cout << "Illegal move" << endl;
            }
        }
    }
    return 0;
}