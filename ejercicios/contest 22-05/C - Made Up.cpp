//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
/*#include <atcoder/all>
using namespace atcoder;

using ll = long long;
using P = pair<int,int>;*/

int main() {
  int n;
  cin >> n;
  int aux;
  int A[n];
  rep(i,n){
      cin >> aux;
      A[i]=aux;
  }
  int B[n];
  rep(i,n){
      cin >> aux;
      B[i]=aux;
  }
  int C[n];
  rep(i,n){
      cin >> aux;
      C[i]=aux;
  }
    int cont=0;
  for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
          if(A[i-1]==B[C[j-1]-1]){
              cont++;
          }
      }
  }
  cout << cont;
  return 0;
  
  
  
  return 0;
}