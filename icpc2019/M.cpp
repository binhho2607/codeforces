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

long double gradient(int w, int g, int h, long double p){
    return (p/(long double)sqrt((long double)pow(h, 2)+(long double)pow(p,2))) + ((p-w)/(long double)sqrt((long double)pow(g, 2)+(long double)pow(w-p,2)));
}

void solve(int w, int g, int h, int r){
    long double longest;
    long double left, right;
    left = 0;
    right = w;
    int i = 100;
    while(i>0){
        long double mid = left+(right-left)/2;
        long double gr = gradient(w,g-r,h-r,mid);
        // cout << gr << " " << mid << endl;
        if(gr > 0){
            right = mid;
        }else{
            left = mid;
        }
        --i;
    }
    long double res = left+(right-left)/2;
    long double sh = (long double)sqrt((long double)pow(max(g,h)-min(g,h), 2) + (long double)pow(w,2));
    cout << fixed << setprecision(8) << sh << " " << (long double)sqrt((long double)pow(h-r,2)+(long double)pow(res,2))+(long double)sqrt((long double)pow(g-r,2)+(long double)pow(w-res,2)) << endl;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<gcd(75206452536745713, 10322579177493903);

    return 0;
}