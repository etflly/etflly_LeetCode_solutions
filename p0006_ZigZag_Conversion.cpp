/* LeetCode 6. ZigZag Conversion
 *
 * 题目原描述比较含糊不清，事实上是将一个字符串按照下面的方式排列(r为行数），然后再按行输出。
 * 0                           2r-2                         4r-4
 * 1                     2r-3  2r-1                  4r-5   4r-3
 * 2               2r-4        2r                4r-6        .
 * .           .               .               .             .
 * .       r+3                 .           3r-1              .
 * r-2 r+2                     3r-4    3r-2                 5r-6
 * r-1                         3r-3                         5r-3
 *
 * 可以开几个字符串数组模拟这个过程，我选择了找规律。
 * 考虑图形中每一行相邻两个字符在原串中的序号之差。令P=r*2-2（即一个“V”循环的长度），那么有如下规律：
 * 0  +P      (+0)  +P      (+0)  ...
 * 1  +P-2    +2    +P-2    +2    ...
 * 2  +P-4    +4    +P-4    +4    ...
 * .  .       .     .       .
 * i  +P-i*2  +i*2  +P-i*2  +i*2  ...
 * .  .       .     .       .
 * n  (+0)    +P    (+0)    +P    ...
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res(s.size(), 0);
        int P = numRows * 2 - 2;
        int t = 0;
        for (int i = 0; i < numRows; ++i) {
            int k = i;
            int d = P - i * 2;
            while (k < s.size()) {
                if (d) res[t++] = s[k];
                k += d;
                d = P - d;
            }
        }
        return res;
    }
};
