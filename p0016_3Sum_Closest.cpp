/* LeetCode 16. 3Sum Closest
 *
 * 给定一组数a[n]，从中选3个，使其和与给定的target最接近。
 *
 * 同p15的方法2类似。先排序。枚举第一个数a[i]，后两个数在a[i+1..n-1]中选择。初始令第二个数的标号j=i+1，第三个数k=n-1，若a[i]+a[j]+a[k]<target，j右移，若a[i]+a[j]+a[k]>target，k左移。时间复杂度O(n^2)。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        int ret = a[0] + a[1] + a[2];
        int n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = a[i] + a[j] + a[k];
                if (abs(sum - target) < abs(ret - target))
                    ret = sum;
                if (sum < target) ++j;
                else if (sum > target) --k;
                else return ret;
            }
        }
        return ret;
    }
};
