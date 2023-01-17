

#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void solve(unsigned long n, vector<vector<long>> b){
    // long c[200001] = {0};
    unordered_map<long, long> c;
    for(long i=0;i<n;++i){
        for(long j=0;j<b[i].size();++j){
            // c[b[i][j]] += 1;
            if (c.find(b[i][j]) == c.end()){
                c.emplace(b[i][j],1);
            }else{
                c[b[i][j]] += 1;
            }
        }
    }

    for(long i=0;i<n;++i){
        bool f = true;
        for(long j=0;j<b[i].size();++j){
            if(c[b[i][j]] <= 1) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
    return;
}


int main(void) {
    /* number of test cases */
    unsigned long t;
    unsigned long n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;
    for(long i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        vector<vector<long>> b;
        for (long j=0; j < n; ++j) { // each element of vector
            long s;
            cin >> s;
            b.push_back(vector<long>());
            for(long k=0;k<s;++k){
                long c;
                cin >> c;
                b[b.size()-1].push_back(c);
            }
        }
        
        solve(n, b);
    }


    return 0;
}