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

string hash2(int x, int y){
    return to_string(x) + " " + to_string(y);
}

long double dp(int cur, int left, const vector<long double>& nums, umap<string, long double>& memo, const vector<int>& zero){
//    cout << "dp " << cur << " " << left << endl;
    if(cur == sz(nums) && left != 0){
        return 0.0;
    }
    if(cur == sz(nums) && left == 0){
        return 1.0;
    }
    if(left-1 >= sz(nums)-cur){
        return 0.0;
    }
    if(left == 0){
        return 1.0;
    }
    if(sz(nums)-cur-1-zero[cur] < left-1){
        return 0.0;
    }

//    if(left == 0){
//        return 1.0;
//    }

    if(memo.find(hash2(cur, left)) != memo.end()){
//        cout << "memo" << endl;
        return memo[hash2(cur, left)];
    }
    long double prob = 0;
//    for(int i=cur+1;i<sz(nums)-left+1;++i){
//        prob += dp(i, left-1, nums, memo, zero)*nums[cur];
//    }
    prob += dp(cur+1, left-1, nums, memo, zero)*nums[cur];
    prob += dp(cur+1, left, nums, memo, zero)*(1-nums[cur]);
//    cout << "prob " << prob << endl;
    memo[hash2(cur, left)] = prob;
    return prob;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/


#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int m, n;
    cin >> n >> m;
    vector<long double> nums{1.0};
//    int count = 0;
    for(int i=0;i<n+m-1;++i){
        long double s;
        cin >> s;
//        if(s > 0) ++count;
        nums.pb(s);
    }
    vector<int> zero(sz(nums), 0);
    zero[sz(zero)-1] = 0;
    for(int i=sz(nums)-2;i>=0;--i){
        zero[i] = zero[i+1];
        if(nums[i+1] == 0.0){
            zero[i]++;
        }
    }
    if(sz(nums)-zero[0]-1 < m){
        cout << fixed << setprecision(6) << 0 << endl;
        return 0;
    }
    umap<string, long double> memo;
    long double ans = dp(0,m+1, nums, memo, zero);
//    for(auto p:memo){
//        cout << p.a << " " << p.b << endl;
//    }
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}