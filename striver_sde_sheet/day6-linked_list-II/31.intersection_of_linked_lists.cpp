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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Method 1
//         unordered_map<ListNode*,int> mp;
//         ListNode* temp=headA;
//         while(temp){
//             mp[temp]++;
//             temp=temp->next;
            
//         }
        
//         temp=headB;
//         while(temp){
//             if(mp[temp]){
//                 return temp;
//             }
//             temp=temp->next;
//         }
        
//         return NULL;
        
        //Method 2
        ListNode *d1=headA;
        ListNode *d2=headB;
        
        while(d1!=d2){
            d1=(d1==NULL)?headB:d1->next;
            d2=(d2==NULL)?headA:d2->next;
        }
        return d1;
        
    }
};