/* LeetCode 1. Two Sum
 *
 * 给定数组nums，数target，从nums中找到2个数使其和正好为target。答案唯一。
 *
 * 1. 查找树，时间复杂度O(nlogn)，空间复杂度O(n)
 *
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(target - nums[i]))
                return vector<int> { hash[target-nums[i]], i };
            hash[nums[i]] = i;
        }
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) a[i] = make_pair(nums[i], i);
        sort(a.begin(), a.end());
        int i = 0, j = n - 1;
        while (i < j) {
            if (a[i].first + a[j].first == target) return vector<int>{a[i].second, a[j].second};
            if (a[i].first + a[j].first < target) ++i;
            else --j;
        }
        return vector<int>(0);
    }
};
