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

unordered_map<ll, vector<ll>> get_primes()
{
    vector<ll> primes = {2,3,5,7,11, 13, 17, 19, 23};
    unordered_map<ll, vector<ll>> xd;
    for (auto p : primes)
    {
        xd[p] = {};
    }
    return xd;
}

vector<int> helper(ll i)
{

}
void solve(int a, int b, int c, int d){
    // Get all prime number buckets
    unordered_map<ll, vector<ll>> prime_buckets = get_primes();

    for (int i = a; i <=c; ++i)
    {
        for (auto it : prime_buckets)
        {
            if (i % it.first == 0)
            {
                prime_buckets[it.first].push_back(i);
            }
        }
    }

    ll solution = 0;
    for (ll i = c; i <= d; ++i) {
        vector<int> primes = helper(i);
        unordered_set<ll> xd;
        for (auto p: primes)
        {
            auto vec = prime_buckets[p];
            for (auto el : vec)
            {
                xd.insert(el);
            }
        }
        solution += ((b-a) - xd.size());

    }

    cout << solution << endl;
}

vector<vi> sieve(int n){
    vector<vi> mark(n+1, vi());
    vector<vi> primes;
    mark[0] = mark[1] = {1};
    for(int i=2;i*i <= n; ++i){
        if(sz(mark[i]) == 0){
            for(int j=i*i;j<=n;j+=i){
                mark[j].pb(i);
            }
        }
    }
    return mark;
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
    ll a;
    ll b;
    ll c;
    ll d;

    cin>> a;
    cin >> b;
    cin >> c;
    cin >> d;

    vector<vi> factors = sieve(pow(10, 7));



    solve(a, b, c, d);

    return 0;

}
