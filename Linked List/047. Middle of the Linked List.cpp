class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*temp=head;
        int count = 0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
         for(int i = 0; i < count/2; i++)// traverse till N/2th node to find the middle
            head = head -> next;
        return head;
        
    }
    //  ListNode* middleNode(ListNode* head) {
    //     ListNode *slow = head, *fast = head;
    //     while (fast && fast->next)
    //         slow = slow->next, fast = fast->next->next;
    //     return slow;
    // }
};
