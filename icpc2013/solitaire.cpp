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


void solve(vi nums){
    vi nums2;
    if(sz(nums)==1){
        cout << 1 << endl;
        return;
    }
    while(sz(nums)>0){
        int s = sz(nums);
        nums2 = vi();
        bool f = false;
        for(int i=0;i<sz(nums)-1;++i){
            if((nums[i]+nums[i+1])%2 != 0){
                nums2.pb(i);
                if(i==sz(nums)-2) f = true;
            }else{
                ++i;
            }
        }
        if(f) nums2.pb(nums.back());
        if(sz(nums2) == s) break;
        nums = nums2;
    }
    cout << sz(nums) << endl;
    // stack<int> st;
    // for(int i=0;i<sz(nums);++i){
    //     if(sz(st) == 0){
    //         st.push(nums[i]);
    //     }else{
    //         if((nums[i]+st.top())%2 == 0){
    //             st.pop();
    //         }else{
    //             st.push(nums[i]);
    //         }
    //     }
    // }
    // cout << sz(st) << endl;
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
    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        nums.pb(n);
    }

    solve(nums);
    return 0;
}