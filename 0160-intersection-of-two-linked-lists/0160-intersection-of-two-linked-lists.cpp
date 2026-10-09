/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode*curr1=head1; 
        ListNode*curr2=head2;
        int count1=0;
        while(curr1){
            count1++;
            curr1=curr1->next;
        }
        int count2 = 0;
        while(curr2){
            count2++;
            curr2=curr2->next;
            
        }
        curr2=head2,curr1=head1 ;
        int temp = abs(count2-count1);
        if(count1>count2){
            while(temp--){
                curr1=curr1->next;
            }
        }
        else {
            while(temp--){
                curr2=curr2->next;
            }
        }
            
        
        while(curr1!=curr2){
            curr1=curr1->next ;
            curr2=curr2->next ;
        }
        return curr1  ;
        
    }
};