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

ll solve(vector<ll> ani)
{
    sort(ani.begin(), ani.end());

    vector<ll> pref(ani.size() + 1);
    pref[0] = 0;
    for (int i = 0 ; i < ani.size();++i)
    {
        pref[i+1] = pref[i] + ani[i];
    }

    int j = 2;
    while (j < pref.size() - 1)
    {
        if (pref[j] - pref[j-2] >= pref[pref.size() -1] - pref[j])
        {
            return pref.size() - j + 1;
        }
        ++j;
    }

    return 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll>arr(n);
    for (ll i = 0; i < n; ++i){
        cin>>arr[i];
    }

    cout<< solve(arr) <<endl;
    return 0;
}
