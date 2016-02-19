/* LeetCode 
 *
 * 删除一个单向链表倒数第n个数。要求只遍历一遍。
 *
 * 问题的关键在于怎么用一次遍历找到倒数第n个数。用2个指针，h2指向h1后第n个数，两个指针同时后移，这样h2为NULL的时候h1就指向倒数第n个数了。
 * 但其实我感觉这个方法有点无赖，2个指针遍历一遍和1个指针遍历两遍其实没什么大差别，最多是在n比较小的时候对cache友好一点。
 *
 * Author: etflly
 * Website: etflly.me
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h1 = head;
        ListNode* h2 = head;
        for (int i = 0; i < n; ++i) h2 = h2->next;
        if (h2 == NULL) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        h2 = h2->next;
        while(h2) { h1 = h1->next; h2 = h2->next; }
        ListNode* tmp = h1->next;
        h1->next = tmp->next;
        delete tmp;
        return head;
    }
};
