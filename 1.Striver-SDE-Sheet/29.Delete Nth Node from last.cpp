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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //      if(head->next==0) return 0;
        
    //     int count=0;
    //     ListNode *temp=head;
    //     while(temp!=0){
    //         temp=temp->next;
    //         count++;
    //     }
        
    //     int node=count-n;
    //     if(node==0) return head->next;
        
    //      ListNode*prev=head;
    //     for(int i=1;i<node;i++){
    //        prev=prev->next;
    //     }
    //     ListNode*del=prev->next;
    //     prev->next=del->next;
    //     delete del;
    //     return head;
    // }

      ListNode *fast = head, *slow = head;
	    while(n--) {
           fast = fast -> next;//iterate first n nodes using fast
        }
        
	    if(!fast) return head -> next;// if fast is already null, it means we have to delete head itself. So,just return next of head
        
	     while(fast -> next){// iterate till fast reaches the last node of list
		    fast = fast -> next;
            slow = slow -> next;      
        }
         
	      slow -> next = slow -> next -> next; // remove the nth node from last
	      return head;
    }
};
