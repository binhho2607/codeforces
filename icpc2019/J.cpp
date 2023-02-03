#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
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

// void solve(vector<ll> nums){
//     vector<pair<ll, ll>> pl;
//     vector<pair<ll, ll>> pr;
//     pr.resize(sz(nums),pair<ll,ll>());
//     ll cur = 0;
//     ll m = 0;
//     ll s = 0;
//     for(int i=0;i<sz(nums);++i){
//         if((long double)cur/(long double)(i) > m){
//             m = (long double)cur/(long double)(i);
//             s = i;
//         }
//         pl.pb(mk(m, s));
//         cur += nums[i];
//     }
//     cur = 0;
//     m = 0;
//     s = 0;
//     for(int i=sz(nums)-1;i>=0;--i){  
//         if((long double)cur/(long double)(sz(nums)-i-1) > m){
//             m = (long double)cur/(long double)(sz(nums)-i-1);
//             s = sz(nums)-i-1;
//         }
//         pr[i] = mk(m, s);
//         cur += nums[i];
//     }

//     long double ans = 0;
//     for(int i=0;i<sz(pl);++i){
//         long double val;
//         if(pl[i].b+pr[i].b == 0){
//             val = 0;
//         }else{
//             val = (long double)(pl[i].a*pl[i].b+pr[i].a*pr[i].b)/(long double)(pl[i].b+pr[i].b);
//         }
//         ans = max(ans, val);
//     }
//     cout << fixed << setprecision(10) << ans << endl;
// }


void solve(vector<ll> nums){
    ll cur1 = 0;
    ll cur2 = 0;
    long double profit = 0;
    for(int i=0;i<sz(nums);++i){
        cur1 += nums[i];
        cur2 += nums[sz(nums)-i-1];
        profit = max(profit, (long double)cur1/(long double)(i+1));
        profit = max(profit, (long double)cur2/(long double)(i+1));
    }
    cout << fixed << setprecision(10) << profit << endl;
    // cur = 0;
    // for(int i=sz(nums)-1;i>=0;--i){
    //     cur += nums[i];
    //     profit = max(profit, (long double)cur/(long double)i);
    // }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    ll t;
    cin >> t;
    vector<ll> nums;
    for(int i=0;i<t;++i){
        ll s;
        cin >> s;
        nums.pb(s);
    }

    solve(nums);
    return 0;
}