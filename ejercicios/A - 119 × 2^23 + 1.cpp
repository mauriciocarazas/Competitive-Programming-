//#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

ll expo = 0;

ll exp_dos(ll x,ll exp){
    while(x>1){
        x=x/2;
        exp++;
    }
    return exp;
}

ll value(ll num,ll b){      //num es el numero ingresado , b es el exponente max del 2
    ll result = num;        //lo inicializo el resultado (suma de a+b+c) para ir guardando el valor mas pequeño que se ingrese(empieza en el max)
    ll temp;                //el valor de 2 ^ b
    ll a;               //a es el multiplicador
    ll c;                   //c es lo que se suma, el resto
    while(b>1){             // vamos a ir reduciendo b hasta 1
        temp= pow(2,b);      //siempre el temp es 2 ^ b
        a = 1;              // siempre que bajemos el exponente(b) hay que reiniciar el a
        while (temp * a < num){     // a*2^b < num ?
            c= num - (temp * a);    // c = num - a*2^b
            if(a+b+c<result){       // resultado se va quedando con el menor valor
                result = a+b+c;
            }
            a++;
        }
        b--;
    }
    return result;

}

int main() {
    ll N;
    cin >>N;
    ll aux = exp_dos(N,expo); //valor del b inicial
    cout << value(N,aux);
    return 0;
}