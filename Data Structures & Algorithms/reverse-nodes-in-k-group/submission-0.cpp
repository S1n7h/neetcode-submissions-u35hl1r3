class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode* cur = head;     
        while(cur){
            cur = cur->next;
            length++;
        }
        cur = head;

        ListNode* newhead = nullptr;
        ListNode* after;
        ListNode* newtails = nullptr;
        ListNode* newtails2 = nullptr;

        for (int i = 0 ; i < length/k ; i++){
            if(i == 0) {
                after = cur->next;
            }
            int subsize = 0;
            while (subsize < k){
                if (subsize == 0){
                    newtails2 = newtails;
                    newtails = cur;
                    cur->next = nullptr;
                }
                if (i == 0 && subsize == k-1) newhead = cur;  // ✅ assign correct head
                if (subsize == k - 1 && i > 0){
                    newtails2->next = cur;  
                }
                if (subsize != k - 1) {
                    ListNode* afternext = after ? after->next : nullptr; // ✅ null check
                    after->next = cur;
                    cur = after;
                    after = afternext;
                } else {
                    cur = after;
                    if (after) after = after->next; // ✅ avoid null deref
                }
                subsize++;                
            }
            newtails->next = cur;
            if (cur) after = cur->next; // ✅ keep after in sync
        }
        return newhead ? newhead : head; // ✅ fallback if k > length
    }
};
