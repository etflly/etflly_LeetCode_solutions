/* LeetCode 219. Contains Duplicate II
 *
 * 给定一个数列nums和间距k，求是否存在nums[i]==nums[j]且abs(i-j)<=k。
 *
 * 枚举，用unordered_set（读取单个元素速度比set快）记录之前k个数。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(nums[i])) return true;
            hash.insert(nums[i]);
            if (i >= k) hash.erase(nums[i-k]);
        }
        return false;
    }
};
