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


ll recursion(vector<int> primes, int p, int lp, unsigned ll cur, int count, unsigned ll target){
    if(p == lp+1){
        if(cur == 1) return 0;
        // cout << cur << " " << count << endl;
        return pow(-1, count)*target/cur;
    }
    return recursion(primes, p+1, lp, cur*primes[p], count+1, target) + recursion(primes, p+1, lp, cur, count, target);
}

unsigned long long GCD(unsigned long long x, unsigned long long y)
{
    if (y == 0) return x;
    return GCD(y, x%y);
}

void solve(unsigned ll n){
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    unsigned ll target = 1;
    int lp = 0;
    for(int i=0;i<sz(primes);++i){
        if(target*primes[i] <= n){
            target *= primes[i];
            lp = i;
        }else{
            break;
        }
    }
    long double ans = 1;
    for(int i=0;i<=lp;++i){
        ans *= (1-(long double)1/(long double)(primes[i]));
    }
    ans *= target;
    ans = target-ans;
    unsigned ll g = GCD((ll)ans, target);
    // cout << ans << " " << target << " " << g << endl;
    cout << (ll)ans/g << "/" << target/g << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned ll t;
    unsigned int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;
    // t = pow(10,18);
    solve(t);

    return 0;
}