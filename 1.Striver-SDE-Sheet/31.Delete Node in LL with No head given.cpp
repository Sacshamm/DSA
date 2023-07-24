class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;//replace node val with next
        node->next = node->next->next;//make new link with node ke next ke next ke sath
    }
};
