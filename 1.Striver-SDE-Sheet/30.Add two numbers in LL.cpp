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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* NN = new ListNode();//to store new list
        ListNode* temp = NN;
        int carry=0;

        while(l1||l2||carry){
            int sum = 0;
            //if l1 not null then add
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            // if l2 not null then add 
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }

            sum+=carry;
            carry = sum/10;//reverse addition 10 ka carry hoga 1

            ListNode* newNode = new ListNode(sum%10);//reverse addition 10 ki value hogi 0
            temp->next = newNode;//connect node
            temp=temp->next; 
        }
        return NN->next;//NN is null but its next is head of new LL
    }
};
