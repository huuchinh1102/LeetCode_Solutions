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

void deleteNode(struct ListNode* node) {
    struct ListNode *currNode;
    struct ListNode *nextNode;
    currNode = node;
    nextNode = node->next;
    int temp = currNode->val;
    currNode->val = nextNode->val;
    nextNode->val = temp;
    currNode->next = nextNode->next;
    free(nextNode);
}