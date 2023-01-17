

#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void solve(int n){
    int c = 0;
    vector<vector<int>> matrix(n, vector<int>(n, 0));


    for(int i=0;i<(n+1)/2;++i){
        for (int j=i;j<n-i;++j){
            if (c%2 == 0) {
                matrix[i][j] = c/2+1;
            } else {
                matrix[i][j] = pow(n,2)-(c/2);
            }
            c += 1;
        }

        for (int j=i+1;j<n-i;++j) {
            if (c%2 == 0) {
                matrix[j][n-i-1] = c/2+1;
            } else {
                matrix[j][n-i-1] = pow(n,2)-(c/2);
            }
            c += 1;
        }

        for (int j=n-i-2;j>i-1;--j){
            if (c%2 == 0) {
                matrix[n-i-1][j] = c/2+1;
            } else {
                matrix[n-i-1][j] = pow(n,2)-(c/2);
            }
            c += 1;
        }

        for (int j=n-i-2;j>i;--j) {
            if (c%2 == 0) {
                matrix[j][i] = c/2+1;
            } else {
                matrix[j][i] = pow(n,2)-(c/2);
            }
            c += 1;
        }
    }

    for (int i=0;i<n;++i) {
        for(int j=0;j<n;++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
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
        cin >> n; // number of elements in vector
        solve(n);
    }

    return 0;
}