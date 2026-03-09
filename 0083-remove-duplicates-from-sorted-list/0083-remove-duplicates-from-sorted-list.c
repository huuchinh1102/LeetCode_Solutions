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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* currNode;
    struct ListNode* prevNode;
    if (head == NULL);
    else {
        prevNode = head;
        currNode = head->next;
        while (currNode != NULL) {
            if (currNode->val == prevNode->val) {
                prevNode->next = currNode->next;
                free(currNode);
                currNode = prevNode->next;
            }
            else {
                currNode = currNode->next;
                prevNode = prevNode->next;
            }
        }
    }
    return head;    
}