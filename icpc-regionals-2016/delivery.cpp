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


int solve(vector<pii> v, int k){

    int curLoad = 0;
    int curPos = 0;
    int i = 0;
    int dist = 0;
    while(i < sz(v)){
//        cout << i << endl;
        while(curLoad > 0 && i < sz(v) && (v[i].b-curLoad <= 0 || (v[i].b-curLoad)/k < v[i].b/k)){
            v[i].b -= min(curLoad, v[i].b);
            curLoad -= min(curLoad, v[i].b);
            dist += (v[i].a-curPos);

            curPos = v[i].a;
            if(curLoad > 0) ++i;
        }
        if(i >= sz(v)) break;
//        cout << v[i].a << " " << v[i].b << " " << dist << endl;
        if(v[i].b > 0 && curPos != 0){
//            v[i].b = 0;
            dist += 2*(v[i].b/k+1)*(v[i].a);
            cout << v[i].a << " " << 2*(v[i].b/k+1)*(v[i].a) << endl;
            curLoad = k-v[i].b%k;
            curPos = v[i].a;
            v[i].b = 0;
        }else if(v[i].b > 0 && curPos == 0){
//            v[i].b = 0;
            dist += (2*(v[i].b/k+1)-1)*(v[i].a);
            cout << v[i].a << " " << (2*(v[i].b/k+1)-1)*(v[i].a) << endl;
            curLoad = k-v[i].b%k;
            curPos = v[i].a;
            v[i].b = 0;
        }
//        cout << dist << " " << curLoad << " " << curPos << endl;
        ++i;
    }
//    cout << dist << endl;
    for(auto p:v){
        cout << p.b << " ";
    }
    cout << endl;
    return dist;
}




int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    unsigned int k;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin >> t >> k;
    vector<pii> neg;
    vector<pii> pos;
    for(int i=0; i < t; ++i) { //loops for each case
        int s1, s2;
        cin >> s1 >> s2;
        if(s1 < 0) neg.pb(mk(-s1,s2));
        if(s1 > 0) pos.pb(mk(s1,s2));
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
//    for(auto p:pos){
//        cout << p.a << " ";
//    }
//    cout << endl;
    int d1 = solve(neg, k);
    int d2 = solve(pos, k);
//    cout << d1 << " " << d2 << " " << neg.back().a << " " << pos.back().a << endl;

    int dist = d1+d2;
    if(sz(neg) > 0) dist += neg.back().a;
    if(sz(pos) > 0) dist += pos.back().a;
    cout << dist << endl;


    return 0;
}