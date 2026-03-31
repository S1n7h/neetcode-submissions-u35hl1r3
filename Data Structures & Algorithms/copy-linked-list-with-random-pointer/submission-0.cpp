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
        if(!head)   return nullptr;
        Node* cur = head;
        while(cur){ //makes clones
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;            
        }cur = head;
        
        while(cur){     //updates random
            if (cur->random)    cur->next->random = cur->random->next; 
            else cur->next->random = nullptr;
            cur = cur->next->next;
        }Node* new_head = head->next; 

        Node* original = head;       
        cur = new_head;

        while(original){
            original->next = original->next->next;
            original = original->next;
            if (cur->next){
            cur->next = cur->next->next;
            cur = cur->next;
            }
        }
        return new_head;
    }
};
