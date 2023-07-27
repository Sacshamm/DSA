/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //also can be solved using map 
 //very brute force

 //cycle detection method
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next != NULL){
            //first find if there is cycle or not
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                //now there is cycle
                //to find the meeting point 
                //set slow at start and start increasing slow and fast by one step until they dont meet
                slow=head;
                while(slow!=fast){
                    slow = slow->next;
                    fast=fast->next;
                }
                //if they meet return node
                return slow;
            }

        }
        return NULL;
    }
};
