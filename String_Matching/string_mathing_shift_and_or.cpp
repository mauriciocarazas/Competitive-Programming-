#include<iostream>
#include<string>

using namespace std;
int main(){
    string str1,str2;
    int cnt[100000];
    //cin>>str1;
    while(getline(cin,str1)){
        getline(cin,str2);
        int pos=0,x=0;
        while(str2.find(str1,x)!=-1&&x<str2.size()){
            cnt[pos++]=str2.find(str1,x);
            x=cnt[pos-1]+1;
        }
        for(int i=0;i<pos;i++){
            printf("%d%c",cnt[i],i==pos-1?'\n':' ');
        }
    }
    return 0;
}