#define imax INT_MAX
#define imin INT_MIN
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define vii vector<vi>
#define umap unordered_map
#define uset unordered_set
#define MOD 100000007

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

struct VectorHasher{
    int operator()(const vi&V) const{
        int hash = V.size();
        for (auto & i : V){
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash>>2);
        }
        return hash;
    }
};

void solve(int s){
    cout <<s<<endl;
}

vi getDigits(int num){
    vi v;
    while(num > 0){
        v.pb(num%10);
        num /= 10;
    }
    return v;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int t;

    int m, n;
    cin >> m >> n;
    int ans = 0;
    for(int i=m;i<=n;++i){
        vi digs = getDigits(i);
        uset<int> seen;
        bool flag = true;
        for(auto d:digs){
            if(d==0){
                flag = false;
                break;
            }
            if(seen.find(d) != seen.end()){
                flag = false;
                break;
            }
            if(i%d != 0){
                flag = false;
                break;
            }
            seen.insert(d);
        }
        if(flag && sz(digs) == 6){
            ++ans;
        }
    }

     cout << ans;
    return 0;
}
