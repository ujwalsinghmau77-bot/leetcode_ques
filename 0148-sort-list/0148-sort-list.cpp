class Solution {
public:

    ListNode* mergeList(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(l1 != NULL && l2 != NULL) {

            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }

        if(l1 != NULL)
            temp->next = l1;

        if(l2 != NULL)
            temp->next = l2;

        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {

        // 1. Base case
        if(head == NULL || head->next == NULL)
            return head;

        // 2. Find middle
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 3. Break into two halves
        temp->next = NULL;

        // 4. Sort both halves
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // 5. Merge sorted halves
        return mergeList(l1, l2);
    }
};