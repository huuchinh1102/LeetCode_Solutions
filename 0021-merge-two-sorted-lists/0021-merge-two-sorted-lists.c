/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct listNode {
    int val;
    struct ListNode *next;
} ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode * res;
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    res = &dummy;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            res->next = list1;
            res = res->next;
            list1 = list1->next;
        }
        else {
           res->next = list2;
           res = res->next;
           list2 = list2->next;
        } 
    }
    while(list1 != NULL) {
        res->next = list1;
        res = res->next;
        list1 = list1->next;
    }
    while(list2 != NULL) {
        res->next = list2;
        res = res->next;
        list2 = list2->next;
    }
    return dummy.next; 
}