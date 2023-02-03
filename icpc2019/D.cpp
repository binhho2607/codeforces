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
    bool good = true;
    int j=0;
    for(int i=1;i<=200 && j<nums.size();++i){
        if(nums[j] != i){
            cout << i << endl;
            good = false;
        }else{
            ++j;
        }
    }
    if(good){
        cout << "good job" << endl;
    }
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