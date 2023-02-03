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

string construct(int n, int j){
    string s = "";
    while(n > 0){
        s = to_string(n%j)+s;
        n = n/j;
    }
    return s;
}


void solve(int a, int b, int k){
    ll ans = 0;
    for(int i=a;i<=b;++i){
        bool f = true;
        for(int j=2;j<=k;++j){
            string s = construct(i, j);
            for(int l=0;l<sz(s)/2;++l){
                if(s[l]!=s[sz(s)-l-1]){
                    f = false;
                    break;
                }
            }
            if(!f){
                break;
            } 
        }
        if(f) ans += 1;
    }
    cout << ans << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int a;
    unsigned int b;
    unsigned int k;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> a;
    cin >> b;
    cin >> k;

    solve(a, b, k);

    return 0;
}