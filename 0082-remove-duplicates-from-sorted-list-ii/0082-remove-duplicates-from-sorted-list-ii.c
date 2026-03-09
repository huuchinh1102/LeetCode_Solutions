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
    struct ListNode * currNode;
    struct ListNode * prevNode;
    struct ListNode * curr2Node;
    struct ListNode * prev2Node = (struct ListNode*) malloc(sizeof(struct ListNode));
    int bye[305];
    for (int a = 0; a < 300; a++) {
        bye[a] = -101;
    }
    int y = 0;
    if (head == NULL);
    else {
        prevNode = head;
        currNode = head->next;
        int i = 0;
        while (currNode != NULL) {
            if (prevNode->val == currNode->val) {
                prevNode->next = currNode->next;
                free(currNode);
                currNode = prevNode->next;
                if (i >= 1 && bye[i-1] != prevNode->val) {
                    bye[i] = prevNode->val;
                    i++;
                }
                else if (i == 0) {
                    bye[i] = prevNode->val;
                    i++;
                }
            }
            else {
                currNode = currNode->next;
                prevNode = prevNode->next;
            }
        }
        prev2Node->next = head;
        curr2Node = head;
        while (curr2Node != NULL) {
            if (curr2Node->val == bye[y] && curr2Node == head) {
                head = curr2Node->next;
                free(curr2Node);
                curr2Node = head;
                prev2Node->next = head;
                y++;
            }
            else if (curr2Node->val == bye[y]) {
                prev2Node->next = curr2Node->next;
                free(curr2Node);
                curr2Node = prev2Node->next;
                y++;
            }
            else {
                curr2Node = curr2Node->next;
                prev2Node = prev2Node->next;
            }
        }
    }
    return head;     
}