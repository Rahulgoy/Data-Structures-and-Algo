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
    ListNode *rotate(ListNode* head){
        ListNode* temp=head;
        while(temp->next->next){
            temp=temp->next;
        }
        temp->next->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        k=k%count;
        while(k--){
            head=rotate(head);
        }
        return head;
    }
};