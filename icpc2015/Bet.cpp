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

ll fact(int n){
    if(n==0 || n==1) return 1;
    return n*fact(n-1);
}

ll comb(int p, int q){
    return fact(p)/(fact(q)*fact(p-q));
}

void solve(int r, int s, int x, int y, int w){
    long double p = (long double)(s-r+1)/(long double)s;
    long double e = 0;
    for(int i=x;i<=y;++i){
        // cout << y << " " << i << endl;
        e += comb(y, i)*pow(p, i)*pow(1-p, y-i);
    }
    if(e*w > 1){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}


struct Point {
 
    ll x, y;
 
    bool operator<(Point p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};
 
ll cross_product(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y)
           - (A.y - O.y) * (B.x - O.x);
}
 
vector<Point> convex_hull(vector<Point> A)
{
    int n = A.size(), k = 0;
    if (n <= 3)
        return A;
    vector<Point> ans(2 * n);
    sort(A.begin(), A.end()); // Sort points lexicographically
    for (int i = 0; i < n; ++i) { // Build lower hull
        while (k >= 2 && cross_product(ans[k - 2],
                          ans[k - 1], A[i]) <= 0)
            k--;
        ans[k++] = A[i];
    }
    for (size_t i = n - 1, t = k + 1; i > 0; --i) { // Build upper hull
        while (k >= t && cross_product(ans[k - 2],
                           ans[k - 1], A[i - 1]) <= 0)
            k--;
        ans[k++] = A[i - 1];
    }
    ans.resize(k - 1);
    return ans;
}
  




int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    unsigned int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        int r, s, x, y, w;
        cin >> r >> s >> x >> y >> w;
        solve(r, s, x, y, w);
    }

    return 0;
}