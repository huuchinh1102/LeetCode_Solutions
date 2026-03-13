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

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode * currNode;
    struct ListNode * prevNode;
    struct ListNode * tempNode;
    prevNode = NULL;
    currNode = head;
    tempNode = head->next;
    while (tempNode != NULL) {
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = tempNode;
        tempNode = tempNode->next;
    }
    currNode->next = prevNode;
    head = currNode;
    return head;
}