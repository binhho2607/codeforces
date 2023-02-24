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

string hashStr(int x, int y){
    return to_string(x) + " " + to_string(y);
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    int r, n, a, b, x;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin >> r >> n >> a >> b >> x;
    vector<vi> honey;
    for(int i=r;i<=2*r-1;++i){
        honey.pb(vi(i, 0));
    }
    for(int i=2*r-2;i>=r;--i){
        honey.pb(vi(i, 0));
    }
    uset<int> u;
    for(int i=0; i < x; ++i) { //loops for each case
        int s;
        cin >> s;
        u.insert(s);
    }
    int id = 1;
    pii start, end;
    for(int i=0;i<sz(honey);++i){
        for(int j=0;j<sz(honey[i]);++j){
            if(u.find(id) != u.end()){
//                cout << "hi" << endl;
                honey[i][j] = 1; // obstacle
            }
            if(id == a){
                start = mk(i,j);
            }
            if(id == b){
//                cout << id << " " << i << " " << j << endl;
//                cout << sz(honey[i]) << endl;
                end = mk(i,j);
            }
            ++id;
        }
    }
//    cout << end.a << " " << end.b << endl;
    queue<pii> q;
    q.push(start);
    int k = 0;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    uset<string> visited{hashStr(start.a, start.b)};
    while(sz(q) > 0 && k <= n){
        int m = sz(q);
//        cout << m << endl;
        for(int l=0;l<m;++l){
            pii top = q.front();
            q.pop();
            int i = top.a;
            int j = top.b;

            if(end.a == i && end.b == j){
                cout << k << endl;
                return 0;
            }
            vector<pii> dirs{mk(0,-1),mk(0,1)};
            if(i<r-1){
                dirs.pb(mk(-1,-1));
                dirs.pb(mk(-1,0));
                dirs.pb(mk(1,0));
                dirs.pb(mk(1,1));
            }else if(i>r-1){
                dirs.pb(mk(1,-1));
                dirs.pb(mk(1,0));
                dirs.pb(mk(-1,0));
                dirs.pb(mk(-1,1));
            }else{
                dirs.pb(mk(-1,-1));
                dirs.pb(mk(-1,0));
                dirs.pb(mk(1,0));
                dirs.pb(mk(1,-1));
            }

            for(auto d:dirs){
                if(i+d.a >= 0 && i+d.a < sz(honey) && j+d.b >= 0 && j+d.b < sz(honey[i+d.a]) && honey[i+d.a][j+d.b] == 0 && visited.find(hashStr(i+d.a, j+d.b)) == visited.end()){
                    visited.insert(hashStr(i+d.a, j+d.b));
                    q.push(mk(i+d.a, j+d.b));
//                    cout << i << " " << j <<  " next " << i+d.a << " " << j+d.b << " " <<  d.a << " " << d.b << endl;
                }
            }
        }
        ++k;
    }

    cout << "No" << endl;



    return 0;
}