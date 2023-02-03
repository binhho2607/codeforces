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

void solve(vector<pii> &nums, vector<pii> &queries){
    for(auto q:queries){
        
        if(q.a < q.b){
            
            ll curlow = imax;
            ll profit = 0;
            ll curday = 0;
            vi prop{0,1,2,3,2,1,0};
            for(int i=q.a;i<=q.b;++i){
                profit = max(profit, nums[i].a+nums[i].b*prop[curday%7]-curlow);
                // cout << nums[i].a << " " << i << endl;
                if(nums[i].a+nums[i].b*prop[curday%7] < curlow){
                    curlow = nums[i].a+nums[i].b*prop[curday%7];
                }
                curday += 1;
            }
            cout << profit << endl;
        }else{
            ll curlow = imax;
            ll profit = 0;
            ll curday = 0;
            vi prop{0,1,2,3,2,1,0};
            for(int i=q.a;i>=q.b;--i){
                profit = max(profit, nums[i].a+nums[i].b*prop[curday%7]-curlow);
                if(nums[i].a+nums[i].b*prop[curday%7] < curlow){
                    curlow = nums[i].a+nums[i].b*prop[curday%7];
                }
                curday += 1;
            }
            cout << profit << endl;
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt","r",stdin);
    //     freopen("../output.txt","w",stdout);
    // #endif

    int t;
    cin >> t;

    vector<pii> nums{mk(0,0)};
    // nums.resize(t+1, -1);
    for(int i=0;i<t;++i){
        ll s1, s2;
        cin >> s1;
        cin >> s2;
        nums.pb(mk(s1, s2));
        
    }

    cin >> t;
    vector<pii> queries;
    for(int i=0;i<t;++i){
        ll s1, s2;
        cin >> s1;
        cin >> s2;
        queries.pb(mk(s1, s2));
    }

    solve(nums, queries);
    return 0;
}