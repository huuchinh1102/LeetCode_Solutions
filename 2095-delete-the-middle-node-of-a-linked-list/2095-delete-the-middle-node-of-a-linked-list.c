/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteMiddle(struct ListNode* head) {
    int cnt = 0;
    struct ListNode* dummy = (struct ListNode*) malloc (sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* currNode = head;
    struct ListNode* prevNode = dummy;
    while (head != NULL) {
        head = head->next;
        cnt++;
    }
    int dem = 0;
    if (cnt == 1) {
        free(currNode);
        dummy->next = NULL;
    }
    else {
        while (currNode != NULL) { 
            currNode = currNode->next;
            prevNode = prevNode->next;
            dem++;
            if (dem == cnt/2) {
                prevNode->next = currNode->next;
                break;
            }
        }
    }
    return dummy->next;
}