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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Method 1         
//         if(!l1) return l2;
//         if(!l2) return l1;
//         int carry=0,sum=0;
//         ListNode * res = new ListNode();
//         ListNode *tmp=res;
//         while(l1!=NULL and l2!=NULL){
//             sum=l1->val+l2->val+carry;
//             if(sum==0) carry=0;
//             else carry=sum/10;
//             sum=sum%10;
            
            
//             ListNode * temp = new ListNode(sum);
//             res->next=temp;
//             res=temp;
//             l1=l1->next;
//             l2=l2->next;
            
//         }
        
//         while(l1){
//             sum=l1->val+carry;
//             carry=sum/10;
//             sum=sum%10;
            
            
//             ListNode * temp = new ListNode(sum);
//             res->next=temp;
//             res=temp;
//             l1=l1->next;
//         }
//         while(l2){
//             sum=l2->val+carry;
//             carry=sum/10;
//             sum=sum%10;
            
            
//             ListNode * temp = new ListNode(sum);
//             res->next=temp;
//             res=temp;
//             l2=l2->next;
//         }
//         if(carry){
//             ListNode * temp = new ListNode(carry);
//         res->next=temp;
//         res=temp;
//         }
        
//         return tmp->next;
        
        // Method 2 clean code
        ListNode * res = new ListNode();
        ListNode *tmp=res;
        int carry=0;
        while(l1 || l2 || carry){
            int sum=(l1?l1->val:0) + (l2?l2->val:0) + (carry);
            carry=sum/10;
            ListNode * temp = new ListNode(sum%10);
            res->next=temp;
            res=temp;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            
        }
        return tmp->next;
    }
};