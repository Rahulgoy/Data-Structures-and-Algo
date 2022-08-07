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
    bool hasCycle(ListNode *head) {
        // Method 1 Hashing
        // unordered_map<ListNode *,int> mp;
        // ListNode *temp = head;
        // while(temp!=NULL){
        //     if(mp[temp]) return true;
        //     else mp[temp]++;
        //     temp=temp->next;
        // }
        // return false;
        
        // Method 2 Fast and Slow pointer
        if(!head) return head;
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
            
        }
        return false;
        
    }
};