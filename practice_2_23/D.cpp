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

void solve(vector<string> input){
    unordered_map<char, ll> map;

    for (auto card : input) {
        map[card[0]] ++;
    }
    ll k = 0;

    for (auto it : map)
    {
        k = max(k, it.second);
    }

    cout << k << endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int t;
    unsigned int n;
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif

    string in;
    vector<string> vec;

//    getline(cin, in);
//    cout << in << endl;
    for (int i = 0; i < 5; ++i)
    {
        cin >> in;
        vec.push_back(in);
    }

    solve(vec);


}
