class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int>mp;//store adress of node in map not node val
        while(headA){
            mp[headA]++;
            headA=headA->next;
        }
        while(headB){
            if(mp[headB]>0) return headB;//if same adress is already then it is intersection 
            else headB=headB->next;
        }
        return NULL;
    }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode *h1 = headA;
    //     ListNode *h2 = headB;

    //     while(h1!=h2){
    //         if(h1==NULL) h1=headB;
    //         h1=h1->next;

    //         if(h2==NULL) h2=headA;
    //         h2=h2->next;
    //     }
    //     return h1;
    //}
};
