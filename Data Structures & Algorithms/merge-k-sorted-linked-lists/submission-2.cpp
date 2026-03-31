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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        int linkedlistsize = 0;
        for (int i = 0 ; i < lists.size() ; i++){//merges the lists
            ListNode* temphead = lists[i];
            while (temphead->next){
                temphead = temphead->next;linkedlistsize++;
            }linkedlistsize++;
            if (i < lists.size() - 1){
                temphead->next = lists[i+1];
            }else   temphead->next = nullptr;
        }
        ListNode* head = new ListNode(0, lists[0]);
        ListNode* cur = head->next;
        ListNode* cur2 = head->next;
        cur = head->next;
        while(cur){
            cout << cur->val << "  ";
            cur = cur->next;
        }cur = head->next;
        for (int i = 0 ; i < linkedlistsize; i++){
            int minimum = cur->val;
            for (int j = i ; j < linkedlistsize ; j++){
                if (cur2->val < minimum){
                    int temp = cur->val;
                    cur->val = cur2->val;
                    cur2->val = temp;
                    minimum = cur->val;
                }cur2 = cur2->next;
            }cur = cur->next;
            cur2 = cur;        
        }cur = head->next;
        cout << '\n';
        while(cur){
            cout << cur->val << "  ";
            cur = cur->next;
        }cur = head->next;
        return cur;
    }
};
