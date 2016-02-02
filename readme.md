## 1. Two Sum
### 题目大意
给定数组nums，数target，从nums中找到2个数使其和正好为target。答案唯一。
### 思路
1. 暴力枚举，时间复杂度O(n^2)，空间复杂度O(1)
2. 哈希，时间复杂度O(n)，空间复杂度O(a)
3. 查找树（map），时间复杂度O(nlogn)，空间复杂度O(n)

### 代码
```c++

class Solution3 {
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
```

## 2. Add Two Numbers
### 题目大意
求链表表示的2个整数的和，链表的每一个元素是整数的一位，链表倒序存储，即链表首是个位，尾是最高位。
### 思路
高精度加法，注意进位和指针运算即可。
### 代码
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *now = &head;
        int c = 0;
        while (l1 || l2 || c) {
            if (l1) { c+= l1->val; l1 = l1->next; }
            if (l2) { c+= l2->val; l2 = l2->next; }
            now = now->next = new ListNode(c % 10);
            c /= 10;
        }
        return head.next;
    }
};
```

## 3. Longest Substring Without Repeating Characters
### 题目大意
给定一个字符串，求它的不含重复字符的最长字串的长度。
### 思路
维护一个“滑动窗口”。并用vis[c]数组表示上一次看到字符c是在什么位置。
遍历字符串，窗口右端始终是当前字符。如果vis[s[i]]在当前窗口之内，说明遇到了重复字符，那么将窗口左端移动到vis[s[i]]+1。
### 代码
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256, -1);
        int ans = 0, now = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (vis[s[i]] < i - now) ans = max(ans, ++now);
            else now = i - vis[s[i]];
            vis[s[i]] = i;
        }
        return ans;
    }
};
```

## 4. Median of Two Sorted Array
### 题目大意
求两个有序数列A[n], B[m]合并后的中位数。要求时间复杂度O(log(m+n))。
### 思路
1. 设N=n+m，合并后的数列为T。若N为奇数，则中位数是T[N/2]；若N为偶数，则中位数是(T[N/2-1]+T[N/2])/2。
要达到log级的时间复杂度，必然不能求出T，那么问题转换为在不求出T的情况下求T[k]。考虑二分法。
若第k个数出现在A中，设为A[i]，那么必有(0<=k-i-1<m)B[k-i-1] <= A[i] <= B[k-i](0<=k-i<m)，根据这个条件，可对A[i]二分求解。
同理，若第k个数出现在B中，也可以二分求出。
2. 同样是二分，考虑中位数将2个数列都划分为2部分，前半部分的数的个数是(n+m+1)/2，二分找到A的分裂点A[i]（A[0..i-1]为前半部分），令j=(n+m+1)/2-i，则若A[i-1]<=B[j] && B[j-1]<=A[i]，有B的分裂点B[j]（B[j-1]为前半部分）。
若n+m为奇数，答案即是max(A[i-1], B[j-1])；若n+m为偶数，答案为(max(A[i-1], B[j-1]) + min(A[i], B[j]))/2。

### 代码
```c++
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        if (n & 1) return findKth(n/2, nums1, nums2);
        else return (findKth(n/2-1, nums1, nums2) + findKth(n/2, nums1, nums2)) / 2.0;
    }
private:
    int findKth(int k, vector<int>& a, vector<int>& b) {
        if (a.size() == 0) return b[k];
        if (b.size() == 0) return a[k];
        int L = 0, R = a.size();
        int M = (L + R) / 2;
        while (L < R) {
            if (M > k || (k - M < b.size() && a[M] > b[k-M])) { R = M; M = (L + R) / 2; }
            else if (k - M > b.size() || k != M && a[M] < b[k-M-1]) { L = M + 1; M = (L + R) / 2; }
            else return a[M];
        }
        L = 0; R = b.size();
        M = (L + R) / 2;
        while (L < R) {
            if (M > k || (k - M < a.size() && b[M] > a[k-M])) { R = M; M = (L + R) / 2; }
            else if (k - M > a.size() || k != M && b[M] < a[k-M-1]) { L = M + 1; M = (L + R) / 2; }
            else return b[M];
        }
    }
};


class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if (n > m) return findMedianSortedArrays(B, A);
        if (n == 0) return (B[m/2] + B[(m-1)/2]) / 2.0;
        int H = (n + m + 1) / 2;
        int L = 0, R = n+1;
        int i, j;
        while (L < R) {
            i = (L + R) / 2;
            j = H - i;
            if (j < 0) R = i;
            else if (j > m) L = i + 1;
            else if (i > 0 && j < m && A[i-1] > B[j]) R = i;
            else if (j > 0 && i < n && B[j-1] > A[i]) L = i + 1;
            else {
                int ans1 = max(i==0 ? INT_MIN : A[i-1], j==0 ? INT_MIN : B[j-1]);
                int ans2 = min(i==n ? INT_MAX : A[i], j==m ? INT_MAX : B[j]);
                if ((n + m) & 1)
                    return ans1;
                else
                    return (ans1 + ans2) / 2.0;
            }
        }
        return -1;
    }
};
```

## 5. Longest Palindromic Substring
### 题目大意
求一字符串的最长回文子串。字符串最长1000。
### 思路
1. 枚举中心点，两边扩展。时间复杂度为O(n^2)。
2. [Manacher算法](https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md)。这个算法也是枚举中心点i，但是用一个巧妙的方法得到了以i为中心的回文子串的长度下界，使时间复杂度提升为O(n)。
3. 后缀树+Tarjan。时间复杂度O(n)。编码复杂。

### 代码
```c++
class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        string res = "";
        for (int i = 0; i < n; ++i) {
            for (int k = 1; k <= min(i+1, n-i); ++k)
                if (i-k < 0 || i+k >= n || s[i-k] != s[i+k]) {
                    if (maxlen < k + k - 1) {
                        maxlen = k + k - 1;
                        res = s.substr(i - k + 1, k + k - 1);
                    }
                    break;
                }
            for (int k = 0; k <= min(i+1, n-1-i); ++k)
                if (i-k < 0 || i+1+k >=n || s[i-k] != s[i+1+k]) {
                    if (maxlen < k + k) {
                        maxlen = k + k;
                        res = s.substr(i - k + 1, k + k);
                    }
                    break;
                }
        }
        return res;
    }
};


class Solution2 {
public:
    string longestPalindrome(string s) {
        string T(s.size()*2+1, 0);
        for (int i = 0; i < s.size(); ++i) T[i*2+1] = s[i];
        int maxlen = 0;
        string res("");
        int mx = -1, cn = -1;
        vector<int> d(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            if (mx > i) d[i] = min(d[cn-(cn-i)], mx-i);
            while(i-d[i]-1 >= 0 && i+d[i]+1 < T.size() && T[i-d[i]-1] == T[i+d[i]+1]) ++d[i];
            if (i + d[i] > mx) {
                mx = i + d[i];
                cn = i;
            }
            if (d[i] > maxlen) {
                maxlen = d[i];
                res = s.substr((i-d[i])/2, d[i]);
            }
        }
        return res;
    }
};
```

### 6. ZigZag Conversion
### 题目大意
题目原描述比较含糊不清，事实上是将一个字符串按照下面的方式排列(r为行数），然后再按行输出。
0                           2r-2                         4r-4
1                     2r-3  2r-1                  4r-5   4r-3
2               2r-4        2r                4r-6        .
.           .               .               .             .
.       r+3                 .           3r-1              .
r-2 r+2                     3r-4    3r-2                 5r-6
r-1                         3r-3                         5r-3
### 思路
可以开几个字符串数组模拟这个过程，我选择了找规律。
考虑图形中每一行相邻两个字符在原串中的序号之差。令P=r\*2-2（即一个“V”循环的长度），那么有如下规律：
0  +P      (+0)  +P      (+0)  ...
1  +P-2    +2    +P-2    +2    ...
2  +P-4    +4    +P-4    +4    ...
.  .       .     .       .
i  +P-i\*2  +i\*2  +P-i\*2  +i\*2  ...
.  .       .     .       .
n  (+0)    +P    (+0)    +P    ...
其中括号中的（+0）是不存在的。根据这个图便可以在O(1)的空间复杂度下完成转换。
【注】要额外注意r=1的情况，此时按之前的算法P=1\*2-2=0，并不符事实。
### 代码
```c++
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
```

## 7. Reverse Integer
### 题目大意
将一个十进制数翻转，符号不变。如123=>321，-123=>-321。另原题中没说的：若结果溢出输出0。
### 思路
1. 除/模运算。除了对溢出的处理，还需要注意不同语言对含负数的除法和模运算实现的不同：C/Java是向零取整（余数与被除数相同），对此题来说负数和正数可一样处理；而Python是向下取整，对负数的处理就会麻烦一些。
2. 将数转换为字符串然后倒序输出。需要额外判断一下溢出。对Python来说相对比较方便。

### 代码
```c++
class Solution1 {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x) { ans = ans * 10 + x % 10; x /=10; }
        if (ans < INT_MIN || ans > INT_MAX) return 0;
        return ans;
    }
};
```

## 8. String to Integer (atoi)
### 题目大意
实现atoi函数，即字符串转换为整数。
### 思路
几种特殊情况：
1. 忽略首部空白字符，其余视为非法字符。
2. 只接受第一个出现的正负号，其余视为非法字符。
3. 转换过程碰到任何非数字字符（非法字符）就视为转换完成，输出现有答案。
4. 若结果溢出，视正负输出INT\_MIN或INT\_MAX。
### 代码
```c++
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (isspace(s[i])) ++i;
        bool minus = false;
        long long ans = 0;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') minus = true;
            ++i;
        }
        s = s.substr(i);
        for (i = 0; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') return minus ? -ans : ans;
            ans = ans * 10 + s[i] - '0';
            if (minus) {
                if (-ans < INT_MIN) return INT_MIN;
            }
            else {
                if (ans > INT_MAX) return INT_MAX;
            }
        }
        return minus ? -ans : ans;
    }
};
```

## 29. Divide Two Integers
### 题目大意
实现整数除法，不使用乘、除、模运算。溢出输出INT\_MAX。
### 思路
对除数和被除数取绝对值后，模拟二进制除法，再添加符号位。注意2点：
1. 溢出有2种情况：除数为0；INT\_MIN / (-1)。
2. INT\_MIN取绝对值超出32位整数范围，要用64位整数存储。

###代码
```c++
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        if (b == 0 || a == INT_MIN && b == -1) return INT_MAX;
        bool minus = false;
        if (a < 0) { minus = !minus; a = - a; }
        if (b < 0) { minus = !minus; b = - b; }
        int ans = 0;
        long long rem = 0;
        for (int k = 31; k >= 0; --k) {
            rem = rem << 1 | (a >> k & 1);
            ans <<= 1;
            if (rem >= b) { rem -= b; ans++; }
        }
        return minus ? -ans : ans;
    }
};
```

## 39. Combination Sum
### 题目大意
在数组candidates中选择若干数使选出的数的和等于target，每个数可使用多次，输出所有方案。要求每个方案的数升序输出。
### 思路
无限背包，记录下方案即可。
用d[j]记录选择若干个数和是target的方案。
### 代码
```c++
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
```

## 55. Jump Game
### 题目大意
给一个数列nums[n]，初始你在0，要跳到n-1，每个数代表你在这个位置最多能跳多少格。
### 思路
1. 从头开始跳，维护最多能跳多远。
2. 从终点看回来，维护有连续多少个不可到达终点的点，如果不能跨越这些点，那终点就不可达。

### 代码
```c++
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
```

## 78. Subsets
### 题目大意
给一个集合，求所有子集。
### 思路
枚举，用二进制数来记录状态。
### 代码
```c++

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        uint64_t n = 1 << nums.size();
        vector<vector<int>> ans(n, vector<int>(0));
        for (uint64_t d = 0; d < n; ++d)
            for (int i = 0; i < nums.size(); ++i)
                if (d & 1 << i)
                    ans[d].push_back(nums[i]);
        return ans;
    }
};
```

## 132. Palindrome Partitioning II
### 题目大意
给定字符串s，将其划分为若干字串，使每个字串都是回文串。求最小划分次数
### 思路
DP
d[i]表示s[0..i-1]的最小划分次数。
枚举中心点i扩展回文子串：
1. 当i为中心点时，枚举半径k=[0, min(i, n-i-1)]，若扩展成功（s[i-k] == s[i+k]），用d[i-k]+1来更新d[i+k+1]（从i-k前切一刀）
2. 当(i, i+1)为中心点时，枚举半径k=[0, min(i, n-i-2)]，若扩展成功（s[i-k] == s[i+1+k]），用d[i-k]+1来更新d[i+k+2]（从i-k前切一刀）

### 代码
```c++
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> d(n+1, INT_MAX);
        d[0] = -1;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k <= min(i, n-i-1); ++k)
                if (s[i-k] == s[i+k]) d[i+k+1] = min(d[i+k+1], d[i-k]+1);
                else break;
            for (int k = 0; k <= min(i, n-i-2); ++k)
                if (s[i-k] == s[i+1+k]) d[i+k+2] = min(d[i+k+2], d[i-k]+1);
                else break;
        }
        return d[n];
    }
};
```

## 169. Majority Element
### 题目大意
给定一个数列nums[n]，求出现次数超过n/2的数。答案必定存在。
### 思路
1. 用map记录每个数出现 次数。
2. 排序，nums[n/2]即为答案。
3. 利用“答案在出现次数比其他数出现次数加起来还多”这个事实，扫描数列，碰到的第一个数我们便认为他是我们要找的答案，同时设置一个计数器记录“从现在开始，这个数出现次数与其他数出现次数之差”，当接下来再遇到这个数时计数器加1，碰到别的数时减1。当计数器为0时，我们可以丢掉这个数，将下一个数作为“候选”，重复上述过程。显然，每个被丢掉的“候选”数，在他的“任期”内都占了一半的数量，这样便可以保证，即使我们要找的答案被我们丢过，在之后的数列中，他仍会出现超过一半的次数，我们最终还会又找到他。
4. 二进制思想。如果一个数出现次数超过n/2，那么他的二进制的每一位的数字在那个位置出现次数也会超过n/2。

### 代码
```c++
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
```

## 190. Reverse Bits
### 题目大意
求一个32位整数的二进制翻转后的数
### 思路
利用位运算，将相邻1位、2位、4位、8位、16位交换。
### 代码
```c++
class Solution1 {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n & 0x55555555) << 1 | (n & 0xAAAAAAAA) >> 1;
        n = (n & 0x33333333) << 2 | (n & 0xCCCCCCCC) >> 2;
        n = (n & 0x0F0F0F0F) << 4 | (n & 0xF0F0F0F0) >> 4;
        n = (n & 0x00FF00FF) << 8 | (n & 0xFF00FF00) >> 8;
        n = (n & 0x0000FFFF) << 16 | (n & 0xFFFF0000) >> 16;
        return n;
    }
};
```

## 219. Contains Duplicate II
### 题目大意
给定一个数列nums和间距k，求是否存在nums[i]==nums[j]且abs(i-j)<=k。
### 思路
枚举，用unordered_set（读取单个元素速度比set快）记录之前k个数。
### 代码
```c++

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(nums[i])) return true;
            hash.insert(nums[i]);
            if (i >= k) hash.erase(nums[i-k]);
        }
        return false;
    }
};
```
