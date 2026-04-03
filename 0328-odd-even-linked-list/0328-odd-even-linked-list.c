/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* currNode = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* tail = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* prevNode = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* abc = (struct ListNode*) malloc (sizeof(struct ListNode));
    currNode = head;
    abc = head;
    tail->next = head;
    prevNode->next = head;
    int cnt = 0;
    if (cnt != NULL) cnt++;
    while (abc != NULL) {
        abc = abc->next;
        tail = tail->next;
        cnt++;
    }

    if (cnt <= 2) return head;
    else {
        int dem = 0;
        while (dem != cnt/2) {
            dem++;
            prevNode = prevNode->next;
            currNode = currNode->next;
            prevNode->next = currNode->next;
            tail->next = currNode;
            currNode->next = NULL;
            tail = tail->next;
            currNode = prevNode->next;
        }
    return head;
    }
}