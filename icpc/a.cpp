#define imax INT_MAX
#define imin INT_MIN
// #define sz(x) ((int)(x).size())
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

long long find_greater(string N, vector<int> & avail){
    long long ret = 0;
    for (int i = 0; i < avail.size(); ++i){
        if (avail[i] > (N[0] - '0')){
            ret = avail[i];
            for (int l = 1; l < N.size(); ++l){
                ret = ret * 10 + avail[0];
            }
            return ret;
        }
    }

    ret = avail[0];
    for (int i = 0; i < N.size(); ++i){
        if (i == 0 && ret == 0){
            ret = avail[1];
        }
        else{
            ret = ret * 10 + avail[0];
        }
    }

    return ret;
}


long long find_lesser(string N, vector<int> & avail){
    long long ret = 0;
    for (int i = avail.size() - 1; i >= 0; --i){
        if (avail[i] < (N[0] - '0')){
            ret = avail[i];

            for (int l = 1; l < N.size(); ++l){
                ret = ret * 10 + avail.back();
            }
            return ret;
        }
    }

    ret = avail.back();
    for (int i = 1; i < N.size(); ++i){
        ret = ret * 10 + avail.back();

    }

    return ret;
}

void solve(int N)
{
    vector<int> avail;
    string N_str = to_string(N);
    unordered_set<int> chars;
    int N_copy = N;
    while (N_copy > 0){
        chars.insert(N%10);
        N /= 10;
    }

    for (int i = 0; i < 10; ++ i){
        if (chars.find(i) == chars.end()){
            avail.push_back(i);
        }    
    }

    if (avail.size() == 0){
        cout << "Impossible";
    }

    if (avail.size() == 1 && avail[0] == 0){
        cout << "0";
    }

    long long great = find_greater(N_str, avail);

    long long less = find_lesser(N_str, avail);
    long long dif1 = abs(great - N);
    long long dif2 = abs(less - N);

    if (dif1 < dif2){
        cout << great;
    }
    else if (dif2 < dif1){
        cout << less;
    }
    else { 
        cout << less << " " << great;
    }

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    unsigned int n;

// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
cin>>t;
    solve(t);
}