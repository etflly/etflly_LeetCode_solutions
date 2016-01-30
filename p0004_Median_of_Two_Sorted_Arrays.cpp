/* LeetCode 4. Median of Two Sorted Arrays
 *
 * 求两个有序数列A[n], B[m]合并后的中位数。要求时间复杂度O(log(m+n))。
 *
 * 1. 设N=n+m，合并后的数列为T。若N为奇数，则中位数是T[N/2]；若N为偶数，则中位数是(T[N/2-1]+T[N/2])/2。
 * 要达到log级的时间复杂度，必然不能求出T，那么问题转换为在不求出T的情况下求T[k]。考虑二分法。
 * 若第k个数出现在A中，设为A[i]，那么必有(0<=k-i-1<m)B[k-i-1] <= A[i] <= B[k-i](0<=k-i<m)，根据这个条件，可对A[i]二分求解。
 * 同理，若第k个数出现在B中，也可以二分求出。
 * 2. 同样是二分，考虑中位数将2个数列都划分为2部分，前半部分的数的个数是(n+m+1)/2，二分找到A的分裂点A[i]（A[0..i-1]为前半部分），令j=(n+m+1)/2-i，则若A[i-1]<=B[j] && B[j-1]<=A[i]，有B的分裂点B[j]（B[j-1]为前半部分）。
 * 若n+m为奇数，答案即是max(A[i-1], B[j-1])；若n+m为偶数，答案为(max(A[i-1], B[j-1]) + min(A[i], B[j]))/2。
 *
 * Author: etflly
 * Website: etflly.me
 */

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
