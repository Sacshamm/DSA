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

    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        //staring from same position
        //slow is moving by 1 step and fast moving by 2 step
        //it is evident that when fast covers x distance at that time slow is at x/2.
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    // ListNode* middleNode(ListNode* head) {
    //     ListNode*temp=head;
    //     int count = 0;
    //     //count total length
    //     while(temp!=NULL){
    //         temp=temp->next;
    //         count++;
    //     }
    //     //calculate middle
    //      for(int i = 0; i < count/2; i++)// traverse till N/2th node to find the middle
    //         head = head -> next;
    //     return head;
        
    // }

};
