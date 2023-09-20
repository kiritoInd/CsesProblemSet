#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
const int MOD = (int)1e9 + 7;

using namespace std;
int solve(int target, vector<ll> &dp,vector<int> &nums){
    if(target == 0) return 1;
    if(target<0) return 0;

    if(dp[target] != -1) return dp[target];

    int ans = 0;
    for(int i = 0; i <= nums.size()-1 ;i++){
        if(target - nums[i] >= 0){
            ans += solve(target - nums[i] , dp , nums);
            ans %= MOD;
        }
    }
    return  dp[target] = ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n , x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0;i<n; i++){
        cin>>nums[i];
    }
    vector<ll> dp(x+1,-1);
    cout<<solve(x , dp ,nums);
    return 0;
}