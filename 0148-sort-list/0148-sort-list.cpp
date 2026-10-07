class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1 != NULL) {
            temp->next = l1;
        } else {
            temp->next = l2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }
};