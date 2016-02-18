/* LeetCode 15. 3Sum
 *
 * 给定一组数a[n]，从中选三个使其和为0，求所有不同的选择方案。每个方案中的三个数升序排列。
 *
 * 1. 枚举前2个数，从map中检查第3个数是否存在，时间复杂度O(n^2*logn)。
 * 2. 先排序。枚举第一个数a[i]，后两个数在a[i+1..n-1]中选择。初始令第二个数的标号j=i+1，第三个数k=n-1，若a[i]+a[j]+a[k]<0，j右移，若a[i]+a[j]+a[k]>0，k左移。时间复杂度O(n^2)。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> hash;
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i) ++hash[nums[i]];
        for (auto a = hash.begin(); a != hash.end(); ++a) if (a->second) {
            --a->second;
            for (auto b = a; b != hash.end(); ++b) if (b->second) {
                --b->second;
                int c = - a->first - b->first;
                if (c >= a->first && c >= b->first && hash.count(c) && hash[c]) {
                    ret.push_back(vector<int>{a->first, b->first, c});
                }
                ++b->second;
            }
            ++a->second;
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ret;
        int n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && a[i] == a[i-1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (a[i] + a[j] + a[k] == 0) {
                    ret.push_back(vector<int> {a[i], a[j], a[k]});
                    ++j; --k;
                    while (j < k && a[j-1] == a[j]) ++j;
                    while (j < k && a[k+1] == a[k]) --k;
                }
                else if (a[i] + a[j] + a[k] < 0) ++j;
                else --k;
            }
        }
        return ret;
    }
};
