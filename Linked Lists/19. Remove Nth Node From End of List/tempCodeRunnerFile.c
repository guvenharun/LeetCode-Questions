    struct ListNode* prev = NULL;
//     struct ListNode* current = head;
//     struct ListNode* forward = head;  

//     for (int i = 0; i < n; i++) {
//         if (forward == NULL) { 
//             return head;
//         }
//         forward = forward->next;
//     }

//     if (forward == NULL) {
//         struct ListNode* temp = head;
//         head = head->next;
//         return head;
//     }

//     while (forward != NULL) {
//         prev = current;
//         current = current->next;
//         forward = forward->next;
//     }

//     prev->next = current->next;

//     return head;
// }