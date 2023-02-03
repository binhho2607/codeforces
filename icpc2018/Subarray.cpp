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
#include <climits>

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
    int hash = 2;
    hash ^= x.first + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    hash ^= x.second + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    return  hash;
  }
};


ll dp(int k, vector<ll> nums, int i, umap<pii, ll, PairHasher>& memo){
    if(i==sz(nums ) && k>0){
        return LLONG_MIN;
    }
    if(k > sz(nums)-i){
        return LLONG_MIN;
    }
    if(k==0){
        return 0;
    }
    if(memo.find(mk(i,k)) != memo.end()){
        return memo[mk(i,k)];
    }
    
    ll m = LLONG_MIN;
    ll cur = 0;
    for(int s=i;s<sz(nums);++s){
        cur += nums[s];
        ll res = dp(k-1, nums, s+1, memo);
        if(res != LLONG_MIN){
            m = max(m, cur+res);
        }
        res = dp(k, nums, s+1, memo);
        if(res != LLONG_MIN){
            m = max(m, res);
        }

    }
    memo[mk(i,k)] = m;
    return m;
    
}






int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int n;
    unsigned int k;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> n;
    cin >> k;
    vector<ll> nums;
    for(int i=0; i < n; ++i) { //loops for each case
        ll s;
        cin >> s;
        nums.pb(s);
    }
    umap<pii, ll, PairHasher> memo;
    cout << dp(k, nums, 0, memo) << endl;
    // solve(k, nums);

    return 0;
}