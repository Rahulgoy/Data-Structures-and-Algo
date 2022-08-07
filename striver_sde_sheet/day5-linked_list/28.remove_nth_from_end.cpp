/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //  Method 1 - Two passes        
//         if(!head->next and n==1) return NULL;
            
//         ListNode* temp=head;
//         int count=1;
//         while(temp->next!=NULL){
//             temp=temp->next;
//             count++;
//         }
//         count=count-n-1;
//         if(count<0){
//             head=head->next;
//             return head;
//         } 
//         temp=head;
//         while(count>0){
//             temp=temp->next;
//             count--;
//         }
//         if(n==1) temp->next=NULL;
//         else temp->next=temp->next->next;
//         return head;
        
        // Method 2 One pass
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        for(int i=1;i<=n;i++) fast=fast->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(!slow->next->next) slow->next=NULL;
        else slow->next=slow->next->next;
        return start->next;
    }
};