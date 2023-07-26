/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // bool hasCycle(ListNode *head) {
    //     map<ListNode*,int>mp;

    //     while(head){
    //         mp[head]++;
    //         head = head->next;
    //         if(mp[head]>1) return true;
    //     }
    //     return false;
    // }

     bool hasCycle(ListNode *head) {
       ListNode * fast = head;
       ListNode * slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
