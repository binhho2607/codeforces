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
#include <float.h>

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


void solve(vector<pair<double,double>> nums){
    double l = 0;
    sort(nums.begin(), nums.end());
    for(int i=1;i<sz(nums);++i){
        double r = nums[i].b-nums[i-1].b;
        double q = nums[i].a-nums[i-1].a;
        if(r < 0) r = -r;
        if(q < 0) q = -q;
        l = max((double)r/q, l);
    
    }
    // sort(x.begin(), x.end());
    // sort(f.begin(), f.end());
    // long double maxf = DBL_MIN;
    // int jf = -1;
    // int jx1 = -1;
    // int jx2 = -1;
    // long double minx = DBL_MAX;
    // for(int i=1;i<sz(x);++i){
    //     if(x[i].a-x[i-1].a<minx){
    //         minx = x[i].a-x[i-1].a;
    //         jx1 = x[i].b;
    //         jx2 = x[i-1].b;
    //     }
    // }
    // cout << f[sz(f)-1].a << endl;
    // long double l = max(abs(f[0].a-f[sz(f)-1].a)/abs(nums[f[0].b].a-nums[f[sz(f)-1].b].a), abs(nums[jx1].b-nums[jx2].b)/(minx));




    cout << fixed << setprecision(10) << l << endl;
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

    vector<pair<double, double>> nums;
    for(int i=0; i < t; ++i) { //loops for each case
        double s;
        double n;
        cin >> s;
        cin >> n;
        nums.pb(mk(s, n));

    }

    solve(nums);
    return 0;
}