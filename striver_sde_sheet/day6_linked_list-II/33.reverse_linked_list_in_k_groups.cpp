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
    ListNode* reverseK(ListNode* head, int k,int size_left) {
        
        if(size_left==0) return head;
        ListNode *prevNode=NULL,*currNode=head,*nextNode=head;
        ListNode *temp=head;
        int size=k;
        while(size-- and currNode and size_left){
            nextNode=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=nextNode;
        }
        size_left--;
        if(head!=NULL){
            head->next=reverseK(nextNode,k,size_left);
        }
        return prevNode;
    }
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        int size_left=count/k;
        return reverseK(head,k,size_left);
        // return prevNode;
    }
};