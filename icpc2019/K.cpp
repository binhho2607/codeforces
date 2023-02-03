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

// void solve(string s){
//     int left, right;
//     left = 0;
//     right = 0;
//     // uset<char> u;
//     umap<char, int> m;
//     ll ans = 0;
//     while(right < sz(s)){
//         while(right < sz(s) && (right == left  || (m.find(s[right]) == m.end() || m[s[right]] == 0))){
//             if(m.find(s[right]) == m.end()){
//                 m[s[right]] = 0;
//             }
//             ++m[s[right]];
//             cout << left << " " << right << endl;
//             // if(right-left > 0){
//             //     ++ans;
//             // }
//             ++ans;
//             ++right;
            
//         }
//         while(left < right && m[s[right]] > 0){
//             m[s[left]] -= 1;
//             ++left;
//         }
//     }
//     cout << ans << endl;
// }

void solve(string s){
    int left, right;
    left = 0;
    while(left+1 < sz(s) && s[left] == s[left+1]){
        ++left;
    }
    ll ans = 0;
    while(left < sz(s)+1){
        // cout << left << endl;
        right = left+1;
        uset<char> u;
        u.insert(s[left]);
        char orig = s[left];
        while(right < sz(s)){
            if(s[right] == s[left]){
                break;
            }
            if(u.find(s[right]) == u.end()){
                // cout << left << " " << right << endl;
                ++ans;
                u.insert(s[right]);
            }
            ++right;
        }
        ++left;
        while(left+1 < sz(s) && s[left] == s[left+1]){
            ++left;
        }
    }
    cout << ans << endl;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    string s;
    cin >> s;
    solve(s);

    return 0;
}