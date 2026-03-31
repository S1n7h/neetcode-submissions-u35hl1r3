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
    void reorderList(ListNode* head) {
        if (!head->next)    return;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondhead = slow->next;
        slow->next = nullptr;
        slow = slow->next;

        ListNode* temp; //points to the last number in the array.
        while (secondhead){
            temp = secondhead;
            secondhead = secondhead->next;
            temp->next = slow;
            slow = temp;
        }
        slow = head;
        //slow points to the start, temp points to the end

        while(temp && slow){
            ListNode* temp_next = temp->next;
            ListNode* slow_next = slow->next;
            slow->next = temp;
            temp->next = slow_next;
            slow = slow_next;
            temp = temp_next;  
        }
    }
};
