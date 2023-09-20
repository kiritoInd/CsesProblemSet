#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

const int MOD = (int)1e9 + 7;

using namespace std;
int solve(int x,vector<int> &nums){

    vector<long long> dp(x + 1, 0);
    dp[0] = 1;

    for(int j = 1 ; j <= x; j++){
        for(int i = 0 ; i <=  nums.size()-1; i++){
            if(j - nums[i] >= 0){
                dp[j] += dp[j - nums[i]];
                dp[j] %= MOD;
            }
        }
    }
    return dp[x];
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
    cout<<solve(x ,nums);
    return 0;
}