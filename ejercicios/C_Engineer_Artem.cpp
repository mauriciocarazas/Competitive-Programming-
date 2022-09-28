#include <iostream>
using namespace std;

int main(){
	int T;  
    cin>>T;
	while(T--){     // number of cases
		int n, m;  
        cin>>n>>m; // n - number of rows, m - number of columns
		for(int i = 1; i <= n; i++){ // (i,j), either bi,j=ai,j or bi,j=ai,j+1.
			for(int j = 1; j <= m; j++){
				int x;  cin>>x;
				if((i+j)%2==0 && x%2==0){
                    x++;
                }
				if((i+j)%2==1 && x%2==1){
                    x++;
                }   
				cout<<x<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}