class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* nxt=head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            
        }
        return prev;
    }
};