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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head;

        while(curr!=NULL){
            nextNode = nextNode->next; //move to next
            curr->next = prev;// break and update current link
            prev = curr;//move previous 
            curr = nextNode;//move curr
        }
        //at end both curr and nextNode will be null
        return prev;
    }
};
