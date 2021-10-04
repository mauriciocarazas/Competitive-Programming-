#include <iostream>
#include <string>
//#include <bits/stdc++.h>
using namespace std;
/*#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;*/

int main() {

    string c;
    cin >> c;
    int len = c.length();
    //cout <<"este es el len" <<<len<<endl;
    for(int i=0; i<(len/2); i++){
        char temp = c[i];//SWAP
        c[i] = c[len-i-1];
        c[len-i-1] = temp;

        if(c[i]=='6'){
            c[i]='9';
        }
        else if(c[i]=='9'){
            c[i]='6';
        }
        if(c[len-i-1]=='6'){
            c[len-i-1]='9';
        }
        else if(c[len-i-1]=='9'){
            c[len-i-1]='6';
        }
        
    }
    if(len%2==1){
            if(c[len/2]=='6'){
            c[len/2]='9';
            }
        else if(c[len/2]=='9'){
            c[len/2]='6';
        }
    }

    cout << c;



    return 0;
}