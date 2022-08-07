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
    ListNode *reverse(ListNode* head){
        ListNode *prevNode=NULL,*currNode=head,*nextNode=head;
        while(currNode){
            nextNode=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=nextNode;
            
        }
        return prevNode;
    }
    bool isPalindrome(ListNode* head) {
        // Method 1
        // vector<int> clone;
        // ListNode* temp=head;
        // while(temp){
        //     clone.push_back(temp->val);
        //     temp=temp->next;
        // }
        // for(int i=0;i<clone.size()/2;i++){
        //     if(clone[i]!=clone[clone.size()-i-1]) return false;
        // }
        // return true;
        
        //Method 2
        if(!head or !head->next) return head;
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        fast=slow->next;
        slow=head;
        while(fast){
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
    
};