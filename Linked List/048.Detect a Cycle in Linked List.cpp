/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*It's a classic algo for detecting cycles in a linked list. We use two pointers to traverse the list: The first one is moving one node at the time and the second two nodes at the time. If there is a cycle, sooner or later pointers will meet and we return true. If the fast pointer reached the end of the list, that means there is no cycle and we can return false.

For reference: Floyd's Cycle Detection Algorithm

Time: O(n) - for traversing
Space: O(1) - nothing stored*/

class Solution {
public:
  
//O(N)................O(N)    
//         bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*,int> mp;
//         ListNode* temp= head;
//         while(temp!=NULL)
//         {
//             mp[temp]++;
//             temp=temp->next;
//             if(mp[temp]>1)
//                 return true;
//         }
//         return false;
        
//     }
  
  //O(N)................O(1)  
    bool hasCycle(ListNode *head) {      
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
