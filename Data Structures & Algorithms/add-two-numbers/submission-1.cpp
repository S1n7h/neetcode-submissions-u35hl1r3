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
        ListNode* dl1 = l1;
        ListNode* dl2 = l2;

        int sum = 0; 
        int carry = 0;

        ListNode* head = nullptr;
        ListNode* cur = nullptr;

        while (dl1 && dl2){
            ListNode* temp = new ListNode((dl1->val + dl2->val + carry) % 10);            
            carry = (dl1->val + dl2->val + carry) / 10;
            if (head == nullptr){
                head = temp;
                cur = temp;
            }else{
                cur->next = temp;
                cur = cur->next;
            }
            dl1 = dl1->next;
            dl2 = dl2->next;

        }while (dl1){
            ListNode* temp = new ListNode((dl1->val + carry) % 10);            
            carry = (dl1->val + carry) / 10;
            dl1 = dl1->next;
            cur->next = temp;
            cur = cur->next;
        }while (dl2){
            ListNode* temp = new ListNode((dl2->val + carry) % 10);            
            carry = (dl2->val + carry) / 10;
            dl2 = dl2->next;
            cur->next = temp;
            cur = cur->next;
        }if (carry){
            ListNode* temp = new ListNode(carry);
            cur->next = temp; 
        }
        return head;
    }
};
