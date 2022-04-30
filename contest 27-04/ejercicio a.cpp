//#include<bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

int main(){

    string s;
    int cases;
    cin >> s;
    cin >> cases;
    int q;
    int a,b,c; // a = pos
    char d;
    int count=0;
    int rep[26];
    while(cases--){
        cin >> q;

        if(q == 1){ //case 1 REPLACE d in s[a]
            //cout <<"entra "<<endl << s<<endl;
            cin >> a >> d;
            a++;
            s[a]=d;
            cout <<"sale "<<endl << s<<endl;
        }
        else{ //case 2 calculate the number of distinct characters in the substring (b,c)
            cin >> b >> c;
            int count=0;
            int aux[26]={};
            for (int i=c;i>b;i--){
                aux[s[i]]++;
            }
            for (int i=c;i>b;i--){
                if(s[i]!=s[i-1]){
                    count++;
                }
            }
    

            cout << count << endl;
            
        }
    }


    return 0;

}
/*dfcbbcfeeedbaea
    dfcbbebeeedcaea 
    123456789112345

    */


