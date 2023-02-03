#define imax INT_MAX
#define imin INT_MIN
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define vi vector<int>

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

void solve(vi ans)
{
    vi sol;
    int first = ans[0];
    int i = 1;
    while (i < ans.size())
    {
        if (ans[i] % first == 0)
        {
            sol.pb(ans[i]);
            ++i;
                        first = ans[i];

        }
        ++i;
    }
    for (auto i : sol)
    {
        cout << i << endl;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int t;
    unsigned int n;
    cin >> n;

    vi nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    solve(nums);
}