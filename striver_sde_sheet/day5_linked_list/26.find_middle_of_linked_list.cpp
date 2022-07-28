class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head,*fast=head;
        if(!head) return head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};