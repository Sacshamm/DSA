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
    
//     TC-O(n) SC also O(n)
//     ListNode *detectCycle(ListNode *head){
//         unordered_map<ListNode*,int>mp;
//         ListNode *temp=head;
        
//         while(temp!=NULL){
//             mp[temp]++;
//                 if(mp[temp]==2) return temp;
//             temp=temp->next;
//         }
//         return NULL;
//     }
    
    //TC O(n) and SC O(1)
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode *st_pt=head;
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(st_pt!=slow){
                    slow = slow->next;
                    st_pt = st_pt->next;
                }
                return st_pt;
            }
        }
        return 0;
    }
};
