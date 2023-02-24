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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int t;
    unsigned int n;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    long double dist = 0;
    if(x1 <= x0 && x0 <= x2 && y0 <= y1){

        dist = y1-y0;
    }else if(x1 <= x0 && x0 <= x2 && y0 >= y1) {

        dist = y0 - y2;
    }else if(x0 >= x2 && y1 <= y0 && y0 <= y2){

        dist = x0-x2;
    }else if(x0 <= x1 && y1 <= y0 && y0 <= y2){

        dist = x1 - x0;
    }else if(x0 >= x2 && y0 >= y2){
        dist = sqrt(pow(x0-x2, 2) + pow(y0-y2,2));
    }else if(x0 >= x2 && y0 <= y1){
        dist = sqrt(pow(x0-x2, 2) + pow(y0-y1,2));
    }else if(x0 <= x1 && y0 <= y1){
        dist = sqrt(pow(x0-x1, 2) + pow(y0-y1,2));
    }else if(x0 <= x1 && y0 >= y2){
        dist = sqrt(pow(x0-x1, 2) + pow(y0-y2,2));
    }
    cout << fixed << setprecision(1) <<  dist << endl;
    return 0;

}
