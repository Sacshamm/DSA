class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode*temp = head;
        int len = 1;

        //calc total lenght of ll
     while(temp->next){
          len++;
          temp = temp->next;
     }

     //point end node to starting(make it a circular ll)
     temp->next = head;

     //if k is > len then reduce it
     k = k%len;
     k = len-k; //part after which ll to be rotated

     //now temp reaches at 3 consider eg 1 2 3 4 5 and k=2
     while(k--) temp=temp->next;

     //make 4 as head
     head = temp->next;

     //point 3 to null
     temp->next = NULL;

     return head;
    }
};
