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

void solve(vi nums){
    sort(over(nums));
    reverse(over(nums));

    long double prev = 0;
    long double cur = 0;
    int s = 0;
    for(int k=1;k<=sz(nums);++k){
        s += nums[k-1];
        cur = (long double)s/100;
        // cout << s << " " << cur << endl;
        long double res = pow(cur, (long double)cur/(long double)k);
        cout << res << " " << cur << " " << k << " " << s << " " << nums[k-1] << endl;
        // if(res < prev){
        //     cout << prev << endl;
        //     return;
        // }
        prev = res;
    }
    cout << prev << endl;
    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    vi nums;
    for(int i=0;i<t;++i){
        int s;
        cin >> s;
        nums.pb(s);
    }

    solve(nums);
    return 0;
}