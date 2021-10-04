#include <iostream>
#include <string.h>
using namespace std;
 
 
int main(){
    string s;
    string t;
    cin >> s >> t;
    int cont = 0;
    int s_length= s.length();
    //cout <<s_length;
    if(s==t){
        cout << "Yes";
    }
    else{
        for(int i=0;i<s_length-1;i++){      
           // cout << i;  
            if(s[i]!=t[i]){
                //cout << i;
                //cout <<"yes";
                if(s[i+1]!=t[i+1]){
                    
                    cont++;
                }
            }
        }
        //como maximo 1 par de caracteres conscutivos es diferente
        if(cont==1 ){
            cout <<"Yes";
        }
        else{
            cout <<"No";
        }
    }
 
    return 0;
}











































/*
//ejercicio a
int main(){
    int a,b;
    cin >> a >> b;
    int x=1;
    int aux;
    if (a==b){
        cout << 1;
    }
    else{
        if (a>b){
            aux= a-b;
            for (int i=0;i<aux;i++){
                x=x*32;
            }
            cout << x;
        }
        else{
            aux= b-a;
            for (int i=0;i<aux;i++){
                x=x*32;
            }
            cout << x;
        }
    }


    return 0;
}*/