#include <iostream>
using namespace std;
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int temp = c;
    int t = 1;
    int i = 1;
    while (t == 1) {
        c = temp * i;
        if ((c > a || c==a) && (c < b || c==b)) {
            cout << c;
            t = 0;
        }
        else {
            if (c > b) {
                t = 2;
            }
        }
        i = i + 1;
    }
    if (t == 2) { cout << -1; }
 
    return 0;
}