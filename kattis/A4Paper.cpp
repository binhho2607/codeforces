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
#include <iomanip>

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


void solve(vector<ll> nums){
    long double ans=0;
    vector<ll> need{1}; // start from A1 
    bool f = false;
    for(int i=1;i<sz(nums);++i){
        // cout << nums[i] << " " << (need[i-1])*2 << endl;
        if(nums[i] < (need[i-1])*2){
            need.pb((need[i-1])*2-nums[i]);
        }else{
            f = true;
            need.pb(need[i-1]*2);
            break;
        }
    }
    // for(int i=0;i<sz(need);++i){
    //     cout << need[i] << " ";
    // }
    // cout << endl;

    if(!f){
        cout << "impossible" << endl;
        return;
    }

    long double l = 1/((long double)pow(2,(long double)3.0/(long double)4.0));
    long double s = 1/((long double)pow(2,(long double)5.0/(long double)4.0));
    for(int i=1;i<sz(need)-1;++i){
        // cout << ((need[i]+nums[i-1])/2)*l << endl;
        ans += ((need[i]+nums[i])/2)*l;
        long double tmp = l;
        l = s;
        s = tmp/2;
    }
    ans += (need[sz(need)-1]/2)*l;
    cout << fixed << setprecision(15) << ans << endl;
    // for(int i=0;i<sz(need);++i){
    //     cout << need[i] << " ";
    // }
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
    vector<ll> nums{0};
    for(int i=0; i < t-1; ++i) { //loops for each case
        ll s;
        cin >> s;
        nums.pb(s);
    }
    solve(nums);
    return 0;
}