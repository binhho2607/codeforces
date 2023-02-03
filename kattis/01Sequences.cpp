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

umap<ll, ll> mp;

ll fact(ll n) {
    if(mp.find(n) != mp.end()){
        return mp[n];
    }
    if(n<0){
        mp[n] = 0;
        return 0;
    }
    if (n == 0 || n == 1){
        mp[n] = 1;
        return 1;
    }
    mp[n] = n * fact(n - 1);
    return n * fact(n - 1);
}

ll comb(int a, int b){
    return fact(a)/(fact(b)*(fact(a-b)));
}


void solve(string s){
    vector<pii> pref{mk(0,0)};
    for(int i=sz(s)-1;i>=0;--i){
        if(s[i] == '0'){
            pref.pb(mk(pref[sz(pref)-1].a+1,pref[sz(pref)-1].b));
        }else if(s[i] == '?'){
            pref.pb(mk(pref[sz(pref)-1].a,pref[sz(pref)-1].b+1));
        }
    }

    reverse(pref.begin(), pref.end());
    int M = pref[0].b;
    int N = pref[0].a;
    ll ans = 0;
    // cout << sz(pref) << " " << sz(s) << " " << N << " " << M << endl;
    for(int i=N;i<=N+M;++i){
        int m = pref[i].b;
        int n = pref[i].a;
        if(m+n == 0) continue;
        for(int j=0;j<=i-N;++j){
            cout << M << " " << m << " " << i << " " << j << " " << n << " " << pref[i].a << endl;
            ans += comb(M-m, i-N-j)*comb(m,j)*(j+n);
            cout << ans << endl;
        }
        
    }
    cout << ans%MOD << endl;
    
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

    string s;
    cin >> s;
    solve(s);

    return 0;
}