#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>


using namespace std;

int solve(int x, vector<int> &dp, vector<int> &nums){
    if(x == 0) return 0;
    if(x<0) return -1;

    if(dp[x] != -2) return dp[x];

    int ans = INT_MAX;

    for(int i = 0; i < nums.size();i++){
        int val = solve(x-nums[i],dp,nums);
        if(val != -1) 
            ans = min(ans,val+1);
    }
    if(ans == INT_MAX) ans = -1;

    return  dp[x] = ans;
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
    vector<int> dp(x+1,-2);

    cout<<solve(x , dp , v);
    return 0;
}