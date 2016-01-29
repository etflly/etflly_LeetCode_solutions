/* LeetCode 169. Majority Element
 *
 * 给定一个数列nums[n]，求出现次数超过n/2的数。答案必定存在。
 *
 * 1. 用map记录每个数出现 次数。
 * 2. 排序，nums[n/2]即为答案。
 * 3. 利用“答案在出现次数比其他数出现次数加起来还多”这个事实，扫描数列，碰到的第一个数我们便认为他是我们要找的答案，同时设置一个计数器记录“从现在开始，这个数出现次数与其他数出现次数之差”，当接下来再遇到这个数时计数器加1，碰到别的数时减1。当计数器为0时，我们可以丢掉这个数，将下一个数作为“候选”，重复上述过程。显然，每个被丢掉的“候选”数，在他的“任期”内都占了一半的数量，这样便可以保证，即使我们要找的答案被我们丢过，在之后的数列中，他仍会出现超过一半的次数，我们最终还会又找到他。
 * 4. 二进制思想。如果一个数出现次数超过n/2，那么他的二进制的每一位的数字在那个位置出现次数也会超过n/2。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) 
            if (++hash[nums[i]] > nums.size() / 2) return nums[i];
        return -1;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                ans = nums[i];
                count = 0;
            }
            if (nums[i] == ans) ++count;
            else --count;
        }
        return ans;
    }
};

class Solution4 {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int bit_count;
        for (int k = 0; k < 32; ++k) {
            bit_count = 0;
            for (int i = 0; i < nums.size(); ++i)
                if (nums[i] >> k & 1) ++bit_count;
            if (bit_count > nums.size() / 2) ans |= 1 << k;
        }
        return ans;
    }
};
