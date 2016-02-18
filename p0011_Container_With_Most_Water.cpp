/* LeetCode 11. Container With Most Water
 *
 * 给定一个数列a[n]，其中a[i]表示在数轴i点存在一条长为a[i]的竖线。从中选择两根竖线，使其组成桶来装水，求最多可以装多少水。
 *
 * 
 * 初始令L=0, R=n-1，用a[L]和a[R]组成桶。若a[L]<a[R]，L向右移动（++L），否则R向左移动（--R）。时间复杂度O(n)。
 * 证明：  
 * 若组成最大容积的两点是L0和R0，可以证明对任意L<L0都有a[L]<a[R0]，否则若存在a[L1]>a[R0]，那么L1和R0组成的容器一定比L和R组成的容积要大。同理对任意R>R0都有a[R]<a[L0]。那么根据上述策略，一定可以枚举到L0和R0。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    int maxArea(vector<int>& h) {
        int ret = 0;
        int l = 0, r = h.size() - 1;
        while (l < r) {
            ret = max(ret, (r - l) * min(h[l], h[r]));
            if (h[l] < h[r]) ++l;
            else --r;
        }
        return ret;
    }
};
