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


void solve(int ex, int ey, vector<string> v){
    vector<string> str{"Forward","Right","Left"};
    for(int i=0;i<sz(v);++i){
        // cout << "current line " << i << endl;
        string tmp = v[i];
        for(auto p:str){
            // cout << "modify " << p << endl;
            if(p == tmp) continue;
            v[i] = p;
            vector<pii> dir{mk(1,0),mk(0,-1),mk(-1,0),mk(0,1)};
            int cur = 3;
            pii pos = mk(0,0);
            for(int k=0;k<sz(v);++k){
                if(v[k] == "Forward"){
                    pos = mk(pos.a+dir[cur].a, pos.b+dir[cur].b);
                }
                else if(v[k] == "Left"){
                    cur = (cur-1)%4;
                    if(cur < 0){
                        cur += 4;
                    }
                }
                else if(v[k] == "Right"){
                    cur = (cur+1)%4;
                }
                // cout << pos.a << " " << pos.b << " " << dir[cur].a << " " << dir[cur].b << endl;
            }
            if(pos.a == ex && pos.b == ey){
                cout << i+1 << " " << p << endl;
                return;
            }
        }
        v[i] = tmp;
    }
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int ex;
    unsigned int ey;
    int t;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> ex;
    cin >> ey;
    cin >> t;
    vector<string> v;
    for(int i=0; i < t; ++i) { //loops for each case
        string s;
        cin >> s; // number of elements in vector
        v.pb(s);
    }

    solve(ex, ey, v);

    return 0;
}