  
#include <iostream>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;// nro de arboles
    cin >>n;
    int a;//nro de nueces
    int cont=0;// las que se come
    for (int i=0;i<n;i++){
        cin >> a;
        if(a > 10){
            cont = cont + (a-10);
        }
    }
    cout << cont;


  return 0;
}