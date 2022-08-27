class Solution {
public:
    
       ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *nextNode=head;
         ListNode *current=head;
        while (current!=0) {
            nextNode = nextNode->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};
