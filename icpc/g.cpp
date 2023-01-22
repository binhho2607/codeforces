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

void solve(int c, int n, vi nums)
{
    int left = 0;
    int right = 0;
    vector<pii> cor;
    vector<pii> err;
    if(nums[0] != 1){
        cor.pb(mk(1, nums[0]-1));
    }
    int i = 1;
    while(i<n){
        int j = i-1;
        while(i<n && nums[i]==nums[i-1]+1){
            ++i;
        }
        // cout << nums[j] << " " << nums[i-1] << endl;
        err.pb(mk(nums[j],nums[i-1]));
        if(i>=n){
            break;
        }
        cor.pb(mk(nums[i-1]+1, nums[i]-1));
        ++i;
    }
    if(nums[n-1] != nums[n-2]+1){
        err.pb(mk(nums[n-1],nums[n-1]));
    }
    if(nums[n-1] != c){
        cor.pb(mk(nums[n-1]+1, c));
    }
    cout << "Errors: ";
    for(int i=0;i<sz(err);++i){
        // cout << err[i].a << " " << err[i].b << endl;
        if(err[i].a != err[i].b && i < sz(err)-2){
            cout << err[i].a << "-" << err[i].b << ", ";
        }else if(err[i].a != err[i].b && i == sz(err)-2){
            cout << err[i].a << "-" << err[i].b << " and ";
        }else if(err[i].a != err[i].b && i == sz(err)-1){
            cout << err[i].a << "-" << err[i].b << endl;
        }else if(err[i].a == err[i].b && i < sz(err)-2){
            cout << err[i].a << ", ";
        }else if(err[i].a == err[i].b && i == sz(err)-2){
            cout << err[i].a << " and ";
        }else if(err[i].a == err[i].b && i == sz(err)-1){
            cout << err[i].a << endl;
        }
    }
    cout << "Correct: ";
    for(int i=0;i<sz(cor);++i){
        // cout << i << endl;
        if(cor[i].a != cor[i].b && i < sz(cor)-2){
            cout << cor[i].a << "-" << cor[i].b << ", ";
        }else if(cor[i].a != cor[i].b && i == sz(cor)-2){
            cout << cor[i].a << "-" << cor[i].b << " and ";
        }else if(cor[i].a != cor[i].b && i == sz(cor)-1){
            cout << cor[i].a << "-" << cor[i].b << endl;
        }else if(cor[i].a == cor[i].b && i < sz(cor)-2){
            cout << cor[i].a << ", ";
        }else if(cor[i].a == cor[i].b && i == sz(cor)-2){
            cout << cor[i].a << " and ";
        }else if(cor[i].a == cor[i].b && i == sz(cor)-1){
            cout << cor[i].a << endl;
        }
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int c;
    unsigned int n;

// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
    cin >> c;
    cin >> n;
    vi nums;
    for(int i=0;i<n;++i){
        int s;
        cin >> s;
        nums.pb(s);
    }
    solve(c, n, nums);
}