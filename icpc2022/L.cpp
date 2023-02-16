#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll long int
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>

#define umap unordered_map
#define uset unordered_set
#define MOD 10000000007

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
};

ll findTaxi (int m ){
    ll i=0;
    ll cur = 1;
    ll ans1 = 0;
    while(i < m-1){
        ans1 += 2*cur;
        cur += 2;
        ++i;
    }
    ans1 += cur;
    return ans1;
}

ll findSpider(ll n){
    ll res = 0;
    for(ll i=3;i<=n;++i){
        res += i/3;
            // cout<<res<<endl;

    }
    return res;
}

void solve(ll m, ll n)
{

    ll ans1 = findTaxi(min(n + 1, m + 1));
    ll ans2 = findTaxi(min(n + 1, m + 1))+(findSpider(min(n, m)) * 4);
    // cout<<ans1<<" "<<ans2<<endl;
    ll g = gcd(ans1, ans2);
    if((ans1/g) % (ans2/g) == 0){
        cout<<(ans1/g) / (ans2/g)<<endl;
        return;
    }
    cout << ans1/g << "/" << ans2/g << endl;

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt","r", stdin);
    freopen("../output.txt","w", stdout);
    ll m, n;
    cin >> m >> n;
   
    solve(m, n);
    return 0;
}
