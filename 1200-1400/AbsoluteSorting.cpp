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
// #define all(x) (x).begin(), (x).end()
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
    int lo=nums[0];
    int hi=nums[0];
    if(abs(nums[0]-nums[1])>1){
        if(nums[0] > nums[1]){
            lo = nums[0]-abs(nums[0]-nums[1])/2;
            lo = nums[1];
            hi = nums[0]+abs(nums[0]-nums[1]);
        }else{
            hi = nums[0]+abs(nums[0]-nums[1])/2;
            hi = nums[1];
            lo = nums[0]-abs(nums[0]-nums[1]);
        }
    }
    if(sz(nums)==2){
        cout << nums[0] << endl;
        return;
    }

    // for(int i=lo;i<=hi;++i){
    //     cout << i << endl;
    //     bool f = true;
    //     for(int j=1;j<sz(nums);++j){
    //         cout << abs(nums[j]-i) << " " << abs(nums[j-1]-i) << endl;
    //         if(abs(nums[j]-i)<abs(nums[j-1]-i)){
    //             f = false;
    //             break;
    //         }
    //     }
    //     if(f){
    //         cout << i << endl;
    //         return;
    //     }
    // }

    while(lo <= hi){
        int m = (lo+hi)/2;
        bool f = true;
        for(int i=1;i<sz(nums);++i){
            if(abs(nums[i]-m)<abs(nums[i-1]-m)){
                // cout << m << " " << nums[i] << " " << i << " " << hi << " " << lo << endl;
                if(nums[i-1]>m){
                    lo = m+1;
                }else{
                    hi = m-1;
                }
                f = false;
                break;
            }
        }
        // cout  << hi << " " << lo << endl;
        if(f){
            cout << m << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;


    // for(int i=2;i<sz(nums);++i){
    //     if(abs(nums[i]-nums[0]) >= abs(nums[i-1]-nums[0])){ // do nothing
            
    //         continue;
    //     }
    //     else if(((float)(nums[i]-nums[0]))/((float)(nums[i-1]-nums[0])) > 0 && abs(nums[i]-nums[0]) < abs(nums[i-1]-nums[0])){ // same side, i is closer than i+1
            
    //         cout << -1 << endl;
    //         return;
    //     } else if(((float)(nums[i]-nums[0]))/((float)(nums[i-1]-nums[0])) <= 0){
            
    //         if(nums[i-1]>nums[0]){
    //             if(abs(abs(nums[i]-lo)-abs(nums[i-1]-lo)) <= hi-lo){
    //                 lo += abs(abs(nums[i]-lo)-abs(nums[i-1]-lo));
    //             }else{
                    
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }else{
    //             if(abs(abs(nums[i]-hi)-abs(nums[i-1]-hi)) <= hi-lo){
    //                 hi -= abs(abs(nums[i]-hi)-abs(nums[i-1]-hi));
    //             }else{
    //                 cout << abs(abs(nums[i]-hi)-abs(nums[i-1]-hi)) << " " << nums[i] << " " << nums[i-1] << " " << hi << endl;
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //     }
    // }
    // cout << (lo+hi)/2 << endl;
    // for(int i=0;i<sz(nums);++i){
    //     cout << abs(nums[i]-c) << " ";
    // }
    // cout << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    unsigned int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        vi nums;
        for (int j=0; j < n; ++j) { // each element of vector
            int s;
            cin >> s;
            nums.pb(s);
        }
        solve(nums);
    }

    return 0;
}