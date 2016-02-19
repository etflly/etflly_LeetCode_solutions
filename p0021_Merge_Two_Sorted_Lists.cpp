/* LeetCode 21. Merge Two Sorted Lists
 *
 * 合并两个有序链表。
 *
 * 注意判断表空即可。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        ListNode *head, *now;
        if (!l2 || (l1 && l2 && l1->val < l2->val)) { head = now = l1; l1 = l1->next; }
        else { head = now = l2; l2= l2->next; }
        while(l1 && l2) {
            if (l1->val < l2->val) { now = now->next = l1; l1 = l1->next; }
            else { now = now->next = l2; l2 = l2->next; }
        }
        if (l1) now->next = l1;
        else now->next = l2;
        return head;
    }
};
