
class Solution {
private:

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int acc = 0;
       ListNode *l = nullptr;
       ListNode *head = nullptr;
       while (l1 && l2) {
           int n = l1->val + l2->val + acc;
           acc = 0;
           if (n >= 10) {
               acc = 1;
               n = n - 10;
           }
           ListNode *node = new ListNode(n);
           if (l == nullptr) {
               l = node;
               head = l;
           } else {
               l->next = node;
               l = node;
           }
           l1 = l1->next;
           l2 = l2->next;
       }
       if (l1) {
           while (l1) {
               ListNode *node;
               int n = l1->val + acc;
               acc = 0;
               if (n >= 10) {
                   n = 0;
                   acc = 1;
               }
               node = new ListNode(n);
               l->next = node;
               l = node;
               l1 = l1->next;
           }
       }
       ListNode *node;
       if (l2) {
          while (l2) {
               int n = l2->val + acc;
               acc = 0;
               if (n >= 10) {
                   n = 0;
                   acc = 1;
               }
               node = new ListNode(n);
               l->next = node;
               l = node;
               l2 = l2->next;
           } 
       }
       if (acc) {
           node = new ListNode(acc);
           l->next = node;
           l = node;
       }
       return head;
    }
};
