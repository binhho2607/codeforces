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


void solve(ll n, ll k, ll x, vector<ll> nums){
    sort(nums.begin(), nums.end());
    vector<ll> dif;
    for(int i=1;i<sz(nums);++i){
        if(nums[i]-nums[i-1]>x){
            dif.pb(nums[i]-nums[i-1]);
        }
        
    }
    sort(dif.begin(), dif.end());
    reverse(dif.begin(), dif.end());
    ll ans = 1;
    // ll sz = sz(dif);
    // while(sz(dif) > 0 && dif.back()<=x){
    //     dif.pop_back();
    // }
    while(k>0){
        while(sz(dif) > 0 && dif.back()<=x){
            dif.pop_back();
        }
        
        if(sz(dif)==0) break;
        
        if(dif.back()%x == 0){
            if((dif.back())/x-1 <= k){
                k -= (dif.back())/x-1;
                dif.pop_back();
            }else{
                break;
            }
        }else{
            if((dif.back())/x <= k){
                k -= (dif.back())/x;
                dif.pop_back();
            }else{
                break;
            }
        }
    }
    cout << sz(dif)+1 << endl;
    return;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    ll n;
    ll k;
    ll x;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> n;
    cin >> k;
    cin >> x;
    vector<ll> nums;
    for(int i=0; i < n; ++i) { //loops for each case
        ll s;
        cin >> s; // number of elements in vector
        
        nums.pb(s);
    }
    solve(n, k, x, nums);
    return 0;
}