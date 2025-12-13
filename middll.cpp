class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        
        // 1️⃣ Count the length
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        // middle index (0-based indexing)
        int middleIndex = length / 2;
        
        // 2️⃣ Move to the middleIndex-th node
        temp = head;
        for (int i = 0; i < middleIndex; i++) {
            temp = temp->next;
        }
        
        return temp;
    }
};
