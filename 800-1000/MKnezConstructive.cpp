

#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve(int n){
    if (n == 3) { 
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n%2 == 0) {
        for (int i=0;i<n;++i){
            cout << pow(-1, i) << " ";
        }
    } else {
        for (int i=0;i<n;++i){
            if (i%2==0) {
                cout << (n-1)/2-1 << " ";
            } else {
                cout << -1*(n-1)/2 << " ";
            }
        }
    }
    cout << endl;
    return;
}


int main(void) {
    /* number of test cases */
    unsigned short int t;
    unsigned short int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; 
        solve(n);
    }

    return 0;
}