#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while (cin >> s){
        for(int i=0;i<s.length();i++){
            switch (s[i]){
                case 'A':case 'B':case 'C':
                    s[i] = '2';
                    break;
                case 'D':case 'E':case 'F':
                    s[i] = '3';
                    break;
                case 'G':case 'H':case 'I':
                    s[i] = '4';
                    break;
                case 'J':case 'K':case 'L':
                    s[i] = '5';
                    break;
                case 'M':case 'N':case 'O':
                    s[i] = '6';
                    break;
                case 'P':case 'Q':case 'R':case 'S':
                    s[i] = '7';
                    break;
                case 'T':case 'U':case 'V':
                    s[i] = '8';
                    break;
                case 'W':case 'X':case 'Y':case 'Z':
                    s[i] = '9';
                    break;
                default:
                    break;
            }
        }
        cout << s << endl;
    }

    return 0;
}