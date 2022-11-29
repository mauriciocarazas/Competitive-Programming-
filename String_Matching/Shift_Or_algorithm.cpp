#include <iostream>
#include <string>
#include <map>
using namespace std;
int shift_and(string p, string text) {
    int b = {};
    int l = p.size();
    int tl = text.size();
 
    // init the table
    for (int i = 0; i < l; i++) {
        b[p.at(i)] = 0;
    }

    //build bit mask table;
    for (int i = 0; i < l; i++) {
        b[p.at(i)] = b[p.at(i)] | (1 << i);
    }
 
    int d = 0;
    int matchMask = 1 << l-1;
    for (int i = 0; i < tl; i++) {
        d = ((d << 1) | 1) & (b[text.at(i)] | 0);
        int matched = (d & matchMask);
        if (matched != 0) {
            return i - l + 1;
        }
    }
    return -1;
}

int shift_or(string t, string p) {
   int m = p.length();//length of pattern.
   long pattern_mask[256];//creation of array.
   long R = ~1;

   if (m == 0)
      return -1;//If no pattern has been given.
   if (m >63) {
      cout<<"Pattern is too long!";//if pattern is too long
      return -1;
   }
   for (int i = 0; i <=255; ++i){
      pattern_mask[i] = ~0;//initializing pattern mask array.
   }
   for (int i = 0; i < m; ++i){
      pattern_mask[p[i]] &= ~(1L << i);
   }
   for (int i = 0; i < t.length(); ++i) {
      R |= pattern_mask[t[i]];
      R <<= 1;
      if ((R & (1L << m)) == 0)
         return i - m + 1;
   }
   return -1;
}

void findPattern(string t, string p) {
   int position = shift_or(t, p);//invoking shift_or function.
   if (position == -1)
      cout << "\nNo Match\n";
   else
      //cout << "\nPattern found at position: " << position;
      cout << position;
}

int main() {
   string texto, patron;
    while(getline(cin,texto)){
        getline(cin,patron);
        findPattern(texto,patron);
    }
    return 0;
   
   
   
   /*string t;
   t="you speek a bootiful language";
   string p;
   p="peek a boo";
   findPattern(t, p);*/
}
