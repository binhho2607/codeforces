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

int eval(vi nums, int x){
    int ans = 0;
    for(int i=0;i<sz(nums);++i){
        ans += pow(x,i)*nums[sz(nums)-i-1];
    }
    return ans;
}

void solve(int t, vi nums){
    vector<vi> dp(t+1,vi(t+1,imax));
    dp[0][1] = nums.back();
    for(int i=1;i<=t;++i){
        int cur = eval(nums, i)-eval(nums, i-1);
        for(int j=1;j<i;++j){
            // cout << j << endl;
            cur -= dp[i-j][j];
        }
        dp[i][1] = cur;
        for(int j=1;j<i;++j){
            // cout << dp[i-j][j] <<" " << dp[i-j+1][j] << endl;
            dp[i-j][j+1] = dp[i-j][j]+dp[i-j+1][j];
        }
    }
    for(int i=0;i<=t;++i){
        cout << dp[i][1] << " ";
    }
    cout << endl;
}

// int recurse(int i, int j, vector<vi> dp){
//     if(dp[i][j] != imax){
//         return dp[i][j];
//     }
//     dp[i][j] = 
// }


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;
    vi nums;
    for(int i=0; i <= t; ++i) { //loops for each case
        cin >> n;
        nums.pb(n);
    }
    solve(t, nums);

    return 0;
}