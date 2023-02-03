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

void solve(vector<long long> &A, vector<long long> & B, long long & total)
{
    ll wasteA =0, wasteB = 0;

    for (long long i = 0; i < B.size(); ++i){
        long long total_d = A[i] + B[i];
        long long mid = floor((total_d)/(long double)2) + 1;

        ll a_waste = 0;
        ll b_waste = 0;

        if (A[i] > B[i])
        {
            a_waste = A[i] - mid;
            b_waste = B[i];
            cout << "A " << a_waste << " " << b_waste << endl;
        }
        else 
        {
            a_waste = A[i];
            b_waste = B[i] - mid;
            cout << "B " << a_waste << " " << b_waste << endl;
        }

        wasteA += a_waste;
        wasteB += b_waste;
    }

    long double eff = abs(wasteA - wasteB) / (long double) total;
    cout << eff << endl;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    ll p;
    cin >> p;
    ll d;
    cin >> d;
    vector<ll> A(d, 0);
    vector<ll> B(d, 0);
    ll total = 0;
    for(ll i=0;i<p;++i){
        cin >> d;
        ll a, b;
        cin >> a >> b;
        total += (a + b);
        A[d] = a;
        B[d] = b;
    }

    solve(A, B, total);
    return 0;
}