## 1. Two Sum

### 题目大意

给定数组nums，数target，从nums中找到2个数使其和正好为target。答案唯一。

### 思路

1. 暴力枚举，时间复杂度O(n^2)，空间复杂度O(1)
2. 哈希，时间复杂度O(n)，空间复杂度O(a)
3. 查找树（map），时间复杂度O(nlogn)，空间复杂度O(n)

## 2. Add Two Numbers

### 题目大意

求链表表示的2个整数的和，链表的每一个元素是整数的一位，链表倒序存储，即链表首是个位，尾是最高位。

### 思路

高精度加法，注意进位和指针运算即可。

## 3. Longest Substring Without Repeating Characters

### 题目大意

给定一个字符串，求它的不含重复字符的最长字串的长度。

### 思路

维护一个“滑动窗口”。并用vis[c]数组表示上一次看到字符c是在什么位置。  
遍历字符串，窗口右端始终是当前字符。如果vis[s[i]]在当前窗口之内，说明遇到了重复字符，那么将窗口左端移动到vis[s[i]]+1。

## 4. Median of Two Sorted Array

### 题目大意

求两个有序数列A[n], B[m]合并后的中位数。要求时间复杂度O(log(m+n))。

### 思路

1. 设N=n+m，合并后的数列为T。若N为奇数，则中位数是T[N/2]；若N为偶数，则中位数是(T[N/2-1]+T[N/2])/2。  
要达到log级的时间复杂度，必然不能求出T，那么问题转换为在不求出T的情况下求T[k]。考虑二分法。  
若第k个数出现在A中，设为A[i]，那么必有(0<=k-i-1\<m) B[k-i-1] \<= A[i] <= B\[k-i] (0<=k-i<m)，根据这个条件，可对A[i]二分求解。 
同理，若第k个数出现在B中，也可以二分求出。
2. 同样是二分，考虑中位数将2个数列都划分为2部分，前半部分的数的个数是(n+m+1)/2，二分找到A的分裂点A[i]（A[0..i-1]为前半部分），令j=(n+m+1)/2-i，则若A[i-1]<=B[j] && B[j-1]<=A[i]，有B的分裂点B[j]（B[j-1]为前半部分）。  
若n+m为奇数，答案即是max(A[i-1], B[j-1])；若n+m为偶数，答案为(max(A[i-1], B[j-1]) + min(A[i], B[j]))/2。

## 5. Longest Palindromic Substring

### 题目大意

求一字符串的最长回文子串。字符串最长1000。

### 思路

1. 枚举中心点，两边扩展。时间复杂度为O(n^2)。
2. [Manacher算法](https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md)。这个算法也是枚举中心点i，但是用一个巧妙的方法得到了以i为中心的回文子串的长度下界，使时间复杂度提升为O(n)。
3. 后缀树+Tarjan。时间复杂度O(n)。编码复杂。

## 6. ZigZag Conversion

### 题目大意

题目原描述比较含糊不清，事实上是将一个字符串按照下面的方式排列(r为行数），然后再按行输出。  
```
0                           2r-2                         4r-4  
1                     2r-3  2r-1                  4r-5   4r-3  
2               2r-4        2r                4r-6        .  
.           .               .               .             .  
.       r+3                 .           3r-1              .  
r-2 r+2                     3r-4    3r-2                 5r-6  
r-1                         3r-3                         5r-3  
```

### 思路

可以开几个字符串数组模拟这个过程，我选择了找规律。

考虑图形中每一行相邻两个字符在原串中的序号之差。令P=r\*2-2（即一个“V”循环的长度），那么有如下规律：

```
0  +P      (+0)  +P      (+0)  ...  
1  +P-2    +2    +P-2    +2    ...  
2  +P-4    +4    +P-4    +4    ...  
.  .       .     .       .  
i  +P-i*2  +i*2  +P-i*2  +i*2  ...  
.  .       .     .       .  
n  (+0)    +P    (+0)    +P    ...  
```

其中括号中的（+0）是不存在的。根据这个图便可以在O(1)的空间复杂度下完成转换。

【注】要额外注意r=1的情况，此时按之前的算法P=1\*2-2=0，并不符事实。

## 7. Reverse Integer

### 题目大意

将一个十进制数翻转，符号不变。如123=>321，-123=>-321。另原题中没说的：若结果溢出输出0。

### 思路

1. 除/模运算。除了对溢出的处理，还需要注意不同语言对含负数的除法和模运算实现的不同：C/Java是向零取整（余数与被除数相同），对此题来说负数和正数可一样处理；而Python是向下取整，对负数的处理就会麻烦一些。
2. 将数转换为字符串然后倒序输出。需要额外判断一下溢出。对Python来说相对比较方便。

## 8. String to Integer (atoi)

### 题目大意

实现atoi函数，即字符串转换为整数。

### 思路

几种特殊情况：

1. 忽略首部空白字符，其余视为非法字符。
2. 只接受第一个出现的正负号，其余视为非法字符。
3. 转换过程碰到任何非数字字符（非法字符）就视为转换完成，输出现有答案。
4. 若结果溢出，视正负输出INT\_MIN或INT\_MAX。

## 9. Palindrome Number

### 题目大意

判断一个整数转换成字符串后是否回文。

### 思路

有2种思路：直接翻转整数，或者将整数转换成字符串。后者需要使用额外空间，故第一种较好。但需要注意一些问题：

1. 负数不回文
2. 翻转数可能溢出

为避免溢出有几个可行的处理方案：

1. 用64位整数存储
2. 转换时少处理一位，最后一位单独判断。
3. 转换一半的位数。

## 10. Regular Expression Matching

### 题目大意

实现简单的正则匹配，仅2条特殊规则：

1. '.'匹配一个任何字符
2. '\*'表示匹配零个或多个其之前的字符（如"a*"匹配零个或多个a）

### 思路

DP。  
d[i][j] = true表示母串s的前i位（s[0..i-1]）和模式串p的前j位（p[0..j-1]）匹配成功。

初始d[0][0] = true，若d[i][j] == true，可以推出：

1. 若p[j+1] == '*'，则d[i][j+2] = true；
2. 若p[j+1] != '*'，且s[i] == p[j] || p[j] == '.'，则d[i+1][j+1] = true；
3. 若p[j-1] == '*'，且s[i] == p[j-2] || p[j-2] == '.'，则d[i+1][j] = true。

时间复杂度O(n^2)。另外要注意i,j的枚举范围（[0, 串长]），以及递推时越界判断。

## 11. Container With Most Water

### 题目大意

给定一个数列a[n]，其中a[i]表示在数轴i点存在一条长为a[i]的竖线。从中选择两根竖线，使其组成桶来装水，求最多可以装多少水。

### 思路

初始令L=0, R=n-1，用a[L]和a[R]组成桶。若a[L]<a[R]，L向右移动（++L），否则R向左移动（--R）。时间复杂度O(n)。

证明：  
若组成最大容积的两点是L0和R0，可以证明对任意L<L0都有a[L]<a[R0]，否则若存在a[L1]>a[R0]，那么L1和R0组成的容器一定比L和R组成的容积要大。同理对任意R>R0都有a[R]<a[L0]。那么根据上述策略，一定可以枚举到L0和R0。

## 12. Integer to Roman

### 题目大意

将给定的整数n（1 <= n <= 3999）转换成罗马数字。

### 思路

1. 根据[罗马数字](https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97)的定义进行模拟。
2. 罗马数字也是十进制计数，十进制的每一位的每个数字有唯一的罗马数字记法来表示，据此可以直接查表输出。

## 13. Roman to Integer

### 题目大意

将给定的罗马数字转换成整数n（1 <= n <= 3999）。

### 思路

根据[罗马数字](https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97)的定义进行模拟。

1. 严格按照定义进行解码，好处是如果需要可以判断输入是否合法（虽然本题每要求）。
2. 由于本题保证输入合法，可以仅按照读数的方法来进行转换，即当前位比后一位小则减这个数，否则加这个数。

## 14. Longest Common Prefix

### 题目大意

给定一组字符串，求最长公共前缀。

### 思路

暴力枚举前缀位数。注意处理特殊情况（空集、空串、长度越界等）。

## 15. 3Sum

### 题目大意

给定一组数a[n]，从中选三个使其和为0，求所有不同的选择方案。每个方案中的三个数升序排列。

### 思路

1. 枚举前2个数，从map中检查第3个数是否存在，时间复杂度O(n^2*logn)。
2. 先排序。枚举第一个数a[i]，后两个数在a[i+1..n-1]中选择。初始令第二个数的标号j=i+1，第三个数k=n-1，若a[i]+a[j]+a[k]<0，j右移，若a[i]+a[j]+a[k]>0，k左移。时间复杂度O(n^2)。

## 29. Divide Two Integers

### 题目大意

实现整数除法，不使用乘、除、模运算。溢出输出INT\_MAX。

### 思路

对除数和被除数取绝对值后，模拟二进制除法，再添加符号位。注意2点：

1. 溢出有2种情况：除数为0；INT\_MIN / (-1)。
2. INT\_MIN取绝对值超出32位整数范围，要用64位整数存储。

## 39. Combination Sum

### 题目大意

在数组candidates中选择若干数使选出的数的和等于target，每个数可使用多次，输出所有方案。要求每个方案的数升序输出。

### 思路

无限背包，记录下方案即可。  
用d[j]记录选择若干个数和是target的方案。

## 55. Jump Game

### 题目大意

给一个数列nums[n]，初始你在0，要跳到n-1，每个数代表你在这个位置最多能跳多少格。

### 思路

1. 从头开始跳，维护最多能跳多远。
2. 从终点看回来，维护有连续多少个不可到达终点的点，如果不能跨越这些点，那终点就不可达。

## 78. Subsets

### 题目大意

给一个集合，求所有子集。

### 思路

枚举，用二进制数来记录状态。

## 132. Palindrome Partitioning II

### 题目大意

给定字符串s，将其划分为若干字串，使每个字串都是回文串。求最小划分次数

### 思路

DP
d[i]表示s[0..i-1]的最小划分次数。  
枚举中心点i扩展回文子串：

1. 当i为中心点时，枚举半径k=[0, min(i, n-i-1)]，若扩展成功（s[i-k] == s[i+k]），用d[i-k]+1来更新d[i+k+1]（从i-k前切一刀）
2. 当(i, i+1)为中心点时，枚举半径k=[0, min(i, n-i-2)]，若扩展成功（s[i-k] == s[i+1+k]），用d[i-k]+1来更新d[i+k+2]（从i-k前切一刀）

## 169. Majority Element

### 题目大意

给定一个数列nums[n]，求出现次数超过n/2的数。答案必定存在。

### 思路

1. 用map记录每个数出现 次数。
2. 排序，nums[n/2]即为答案。
3. 利用“答案在出现次数比其他数出现次数加起来还多”这个事实，扫描数列，碰到的第一个数我们便认为他是我们要找的答案，同时设置一个计数器记录“从现在开始，这个数出现次数与其他数出现次数之差”，当接下来再遇到这个数时计数器加1，碰到别的数时减1。当计数器为0时，我们可以丢掉这个数，将下一个数作为“候选”，重复上述过程。显然，每个被丢掉的“候选”数，在他的“任期”内都占了一半的数量，这样便可以保证，即使我们要找的答案被我们丢过，在之后的数列中，他仍会出现超过一半的次数，我们最终还会又找到他。
4. 二进制思想。如果一个数出现次数超过n/2，那么他的二进制的每一位的数字在那个位置出现次数也会超过n/2。

## 190. Reverse Bits

### 题目大意

求一个32位整数的二进制翻转后的数

### 思路

利用位运算，将相邻1位、2位、4位、8位、16位交换。

## 219. Contains Duplicate II

### 题目大意

给定一个数列nums和间距k，求是否存在nums[i]==nums[j]且abs(i-j)<=k。

### 思路

枚举，用unordered_set（读取单个元素速度比set快）记录之前k个数。
