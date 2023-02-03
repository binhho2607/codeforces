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


void solve(vector<pair<ll,ll>> v){
    ll ans = 0;
    sort(v.begin(), v.end());
    for(int i=0;i<sz(v);++i){
        for(int j=i+1;j<sz(v);++j){
            if(v[i].a+2018 < v[j].a){
                break;
            }
            if(sqrt(pow(v[i].a-v[j].a, 2) + pow(v[i].b-v[j].b, 2)) == 2018) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
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
    vector<pair<ll,ll>> v;

    for(int i=0; i < t; ++i) { //loops for each case
        ll s1, s2;
        cin >> s1;
        cin >> s2;
        v.pb(mk(s1, s2));
    }

    solve(v);
    return 0;
}