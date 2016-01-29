/* LeetCode 78. Subsets
 *
 * 给一个集合，求所有子集。
 *
 * 枚举，用二进制数来记录状态。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        uint64_t n = 1 << nums.size();
        vector<vector<int>> ans(n, vector<int>(0));
        for (uint64_t d = 0; d < n; ++d)
            for (int i = 0; i < nums.size(); ++i)
                if (d & 1 << i)
                    ans[d].push_back(nums[i]);
        return ans;
    }
};
