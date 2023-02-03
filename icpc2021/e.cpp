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

void solve(string towers)
{
    bool found_eye = false;
    int counter_left = 0;
    int i = 0;
    while (i < towers.size() && towers[i] != '(')
    {
        counter_left++;
        ++i;
    }
    i += 2;
    while (i < towers.size())
    {
        counter_left--;
        ++i;
    }
    if (counter_left == 0)
    {
        cout<<"correct"<<endl;
    }
    else
    {
        cout<< "fix"<<endl;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // unsigned int t;
    unsigned int n;

    // cin>>t;
    string tower;
    cin >> tower;
    solve(tower);
    return 0;
}