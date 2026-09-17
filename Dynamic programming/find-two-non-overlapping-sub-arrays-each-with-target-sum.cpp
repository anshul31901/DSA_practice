https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/submissions/2145102066/?envType=daily-question&envId=2026-09-17
class Solution {
public:
int minSumOfLengths(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    int left = 0, sum = 0, ans = INT_MAX;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while (sum > target) {
            sum -= nums[left];
            left++;
        }

        dp[right] = (right > 0) ? dp[right - 1] : INT_MAX;

        if (sum == target) {
            int curLen = right - left + 1;
            if (left > 0 && dp[left - 1] != INT_MAX) {
                ans = min(ans, curLen + dp[left - 1]);
            }
            dp[right] = min(dp[right], curLen);
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
};
