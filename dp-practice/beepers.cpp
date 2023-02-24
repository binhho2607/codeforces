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

void permutate(int x, int y, vector<pii> beepers, int cur, int& cost, uset<int> inc, int sx, int sy){
    if(sz(inc) == sz(beepers)){
        cost = min(cost, cur+abs(sx-x)+abs(sy-y));
        return;
    }
    if(cur+abs(sx-x)+abs(sy-y) > cost) return;
    for(int i=0;i<sz(beepers);++i){
        if(inc.find(i) == inc.end()){
            inc.insert(i);
            permutate(beepers[i].a, beepers[i].b, beepers, cur+abs(beepers[i].a-x)+abs(beepers[i].b-y), cost, inc, sx, sy);
            inc.erase(i);
        }
    }
}



int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        int m, n;
        cin >> m >> n;
        int sx, sy;
        cin >> sx >> sy;
        int k;
        cin >> k;
        vector<pii> beepers;
        for(int j=0;j<k;++j){
            int s1, s2;
            cin >> s1 >> s2;
            beepers.pb(mk(s1, s2));
        }
        int cost = imax;
        uset<int> inc;
        permutate(sx, sy, beepers, 0, cost, inc, sx, sy);
        cout << cost << endl;

    }

    return 0;
}