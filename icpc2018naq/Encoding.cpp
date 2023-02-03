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

void encode(string s){
    string ans = "";
    int p = 0;
    while(p < sz(s)){
        char c = s[p];
        int cur = 0;
        while(p<sz(s) && s[p] == c){
            ++p;
            ++cur;
        }
        ans += c+to_string(cur);
    }
    cout << ans << endl;
}

void decode(string s){
    string ans = "";
    int p = 0;
    for(int i=0;i<sz(s);i+=2){
        for(int j=0;j<(int)(s[i+1]-'0');++j){
            ans += s[i];
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
    string c;
    cin >> c;

    string s;
    cin >> s;
    if(c == "E"){
        encode(s);
    }else{
        decode(s);
    }
    return 0;
}