#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
 
using namespace std;
 
int solve(int x, vector<int> &nums){
    vector<int> dp(x+1);
    dp[0] = 0;
 
    for(int j = 1; j<= x; j++){
        int ans = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            if(j-nums[i] < 0) continue;
 
            int val = dp[j - nums[i]];
            if(val != -1) ans = min(ans, val+1);
        }
        if(ans == INT_MAX) dp[j] = -1;
        else dp[j] = ans;
    }
 
    return dp[x];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n , x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    cout<< solve(x,v);
    return 0;
}