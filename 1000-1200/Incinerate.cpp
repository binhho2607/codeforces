

#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


void solve(int n, int k, vector<int> h, vector<int> p){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hq;

    for (int i=0;i<n;++i) {
        hq.push(make_pair(p[i], h[i]));
    }



    int a = 0;
    pair<int, int> d;
    while (k > 0 && hq.size() > 0) {
        a += k;
        while (hq.size() > 0 && hq.top().second-a <= 0) {
            hq.pop();
        }
        if (hq.size() == 0) {
            break;
        }
        d = hq.top();
        k -= d.first;
    }

    if (k > 0 || (k == 0 && hq.size() == 0)) {
        cout << "YES" << endl;
    } else if (k <= 0 && hq.size() > 0) {
        cout << "NO" << endl;
    }

}


int main(void) {
    /* number of test cases */
    unsigned int t;
    unsigned int n;
    unsigned int k;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        cin >> k;
        vector<int> h;
        for (int j=0; j < n; ++j) { // each element of vector
            int s;
            cin >> s;
            h.push_back(s);
        }
        vector<int> p;
        for (int j=0; j < n; ++j) { // each element of vector
            int s;
            cin >> s;
            p.push_back(s);
        }
        solve(n, k, h, p);
    }

    return 0;
}