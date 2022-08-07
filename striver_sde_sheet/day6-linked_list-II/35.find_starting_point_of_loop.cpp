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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head or !head->next) return NULL;
        // Method 1
        // unordered_map<ListNode *,int> mp;
        // ListNode *temp=head;
        // while(temp){
        //     if(mp[temp]) return temp;
        //     else mp[temp]++;
        //     temp=temp->next;
        // }
        // return NULL;
        
        // Method 2
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*entry=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                while(slow!=entry){
                    slow=slow->next;
                    entry=entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};