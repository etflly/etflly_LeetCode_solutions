/* LeetCode 39. Combination Sum
 *
 * 在数组candidates中选择若干数使选出的数的和等于target，每个数可使用多次，输出所有方案。要求每个方案的数升序输出。
 *
 * 无限背包，记录下方案即可。
 * 用d[j]记录选择若干个数和是target的方案。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a = candidates;
        sort(a.begin(), a.end());
        vector<vector<vector<int>>> d(target+1, vector<vector<int>>(0));
        d[0].push_back({});
        for (int i = 0; i < a.size(); ++i) if (i == 0 || a[i] != a[i-1])
            for (int k = a[i]; k <= target; ++k) {
                vector<vector<int>>& pre = d[k-a[i]];
                vector<vector<int>>& now = d[k];
                for (int j = 0; j < pre.size(); ++j) {
                    now.push_back(vector<int>(pre[j]));
                    now[now.size()-1].push_back(a[i]);
                }
            }
        if (d[target].size() == 0) return {};
        return d[target];
    }
};
