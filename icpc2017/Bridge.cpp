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

// long double cosh(long double x){
//     return (exp(x)+exp(-x))/2;
// }


void solve(int d, int s){
    long double left = 0;
    long double right = imax;
    int iter = 0;
    long double mid;
    while(left < right && iter < 100){
        mid = left+(right-left)/2;
        if(mid + s - mid*cosh(d/(2*mid)) == 0){
            break;
        }else if(mid + s - mid*cosh(d/(2*mid)) < 0){
            left = mid;
        }else{
            right = mid;
        }
        iter += 1;
    }
    cout << fixed << setprecision(9) << 2*mid*sinh(d/(2*mid)) << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int d;
    unsigned int s;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> d;
    cin >> s;

    solve(d, s);

    return 0;
}