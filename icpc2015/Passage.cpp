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


// void solve(vi nums){
//     sort(nums.begin(), nums.end());
//     int n1 = nums[0];
//     int n2 = nums[1];
//     nums.erase(nums.begin());
//     nums.erase(nums.begin());
//     int p = sz(nums)-1;
//     int ans = 0;
//     while(p>=1){
//         if(2*n2+n1+nums[p] < nums[p]+n1+nums[p-1]){
//             ans += n2;
//             ans += n1;
//             ans += nums[p];
//             p -= 2;
//             ans += n2;
//         }else{
//             ans += nums[p];
//             ans += n1;
//             p -= 1;
//         }
        
//     }
//     if(p == 0){
//         ans += nums[p];
//         ans += n1;
//     }
//     ans += n2;
//     cout << ans << endl;
// }

void recursion(vi left, vi right, int side, int cur, int& ans){
    if(side%2 == 1 && sz(left) == 0){
        ans = min(ans, cur);
        return;
    }
    if(side%2 == 1){
        int m=imax;
        int ind;
        for(int i=0;i<sz(right);++i){
            if(right[i] < m){
                m = right[i];
                ind = i;
            }
        }
        vi nright = right;
        nright.erase(nright.begin()+ind);
        vi nleft = left;
        nleft.pb(m);
        recursion(nleft, nright, side+1, cur+m, ans);
        return;
    }

    sort(left.begin(), left.end());
    vi nleft = left;
    nleft.pop_back();
    nleft.pop_back();
    vi nright = right;
    nright.pb(left[sz(left)-1]);
    nright.pb(left[sz(left)-2]);
    recursion(nleft, nright, side+1, cur+left[sz(left)-1], ans);


    nleft = left;
    nleft.pop_back();
    nleft.erase(nleft.begin());
    nright = right;
    nright.pb(left[sz(left)-1]);
    nright.pb(left[0]);
    recursion(nleft, nright, side+1, cur+left[sz(left)-1], ans);

    nleft = left;
    nleft.erase(nleft.begin());
    nleft.erase(nleft.begin());
    nright = right;
    nright.pb(left[0]);
    nright.pb(left[1]);
    recursion(nleft, nright, side+1, cur+left[1], ans);

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
        int s;
        cin >> s;
        nums.pb(s);
    }
    // solve(nums);

    int ans = imax;
    recursion(nums, vi(), 0, 0, ans);
    cout << ans << endl;

    return 0;
}