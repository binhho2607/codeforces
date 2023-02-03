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

void solve(string s){
    int p=0;
    int count=0;
    while(s[p] == 'L'){
        ++count;
        ++p;
    }
    int cur = count+1;
    int tmp = cur;
    while(count >=0){
        cout << tmp << endl;
        --count;
        --tmp;
    }
    // ++p;
    while(p<sz(s)){
        ++p;
        count += 1;
        while(p<sz(s) && s[p] == 'L'){
            ++count;
            ++p;
        }
        
        cur = cur+count+1;
        tmp = cur;
        // cout << "cur " << cur << endl;
        while(count >=0){
            cout << tmp << endl;
            --count;
            --tmp;
        }
        // ++p;
    }
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

    string s;
    cin >> s;

    solve(s);
    return 0;
}