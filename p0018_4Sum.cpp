/* LeetCode 18. 4Sum
 *
 * 给定一组数a[n]，从中选四个使其和为0，求所有不同的选择方案。每个方案中的四个数升序排列。
 *
 * 1. 预处理枚举两个数，将其和以及两个数的下标存入map。枚举前两个数a[i],a[j]，后两个数从map中找target-a[i]-a[j]即可。要注意处理重复的数字。时间复杂度O(n^2*log(n)^2)，然而STL常数较大且测试集数据规模较小实测效率并不理想，如果不加优化更是会TLE。
 * 2. 同p15的方法2类似。先排序。枚举第一个数a[i]和第二个数a[j]（i<j），后两个数在a[j+1..n-1]中选择。初始令第三个数的标号k=j+1，第四个数h=n-1，若a[i]+a[j]+a[k]+a[h]<target，k右移，若a[i]+a[j]+a[k]+a[h]>target，h左移。时间复杂度O(n^3)。
 * 
 * 优化（对上述2种方法均适用）：在枚举2个数时，如果这两个数以及剩下的最大的2个数的和仍小于target，可跳过这2个数；如果这两数和剩下的最小的两个数的和大于target，则可以直接跳出循环。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ret;
        int n = a.size();
        sort(a.begin(), a.end());
        map<long long, vector<pair<int, int>>> d;
        for (int i = n - 1; i >= 3; --i) if (i == n - 1 || a[i] != a[i+1]) {
            if (a[i] + a[i-1] + a[i-2] + a[i-3] < target) break;
            if (a[i] + a[0] + a[1] + a[2] > target) continue;
            for (int j = i - 1; j >= 2; --j) if (j == i - 1 || a[j] != a[j+1]) {
                if (a[i] + a[j] + a[j-1] + a[j-2] < target) break;
                if (a[i] + a[j] + a[0] + a[1] > target) continue;
                d[a[i]+a[j]].push_back(make_pair(j, i));
            }
        }
        for (int i = 0; i < n; ++i) if (i == 0 || a[i] != a[i-1]) {
            if (a[i] + a[i+1] + a[i+2] + a[i+3] > target) break;
            if (a[i] + a[n-3] + a[n-2] + a[n-1] < target) continue;
            for (int j = i + 1; j < n; ++j) if (j == i + 1 || a[j] != a[j-1]) {
                if (a[i] + a[j] + a[j+1] + a[j+2] > target) break;
                if (a[i] + a[j] + a[n-2] + a[n-1] < target) continue;
                long long rem = target-a[i]-a[j];
                if (d.count(rem)) {
                    auto it = lower_bound(d[rem].begin(), d[rem].end(), make_pair(j + 1, j + 2));
                    while (it != d[rem].end()) {
                        ret.push_back(vector<int> {a[i], a[j], a[it->first], a[it->second]});
                        ++it;
                    }
                }
            }
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ret;
        int n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 3; ++i) if (i == 0 || a[i] != a[i-1]) {
            if (a[i] + a[i+1] + a[i+2] + a[i+3] > target) break;
            if (a[i] + a[n-3] + a[n-2] + a[n-1] < target) continue;
            for (int j = i + 1; j < n - 2; ++j) if (j == i + 1 || a[j] != a[j-1]) {
                if (a[i] + a[j] + a[j+1] + a[j+2] > target) break;
                if (a[i] + a[j] + a[n-2] + a[n-1] < target) continue;
                int k = j + 1, h = n - 1;
                while (k < h) {
                    if (a[i] + a[j] + a[k] + a[h] == target) {
                        ret.push_back(vector<int> {a[i], a[j], a[k], a[h]});
                        ++k; --h;
                        while(k < h && a[k] == a[k-1]) ++k;
                        while(k < h && a[h] == a[h+1]) --h;
                    }
                    else if (a[i] + a[j] + a[k] + a[h] < target) ++k;
                    else --h;
                }
            }
        }
        return ret;
    }
};
