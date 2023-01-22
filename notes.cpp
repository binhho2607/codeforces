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
#define all(x) (x).begin(), (x).end()
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


int binarySearch(vi nums, int k){
    int left=0;
    int right=sz(nums)-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(nums[mid]==k) return mid;
        if(nums[mid]>k){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    // right = largest number smaller than k
    // left - smallest number larger than k
    return -1;
}



// pick as much object as possible
// while stay under constraint
int greedy(vi m, int c){
    int ans = 0;
    sort(m.begin(),m.end());
    for(int i=0;i<sz(m);++i){
        if(c-m[i]<0) break;
        c -= m[i];
        ans += 1;
    }
    return ans;
}



int longestCommonSub(string s1, string s2){
    vector<vi> memo(sz(s1)+1, vi(sz(s2),0));
    for(int i=0;i<sz(s1);++i){
        for(int j=0;j<sz(s2);++j){
            if(s1[i]==s2[j]){
                memo[i+1][j+1]=1+memo[i][j];
            }else{
                memo[i+1][j+1]=max(memo[i][j+1],memo[i+1][j]);
            }
        }
    }
    return memo[sz(s1)][sz(s2)];
}


// m = vector of objects
// x is usually current object index
// y is usually price/weight of some sort
int dp(int x, int y, vi m, umap<vi, int, VectorHasher> memo){
    // last object, base case, valid
    if(x == sz(m)){ 
        return 0;
    
    // invalid combination
    if(true){
        return imax;
    }
    if(memo.find(vi{x,y}) != memo.end()){
        return memo[vi{x,y}];
    }
    int cmin = imax;
    // form combination with the remainining objects
    for(int i=x;i<sz(m);++i){
        // Bellman-Ford equation
        cmin = min(cmin, dp(i,y+m[x],m,memo));
    }
    // save to memo
    memo.emplace(vi{x,y}, cmin);
    return cmin;
}


int rob(vi nums) {
    if (sz(nums) > 1){ // base case
        nums[1] = max(nums[1], nums[0]);
    }
    for (int i=2;i<sz(nums);++i){
        // Bellman-Ford equation (choose one or the other)
        nums[i] = max(nums[i-2] + nums[i], nums[i-1]);
    }
    return nums[sz(nums)-1];
}

int coinChange(vi nums, int k){
    vi dp(k+1,imax);
    dp[0] = 0;
    for(int i=0;i<sz(dp);++i){
        for(int j=0;j<sz(c);++j){
            if(c[j]<=i){
                dp[i]=min(dp[i],dp[i-c]+1)
            }
        }
    }
    if(dp.back()==imax){
        return -1;
    }
    return dp.back(); 
}


void rotateMatrix(vector<vi> m){
    vector<vi> m2(sz(m[0]), vi(sz(m),0));
    for(int i=0;i<sz(m);++i){ // reflect across diagonal
        for(int j=0;j<sz(m[i]);++j){
            m2[j][i] = m[i][j];
        }
    }
    for(int i=0;i<sz(m2);++i){ // reverse each row
        reverse(m2[i].begin(), m2[i].end());
    }
}

void spiral(vector<vi> m){
    int u = 0; // up
    int l = 0; // left
    int r = sz(m[0])-1; // right
    int d = sz(m)-1; // down
    int c = 0; // count
    int cell;
    while (c < sz(m)*sz(m[0])) {
        for(int i=l;i<r+1;++i){ // left to right
            cell = m[u][i]; // visit cell
            c += 1;
        }
        for(int i=u+1;i<d+1;++i){ // downwards
            cell = m[i][r]; // visit cell
            c += 1;
        }
        if (u!=d){ // make sure we are on a different row than left to right
            for(int i=r-1;i>l-1;--i){ // right to left
                cell = m[d][i]; // visit cell
                c += 1;
            }
        }
        if (l!=r){ // make sure we are on a different col than upwards
            for(int i=d-1;i>u;--i){ // upwards
                cell = m[i][l]; // visit cell
                c += 1;
            }
        }
        l+=1;
        r-=1;
        u+=1;
        d-=1;
    }
}




void solve(int s){
    cout << s << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases */
    unsigned short int t;
    unsigned short int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        vector<int> nums;
        for (int j=0; j < n; ++j) { // each element of vector
            int s;
            cin >> s;
            nums.push_back(s);
        }
    }

    return 0;
}