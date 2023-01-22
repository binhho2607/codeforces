#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll long
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

string solve(ll n, ll m, ll k, vector<ll> nums){
    priority_queue<pair<ll,ll>> q;
    
    for(ll i=0;i<m;++i){
        q.push(mk(nums[i], i));
    }


    ll p = n%k;
    while(n>p){
        ll k1 = k;
        vector<pair<ll,ll>> v;
        ll count = 0;
        while(k1>0){
            if (q.empty()){
                // cout << "empty" << k1 << " " << n  << " " << sz(v) << endl;
                cout << "NO" << endl;
                return "NO";
            }
            count += 1;
            v.pb(q.top());
            q.pop();
            --k1;
        }

        cout << "n: " << n << endl;
        cout << "chosen: " << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
        ll dec = v.back().first;
        n -= dec*count;
        
        cout << dec << " " << n << endl;
        for(int i=0;i<count;++i){
            v.back().first -= dec;
            if(v.back().first>0){
                q.push(v.back());
            } 
            v.pop_back();
        }
        // while(sz(v)>0){
            
        // }
    }
    ll count=0;
    while(!q.empty()){
        q.pop();
        count += 1;
    }
    if(count<p){
        cout << "NO" << endl;
        return "NO";
    } else {
        cout << "YES" << endl;
        return "YES";
    }

    // cout << "YES" << endl;
    // return;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    ll n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif


    ll m;
    ll k;
    cin >> t;

    bool f = true;
    for(ll i=0; i < t; ++i) { //loops for each case
        vector<ll> nums;
        cin >> n;
        cin >> m;
        cin >> k;
        for (int j=0; j < m; ++j) { // each element of vector
            ll s;
            cin >> s;
            nums.pb(s);
        }
        solve(n,m,k,nums);
    }

    return 0;
}