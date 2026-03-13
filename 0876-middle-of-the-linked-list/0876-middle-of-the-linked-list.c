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

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode * currNode;
    struct ListNode * prevNode;
    if (head == NULL) {
        return NULL;
    }
    else {
        prevNode = head;
        currNode = head->next;
        int cnt = 1;
        int i = 1;
        if (currNode == NULL) {
            return head;
        }
        else {
            while (currNode != NULL) {
                currNode = currNode->next;
                prevNode = prevNode->next;
                cnt++;
            }
            currNode = head->next;
            prevNode = head;
            cnt = cnt/2;
            while (i < cnt) {
                currNode = currNode->next;
                prevNode = prevNode->next;
                i++;
            }
            return currNode;
            }
        }
}