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
#include <map>

using namespace std;

struct node {
    ll val;
    node* next;
    node* prev;

};

void solve(vector<vector<ll>> nums){
    vector<node*> s;
    umap<ll, node*> m;
    for(int i=0;i<sz(nums);++i){
        for(int j=0;j<sz(nums[i]);++j){
            node* n = new node;
            n->val = nums[i][j];
            s.pb(n);
            m.emplace(nums[i][j], n);
        }
    }
    for(int i=0;i<sz(nums);++i){
        for(int j=0;j<sz(nums[i]);++j){
            if(j==0){
                m[nums[i][j]]->next = nullptr;
            } else {
                m[nums[i][j]]->next = m[nums[i][j-1]];
            }
            if(j==sz(nums[i])-1){
                m[nums[i][j]]->prev = nullptr;
            } else {
                m[nums[i][j]]->prev = m[nums[i][j+1]];
            }
        }
    }

    sort(s.begin(), s.end(), [] (const auto& lhs, const auto& rhs) {
        return lhs->val > rhs->val;
    });

    // for(int i=0;i<sz(s);++i){
    //     cout << s[i]->val << " ";
    // }

    ll split = 0;
    ll comb = 0;

    if(s[0]->prev != nullptr){
        split += 1;
        s[0]->prev->next = nullptr;
        s[0]->prev = nullptr;
    }

    for(int i=1;i<sz(s);++i){
        if(s[i]->prev == nullptr && s[i-1]->next == nullptr) {
            comb += 1;
            s[i-1]->next = s[i];
            s[i]->prev = s[i-1];
        } else if (s[i]->prev == nullptr && s[i-1]->next != nullptr) {
            split += 1;
            comb += 1;
            s[i-1]->next->prev = nullptr;
            s[i-1]->next = s[i];
            s[i]->prev = s[i-1];
        } else if (s[i]->prev != nullptr && s[i-1]->next == nullptr) {
            
            split += 1;
            comb += 1;
            s[i-1]->next = s[i];
            s[i]->prev->next = nullptr;
            s[i]->prev = s[i-1];
        } else {
            if(s[i]->prev == s[i-1] && s[i-1]->next == s[i]) {
                continue;
            }
            split += 2;
            comb += 1;
            s[i-1]->next->prev = nullptr;
            s[i-1]->next = s[i];
            s[i]->prev->next = nullptr;
            s[i]->prev = s[i-1];
        }
    }

    cout << split << " " << comb << endl;

}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases */
    unsigned short int t;
    unsigned short int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;
    vector<vector<ll>> nums;
    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        nums.pb(vector<ll>());
        for (int j=0; j < n; ++j) { // each element of vector
            ll s;
            cin >> s;
            nums[sz(nums)-1].push_back(s);
        }
    }
    solve(nums);

    return 0;
}