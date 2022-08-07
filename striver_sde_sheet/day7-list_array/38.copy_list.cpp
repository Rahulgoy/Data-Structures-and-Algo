/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* temp = head;
        
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        // a-a'-b-b'-c-c'         
        //  a->c
        //  b->a
        //  c->b
        
        temp = head;
        while(temp){
            temp->next->random = (temp->random)?temp->random->next:NULL;
            temp = temp->next->next;
        }
        
        /*
    
        after this step the situation is 

        a -a'- b -b'- c - c'

        a->c
        b->a
        c->b

        a'->c'
        b'->a'
        c'->b'

        */
        Node* ans = head->next;
        temp = head->next;
        while(head){
            head->next = temp->next;
            head = head->next;
            if(!head) break;
            temp->next = head->next;
            temp = temp->next;
        }
        /*
             after this step the situation is 

            a-b-c

             a'-b'-c'

             A new LL with properly adjusted next and random pointer will form 

            a->c
            b->a
            c->b

            a'->c'
            b'->a'
            c'->b'

    
    */
        return ans;
    }
};