

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




void solve(vector<int> nums){
    int size = nums.size();
    int sum = 0;
    sort(nums.begin(), nums.end());
    vector<int> nums2;
    for (int i=0;i<size/2;++i) {
        nums2.push_back(nums[i]);
        nums2.push_back(nums[size-i-1]);
    }
    if (size%2 == 1) {
        nums2.push_back(nums[size/2]);
    }

    for (int i=0;i<size;++i){
        if(sum == nums2[i]) {
            cout << "NO" << endl;
            return;
        }
        sum += nums2[i];
    }
    cout << "YES" << endl;
    for (int j=0;j<size;++j) {
        cout << nums2[j] << " ";
    }
    cout << endl;
    return;
}


int main(void) {
    /* number of test cases */
    unsigned short int t;
    unsigned short int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n;
        vector<int> nums;
        for (int j=0; j < n; ++j) {
            int s;
            cin >> s;
            nums.push_back(s);
        }

        solve(nums);
    }

    return 0;
}