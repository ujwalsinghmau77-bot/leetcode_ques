class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return {-1, -1};
        }
        ListNode* curr = head->next;
        ListNode* prev = head;
        int index = 1;
        
        while (curr->next != NULL) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                critical.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        if (critical.size() < 2) {
            return {-1, -1};
        }
        
        int mind = INT_MAX;
        for (int i = 1; i < critical.size(); i++) {
            mind = min(mind, critical[i] - critical[i - 1]);
        }
        
        int maxDistance = critical.back() - critical.front();

        return {mind, maxDistance};
    }
};