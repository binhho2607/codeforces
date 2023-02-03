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
#define over(x) (x).begin(), (x).end()
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


ll dp(vector<pii> v, int p, pii cur, umap<vector<int>, ll, VectorHasher>& memo){
    // if(p==sz(v) && (cur.a != 0 || cur.b != 0)){
    //     return 0;
    // }
    ll ans = 0;
    if(cur.a == 0 && cur.b == 0 && p != 0){
        ans = 1;
    }
    if(memo.find(vi{p,cur.a,cur.b}) != memo.end()){
        return memo[vi{p,cur.a,cur.b}];
    }
    
    for(int i=p+1;i<sz(v);++i){
        // cout << v[i].a << " " << v[i].b << " " << i << endl;
        ans += dp(v,i,mk(cur.a+v[i].a, cur.b+v[i].b), memo);
    }
    memo[vi{p,cur.a,cur.b}] = ans;
    return ans;
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

    // vector<pii> v{mk(0,0)};
    vector<pii> v;
    for(int i=0; i < t; ++i) { //loops for each case
        int s1, s2;
        cin >> s1 >> s2;
        v.pb(mk(s1, s2));
    }
    // umap<vector<int>, ll, VectorHasher> memo;
    // cout << dp(v, 0, mk(0,0),memo) << endl;

    vector<vector<ll>> dp(801, vector<ll>(801, 0));
    // dp[400][400] = 1;
    // vector<vector<ll>> ndp = dp;
    // for(int i=0;i<sz(dp);++i){
    //     for(int j=0;j<sz(dp);++j){
    //         if(i-v[0].b >= 0 && i-v[0].b < sz(dp) && j-v[0].a >= 0 && j-v[0].a < sz(dp)){
    //             ndp[i][j] += dp[i-v[0].b][j-v[0].a];
    //         }
    //     }
    // }
    // dp = ndp;
    // dp[400][400] = 1;
    for(int k=0;k<sz(v);++k){
        vector<vector<ll>> ndp = dp;
        ndp[400+v[k].b][400+v[k].a] += 1;
        for(int i=0;i<sz(dp);++i){
            for(int j=0;j<sz(dp);++j){
                if(i-v[k].b >= 0 && i-v[k].b < sz(dp) && j-v[k].a >= 0 && j-v[k].a < sz(dp)){
                    ndp[i][j] += dp[i-v[k].b][j-v[k].a];
                }
            }
        }
        dp = ndp;
    }
    cout << dp[400][400] << endl;
    return 0;
}