#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
// #define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007



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

struct node {
    int val;
    node* next;
    node* prev;
};

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct PairHasher{
  size_t operator()(const pii &x) const{
    return x.first ^ x.second;
  }
};


void solve(vi h, vi b){
    vi dp1, dp2;
    dp1.resize(pow(10,5)+1, imax);
    dp2.resize(pow(10,5)+1, imax);
    dp1[0] = 0;
    dp2[0] = 0;
    for(auto p:h){
        vi ndp1 = dp1;

        for(int i=1;i<sz(dp1);++i){
            if(i-p >= 0 && dp1[i-p] != imax){
                ndp1[i] = min(dp1[i], dp1[i-p]+1);
            }
        }
        dp1 = ndp1;
    }
    for(auto p:b){
        vi ndp2 = dp2;
        // ndp2.resize(pow(10,5)+1, imax);
        // ndp2[0] = 0;
        for(int i=1;i<sz(dp2);++i){
            if(i-p >= 0 && dp2[i-p] != imax){
                ndp2[i] = min(dp2[i], dp2[i-p]+1);
            }
        }
        dp2 = ndp2;
    }

    int ans = imax;

    for(int i=1;i<sz(dp1);++i){
        if(dp1[i] != imax && dp2[i] != imax){
            ans = min(ans, dp1[i]+dp2[i]);
        }
    }

    if(ans == imax){
        cout << "impossible" << endl;
    }else{
        cout << ans << endl;
    }

    return;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    unsigned int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    vi h;
    vi b;
    for(int i=0; i < t; ++i) { //loops for each case
        int s;
        cin >> s;
        h.pb(s);
    }

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        int s;
        cin >> s;
        b.pb(s);
    }

    solve(h, b);

    return 0;
}