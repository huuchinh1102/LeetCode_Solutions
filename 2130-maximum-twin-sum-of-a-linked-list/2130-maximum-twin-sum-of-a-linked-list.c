/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    struct ListNode* current = head;
    int len = 0;
    int a[100005] = {0};
    while (current != NULL) {
        current = current->next;
        len++;
    }
    current = head;
    int i = 0;
    while (current != NULL) {
        a[i] = current->val;
        current = current->next;
        i++;
    }
    int max = a[0] + a[len-1];
    for (int j = 0; j <= (len-1)/2; j++) {
        int sum = a[j] + a[len-1-j];
        if (sum > max) max = sum;
    }
    return max;
}