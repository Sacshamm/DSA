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
    ListNode* deleteMiddle(ListNode* head) {
      
        if(head==NULL||head->next==NULL) return NULL;
        ListNode*temp=head;
        int count = 0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        ListNode *mid=head;
        for(int i=0;i<(count/2)-1;i++){
            mid=mid->next;
        }
      //  cout<<mid->val;
        
        ListNode* del=mid->next;
         mid->next=del->next; 
        del->next==NULL;
      return head;  
    }
    
    
    //intuition : in a list of 2 nodes 2nd node is middle. So we have to be on 1st node to delete second node...........To do this we are directtly assigning out fast to head>next>next that is for the minimum base case
//     ListNode* deleteMiddle(ListNode* head) {
//     if (head->next == nullptr)
//         return nullptr;
//     auto slow = head, fast = head->next->next;
//     while (fast != nullptr && fast->next != nullptr) {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     slow->next = slow->next->next;
//     return head;
// }

};
