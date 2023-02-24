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

ll dp(int cur, string s, umap<int, ll>& memo){
    if(cur == sz(s)){
        return 0;
    }
    if(memo.find(cur) != memo.end()){
        return memo[cur];
    }
    ll m = LLONG_MAX/2;
    m = min(m, 1+dp(cur+1, s, memo));
    for(int i=cur;sz(s)-i-1 > i-cur+1;++i){ // check bounds
        string tmp1 = s.substr(cur, i-cur+1);
        string tmp2 = s.substr(i+1, i-cur+1);
//        cout << "tmp1 " <<  tmp1 << " " << cur << endl;
        string s2 = s;
        int mult = 0;
        while(tmp1 == tmp2){
            m = min(m, sz(tmp1)+dp(i+1+mult*(i-cur+1), s, memo));
            if(i+1 >= sz(s2)) break;
            s2 = s2.substr(i+1, sz(s2)-i);
//            cout << "s2 " << s2 << endl;
            if(sz(s2) < sz(tmp1)) break;
            string tmp2 = s.substr(i+1, i-cur+1);
//            cout << "tmp2 " << tmp2 << endl;
            ++mult;
        }
    }
    memo[cur] = m;
    return m;
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
    umap<int, ll> memo;
    ll ans = dp(0,s, memo);
    cout << ans << endl;

    return 0;
}