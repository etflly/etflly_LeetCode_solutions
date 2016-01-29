/* LeetCode 55. Jump Game
 *
 * 给一个数列nums[n]，初始你在0，要跳到n-1，每个数代表你在这个位置最多能跳多少格。
 *
 * 1. 从头开始跳，维护最多能跳多远。
 * 2. 从终点看回来，维护有连续多少个不可到达终点的点，如果不能跨越这些点，那终点就不可达。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (reach < i) return false;
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int count = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > count) count = 0;
            else ++count;
        }
        return count == 0;
    }
};
