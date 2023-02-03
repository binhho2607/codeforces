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

void solve(int s){
    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    long long int a;
    long long int b;
    cin >> a;
    cin >> b;

    long long int g = gcd(a, b);

    long long int num1 = a / g;
    long long int num2 = b / g;

    if (num1 % 2 == 1 && num2 %2 == 1){
        cout << g;
    }
    else{
        cout << 0;
    }

    return 0;
}