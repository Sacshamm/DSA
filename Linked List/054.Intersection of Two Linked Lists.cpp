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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
         if(headA == NULL || headB == NULL) return NULL;
        ListNode *h1 = headA, *h2 = headB;
       
        while(h1 != h2) 
        {
            if(h1==nullptr) h1= headB;
            else h1=h1->next;
            if(h2==nullptr) h2= headA;
            else h2= h2->next;
        }
        return h1;         
    
    
    
    //using map
//       unordered_map <ListNode*, int> mp;
//         while(headA)
//         {
//             mp[headA]++;
//             headA=headA->next;
//         }
//         while(headB)
//         {
//             if(mp[headB]>0) return headB;
//             headB=headB->next;
//         }
//         return NULL;
    
    
    
//      // using length of two lists
    
//       int length1=0, length2=0;
//         ListNode *h1 = headA, *h2 = headB;
//         while(headA){
//             length1++;
//             headA=headA->next;  //length of LL-1
//         }
//         while(headB){
//             length2++;
//             headB=headB->next; //length of LL-2
//         }
        
//         int difference = abs(length1 - length2); //difference
       
//         if(length1 > length2) {
//             while(difference--) // moving the longerLL by the difference
//                 h1= h1->next;
//         }
//         else {
//             while(difference--)
//                 h2 = h2->next;
//         }
        
//         while(h1 && h2)
//         {
//             if(h1==h2)
//                 return h1;  // return when address become same
//             h1= h1->next;
//             h2= h2->next;
//         }
//         return nullptr; //NULL is returned when intersection isn't present.
    }   
    
};
