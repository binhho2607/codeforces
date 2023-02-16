#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll long long
#define pb push_back
#define mk make_pair
//#define pii pair<int, int>
//#define a first
//#define b second
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

int solve(int a, int b, int c)
{
    int ans = imax;
    int tmp;
    tmp = a + b;
    if (tmp - c >= 0){
        ans = min(tmp -c, ans);
    }
    ans = min(tmp + c, ans);
    if (tmp % c == 0){
        ans = min(ans, tmp / c);
    }
    ans = min(ans, tmp * c);
    tmp = a - b;
    if (tmp - c >= 0){
        ans = min (ans, tmp -c);
    }
    if (tmp + c >= 0){
        ans = min(ans, tmp + c);
    }
    if (tmp >= 0 && tmp % c == 0){
        ans = min(ans, tmp/c);
    }
    if (tmp >= 0){
        ans = min(ans, tmp * c);
    }
    tmp = a * b;
    if (tmp - c >= 0){
        ans = min(ans, tmp - c);
    }
    ans = min(ans, tmp + c);
    if (tmp % c == 0){
        ans = min(ans, tmp / c);
    }
    ans = min(ans, tmp * c);
    if (a % b != 0){
        return ans;
    }
    tmp = a / b;
    if (tmp - c >= 0){
        ans = min(ans, tmp - c);
    }
    ans = min(ans, tmp + c);
    if (tmp % c == 0){
        ans = min(ans, tmp / c);
    }
    ans = min(ans, tmp * c);
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("../input.txt","r", stdin);
    // freopen("../output.txt","w", stdout);

    int a, b, c;
    cin >> a >> b >> c;
    cout<<solve(a, b, c)<<endl;
    return 0;
}