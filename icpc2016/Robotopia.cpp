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

struct node {
    int val;
    node* next;
    node* prev;
};

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct PairHasher{
  size_t operator()(const pii &x) const{
    return x.first ^ x.second;
  }
};


void solve(vector<vi> nums){
    for(int i=0;i<sz(nums);++i){
        int l1 = nums[i][0];
        int a1 = nums[i][1];
        int l2 = nums[i][2];
        int a2 = nums[i][3];
        int lt = nums[i][4];
        int at = nums[i][5];
        
        float s1 = -(float)l1/(float)l2;
        float i1 = (float)lt/(float)l2;
        float s2 = -(float)a1/(float)a2;
        float i2 = (float)at/(float)a2;

        if(abs(s1-s2) < pow(0.1,5)){ // s1 == s2
            if(abs(i1-i2) < pow(0.1,5)){ // i1 == i2, case wher there may be 1 solution in the range
                int x = 1;
                while((lt-l1*x)%l2 != 0){
                    x += 1;
                }
                int y = i1+s1*x;
                if(y <= 0){
                    cout << "?" << endl;
                }else{
                    int x1 = x+1;
                    while((lt-l1*x1)%l2 != 0){
                        x1 += 1;
                    }
                    int y1 = i1+s1*x1;
                    if(y1 <= 0){
                        cout << x << " " << y << endl;
                    }else{
                        cout << "?" << endl;
                    }
                }
            }else{
                cout << "?" << endl;
            }
        }else{
            int x = (i2-i1)/(s1-s2);
            if(abs(x*(s1-s2) - (i2-i1)) > pow(0.1, 5)){ // x is not integer
                cout << "?" << endl;
                continue;
            }
            int y = i1+s1*x;
            if(abs((y-s1*x) - i1) > pow(0.1, 5)){ // y is not integer
                cout << "?" << endl;
                continue;
            }
            if(x <= 0 || y <= 0){
                cout << "?" << endl;
                continue;
            }
            cout << x << " " << y << endl;
        }


        // if(a1*l2 == a2*l1){
        //     cout << "?1" << endl;
        // }else{
        //     int y = ;
        //     int x = (float)(lt-l2*y)/(float)l1;
        //     // cout << x << " " << y << " " << a1*(float)lt/(float)l1 - ((float)a1/(float)l1*l2-a2)*y << endl;
        //     if(l1*x+l2*y != lt || a1*x+a2*y != at || x <=0 || y <= 0){
        //         cout << "?" << endl;
        //     }else{
        //         cout << x << " " << y << endl;
        //     }
        // }

    }
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
    vector<vi> nums;
    for(int i=0; i < t; ++i) { //loops for each case
        int l1, l2, a1, a2, lt, at;
        cin >> l1 >> l2 >> a1 >> a2 >> lt >> at;
        nums.pb(vi{l1, l2, a1, a2, lt, at});
    }
    solve(nums);

    return 0;
}