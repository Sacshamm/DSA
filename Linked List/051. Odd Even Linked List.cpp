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
       // ListNode* oddEvenList(ListNode* head) 
    // {
    //     if(!head) return head;
    //     ListNode *odd=head, *evenhead=head->next, *even = evenhead;
    //     while(even && even->next)
    //     {
    //         odd->next = odd->next->next;
    //         even->next = even->next->next;
    //         odd = odd->next;
    //         even = even->next;
    //     }
    //     odd->next = evenhead;
    //     return head;
    // }
    
     ListNode* oddEvenList(ListNode* head) {
         if(head==0 || head->next==0) return head;
         ListNode *odd=head ,*evenhead=head->next,*even=evenhead;// even head stores startig index of even node 
         
         while(even!=0 && even->next!=0){
             odd->next=even->next;//1->3->5
             odd=odd->next;
             even->next=odd->next;//2->4->null
             even=even->next;
         }
         odd->next=evenhead;//1,3,5,2,4,null
         return head;
     }
};
