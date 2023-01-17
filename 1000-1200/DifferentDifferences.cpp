

#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve(int n1, int n2){
    int dif = 1;
    int cur = 1;
    while (n1 > 0) {
        cout << cur << " ";
        if (cur + dif <= n2 && cur + dif + n1 - 2 <= n2) {
            cur += dif;
            dif += 1;
        } else {
            cur += 1;
        }
        n1 -= 1;
    }
    cout << endl;
}


int main(void) {
    /* number of test cases */
    unsigned short int t;
    unsigned short int n1;
    unsigned short int n2;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n1; 
        cin >> n2;
        solve(n1, n2);
        
    }

    return 0;
}