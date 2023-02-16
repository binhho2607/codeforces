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

void solve(ll a, ll b, ll c)
{
    ll ans = imax;
    ans = min(a + b + c, ans);
    if (a - b + c >= 0)
    {
        ans = min(a - b + c, ans);
    }
    ans = min(a * b + c, ans);
    if ((a % b) == 0)
    {
        ans = min((a / b) + c, ans);
        if ((a / b) - c >= 0)
        {
            ans = min((a / b) - c, ans);
        }
        ans = min((a / b) * c, ans);
    }
    
    if (a + b - c >= 0)
    {
        ans = min(a + b - c, ans);
    }

    if (a - b - c >= 0)
    {
        ans = min(a - b - c, ans);
    }

    if (a * b - c >= 0)
    {
        ans = min(a * b - c, ans);
    }

    ans = min((a + b) * c, ans);

    if ((a - b) * c >= 0)
    {
        ans = min((a - b) * c, ans);
    }
    ans = min(a * b * c, ans);
    if ((a + b) % c == 0)
    {
        ans = min((a + b) / c, ans);
    }
    if ((a - b) % c == 0)
    {
        ans = min((a - b) / c, ans);
    }
    if ((a * b) % c == 0)
    {
        ans = min((a * b) / c, ans);
    }
    if ((a % b) == 0 && (a / b) % c == 0)
    {
        ans = min((a / b) / c, ans);
    }
    cout << ans << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;
    solve(a, b, c);
    return 0;
}
