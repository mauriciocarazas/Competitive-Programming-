#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int a,b;
        cin>>a;
        set<int>s;
        while(a--) {
            int b;
            cin>>b;
            s.insert(b);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}