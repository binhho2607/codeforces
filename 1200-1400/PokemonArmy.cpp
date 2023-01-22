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

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

int dp(int i, int d, vi nums, umap<vi,int, VectorHasher>& memo){
    
    if(i==sz(nums)){
        return 0;
    }
    
    if(memo.find(vi{i,d}) != memo.end()){
        return memo[vi{i,d}];
    }
    int m = d*nums[i];
    for(int j=i+1;j<=sz(nums);++j){
        m = max(m, d*nums[i]+dp(j,-d,nums,memo));
    }
    // cout << i << " " << d << " " << m << endl;
    memo[vi{i,d}] = m;
    // if(memo.find(vi{i,d}) != memo.end()){
    //     cout << "memo" << endl;
    // }
    return m;
}

void solve(vi nums){
    ll ans = 0;
    umap<vi,int, VectorHasher> memo;
    // for(int i=0;i<sz(nums);++i){
    //     ans = max(ans, dp(i,1,nums,memo));
    // }
    
    for(int i=0;i<sz(nums);++i){
        if(i==0 && nums[i+1]<=nums[i]){
            ans += nums[i];
        }else if(i > 0 && i<sz(nums)-1 && nums[i-1] >= nums[i] && nums[i+1] > nums[i]){
            ans -= nums[i];
        }else if(i > 0 && i<sz(nums)-1 && nums[i-1] < nums[i] && nums[i+1] <= nums[i]){
            ans += nums[i];
        }else if(i > 0 && i == sz(nums)-1 && nums[i-1] < nums[i]){
            ans += nums[i];
        }
    }

    cout << ans << endl;
    return;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    unsigned int n;
    unsigned int q;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        cin >> q;
        vi nums;
        for (int j=0; j < n; ++j) { // each element of vector
            int s;
            cin >> s;
            nums.pb(s);
        }
        solve(nums);
    }

    return 0;
}