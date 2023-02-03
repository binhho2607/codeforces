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


void solve(vector<vector<int>> nums, int t){
    int i = 1;
    int cur = 0;
    long double dist = 0;
    long double act = 0;
    // pii prev = mk(nums[0][0], nums[0][1]);
    long double px = nums[0][0];
    long double py = nums[0][1];
    while(i<sz(nums)){
        act += sqrt(pow(nums[i][0]-nums[i-1][0],2)+pow(nums[i][1]-nums[i-1][1],2));
        while(cur <= nums[i][2]){
            long double cx = nums[i-1][0]+(nums[i][0]-nums[i-1][0])*(long double)(cur-nums[i-1][2])/(long double)(nums[i][2]-nums[i-1][2]);
            long double cy = nums[i-1][1]+(nums[i][1]-nums[i-1][1])*(long double)(cur-nums[i-1][2])/(long double)(nums[i][2]-nums[i-1][2]);
            dist += sqrt(pow(cx-px,2) + pow(cy-py,2));
            // cout << cur << " " << cx << " " << cy << " " << (nums[i][1]-nums[i-1][1])*(long double)(cur-nums[i-1][2])/(long double)(nums[i][2]-nums[i-1][2]) << endl;
            px = cx;
            py = cy;
            cur += t;
        }
        ++i;
    }
    if(cur-nums[sz(nums)-1][2] != t){
        long double cx = nums[sz(nums)-1][0];
        long double cy = nums[sz(nums)-1][1];
        dist += sqrt(pow(cx-px,2) + pow(cy-py,2));
    }
    
    cout << fixed << setprecision(10) << ((act-dist)/act)*100 << endl;
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

    cin >> n;
    cin >> t;

    vector<vector<int>> nums;
    for(int i=0; i < n; ++i) { //loops for each case
        int s1, s2, s3;
        cin >> s1;
        cin >> s2;
        cin >> s3;
        nums.pb(vector<int>{s1, s2, s3});
    }

    solve(nums, t);
    return 0;
}