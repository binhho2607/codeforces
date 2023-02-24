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


void solve(int s){
    cout << s << endl;
}

//bool dp(vi v, umap<pii, bool> memo, int k, int c, vi cur){
//    if(k == sz(v)){
//        // check
//    }
//    if(memo.find(mk(k,c)) != memo.end()){
//        return memo[mk(k,c)];
//    }
//
//    for(int i=k;i<sz(v);++i){
//        int pour = min(v[k], c)
//    }
//}

void generate(vi v, int k, vector<vector<int>>& perm, vi cur, vi taken){
//    cout << k << endl;

    if(k == sz(v)){
//        for(auto t:taken){
//            cout << t << " ";
//        }
//        cout << endl;
//        for(auto t:cur){
//            cout << t << " ";
//        }
//        cout << endl;
        perm.pb(cur);
        return;
    }
    cur[sz(cur)-1] -= v[k];
    cur.pb(v[k]);
    taken.pb(v[k]);
    generate(v, k+1, perm, cur, taken);
    taken.pop_back();
    cur.pop_back();
    cur[sz(cur)-1] += v[k];
    generate(v, k+1, perm, cur, taken);
}

//bool dp(vi v)


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    int n;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin >> t;
    vi v;
    for(int i=0; i < t; ++i) { //loops for each case
        int s;
        cin >> s;
        v.pb(s);
    }
    cin >> n;
//    dp(v, n);
    int ans = imax;
    vector<vi> perm;
    vi cur{v[0]};
    generate(v, 1, perm, cur, vi());

    for(auto p:perm){
        for(auto c:p){
            cout << c << " ";
        }
        cout << endl;
//        cout << p[0] << endl;
        if(n-p[0] < 0) continue;
        vector<int> dp(n-p[0]+1, imax/2);
        dp[0] = 0;
        int pour = 0;
        for(int j=1;j<sz(p);++j){

            auto q = p[j];
//            cout << q << " ";
            if(q == 0) continue;
            vector<int> ndp = dp;

            for(int i=0;i<sz(dp);++i){
//                cout << "wtf " << q << " " << i-q << endl;
                if(i-q >= 0 && dp[i-q] != imax/2){

                    ndp[i] = min(dp[i], dp[i-q]+q);
                }
            }
            dp = ndp;
        }
//        cout << endl;
//        cout << "dp " << endl;
//        for(auto d:dp){
//            cout << d << " ";
//        }
//        cout << endl;
        int prefix = 0;
        for(int i=sz(p)-1;i>=1;--i){
            prefix += p[i];
            pour += prefix;
        }
        ans = min(ans, dp.back()+pour);
    }
    cout << ans << endl;
    return 0;
}