class Solution {
public:
    ListNode* rev(ListNode* slow){
        ListNode*curr = slow;
        ListNode*NN = slow;
        ListNode*prev = NULL;

        while(curr){
            NN=NN->next;
            curr->next = prev;
            prev = curr;
            curr = NN;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;

        //find middle of ll
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse right half from middle of ll
        slow->next = rev(slow->next);
        slow = slow->next;

        //start checking left half with right half
        while(slow){
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
