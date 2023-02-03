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


void solve(vi nums, int m){
    vi dp;
    dp.resize(m+1, imax);
    dp[0] = 0;
    sort(nums.begin(), nums.end());
    for(int i=0;i<sz(nums);++i){
        for(int j=1;j<sz(dp);++j){
            if(j-nums[i] >= 0){
                // cout << dp[j] << " " << dp[j-1] << " " << j << " " << min(dp[j], dp[j-i]+1) << endl;
                if(dp[j-nums[i]] != imax){
                    dp[j] = min(dp[j], dp[j-nums[i]]+1);
                }
                
            }
            
        }
    }
    // for(int i=0;i<sz(dp);++i){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    reverse(nums.begin(), nums.end());
    for(int i=0;i<=m;++i){
        int j=i;
        int p=0;
        int c = 0;
        while(j>0){
            // cout << nums[p] << endl;
            // while(j>0 && nums[p] <= j){
            //     // cout << i << " " << p << " " << j <<  endl;
            //     j -= nums[p];
            //     ++c;
            // }
            if(nums[p] <= j){
                c += j/nums[p];
                j -= (j/nums[p])*nums[p];
            }
            ++p;
        }
        // cout << i << " " << c << " " << dp[i] << endl;
        if(c > dp[i]){
            // cout << i << " " << c << " " << dp[i] << endl;
            cout << "non-canonical" << endl;
            return;
        }
    }
    cout << "canonical" << endl;
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
    vi nums;
    int m  = imin;
    for(int i=0; i < t; ++i) { //loops for each case
        int s;
        cin >> s;
        m = max(m, s);
        nums.pb(s);
    }
    solve(nums, 2*m);
    return 0;
}