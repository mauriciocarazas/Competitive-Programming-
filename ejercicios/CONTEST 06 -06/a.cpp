        #include <iostream>
        using namespace std;
        //#include <atcoder/all>
        //using namespace atcoder;
        #define rep(i,n) for (int i = 0; i < (n); ++i)
        using ll = long long;
        using P = pair<int,int>;

        int main() {

            //0 for rock, 1 for scissors, or 2 for paper.
            //Serval, Fennec, and Raccoon 
            //x , y es Fennec and Raccoon
            //siempre es empate

            int x,y;
            cin >> x >> y;

            if(x==y){
                cout << x;
            }
            else{
                if(x==0){
                    if(y==1){
                        cout << 2;
                    }
                    else{
                        cout<<1;
                    }
                }
                if (x==1){
                    if(y==0){
                        cout << 2;
                    }
                    else{
                        cout<<0;
                    }
                    
                }
                if (x==2){
                    if(y==0){
                        cout << 1;
                    }
                    else{
                        cout<<0;
                    }
                    
                }
            }

        return 0;
        }