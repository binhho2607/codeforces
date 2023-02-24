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


bool solve(vector<pii> v){
    if(v[0].a == v[1].a && v[1].a == v[2].a){
        if(v[0].b+v[1].b+v[2].b == v[0].a){
            cout << "YES" << endl;
            return true;
        }
    }
    if(v[0].b == v[1].b && v[1].b == v[2].b){
        if(v[0].a+v[1].a+v[2].a == v[0].b){
            cout << "YES" << endl;
            return true;
        }
    }
    if(v[0].a == v[1].a && v[0].b+v[1].b == v[2].b && v[2].b == v[2].a+v[0].a){
        cout << "YES" << endl;
        return true;
    }
    if(v[0].b == v[1].b && v[0].a+v[1].a == v[2].a && v[2].a == v[2].b+v[0].b){
        cout << "YES" << endl;
        return true;
    }
    return false;
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

    int h1, w1, h2, w2, h3, w3;
    cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;
    vector<pii> v1{mk(h1, w1), mk(h2, w2), mk(h3,w3)};
    vector<pii> v2{mk(h1, w1), mk(h3, w3), mk(h2,w2)};
    vector<pii> v3{mk(h2, w2), mk(h1, w1), mk(h3,w3)};
    vector<pii> v4{mk(h2, w2), mk(h3, w3), mk(h1,w1)};
    vector<pii> v5{mk(h3, w3), mk(h1, w1), mk(h2,w2)};
    vector<pii> v6{mk(h3, w3), mk(h2, w2), mk(h1,w1)};
    vector<vector<pii>> v{v1,v2,v3,v4,v5,v6};
    for(auto p:v){
        auto q = p;
        if(solve(p)){
            return 0;
        }
        swap(p[0].a, p[0].b);
        if(solve(p)){
            return 0;
        }
        swap(p[1].a, p[1].b);
        if(solve(p)){
            return 0;
        }
        swap(p[2].a, p[2].b);
        if(solve(p)){
            return 0;
        }
        p = q;
        swap(p[1].a, p[1].b);
        if(solve(p)){
            return 0;
        }
        swap(p[2].a, p[2].b);
        if(solve(p)){
            return 0;
        }
        p = q;
        swap(p[2].a, p[2].b);
        if(solve(p)){
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}