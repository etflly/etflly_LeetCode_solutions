/* LeetCode 1. Two Sum
 *
 * 给定数组nums，数target，从nums中找到2个数使其和正好为target。答案唯一。
 *
 * 1. 暴力枚举，时间复杂度O(n^2)，空间复杂度O(1)
 * 2. 哈希，时间复杂度O(n)，空间复杂度O(a)
 * [3]. 查找树，时间复杂度O(nlogn)，空间复杂度O(n)
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(target - nums[i]))
                return vector<int> { hash[target-nums[i]], i + 1 };
            hash[nums[i]] = i + 1;
        }
    }
};
