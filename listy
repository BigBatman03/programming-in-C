#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* removeDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* current = head;
    
    while (current) {
        int duplicate = 0;
        while (current->next && current->val == current->next->val) {
            ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
            duplicate = 1;
        }
        
        if (duplicate) {
            prev->next = current->next;
            free(current);
        } else {
            prev = current;
        }
        
        current = prev->next;
    }
    
    head = dummy->next;
    free(dummy);
    return head;
}

void append(ListNode** head, int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    
    if (!*head) {
        *head = newNode;
        return;
    }
    
    ListNode* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 2);
    append(&head, 3);
    append(&head, 3);
    append(&head, 4);
    
    printf("Oryginalna lista:\n");
    printList(head);
    
    head = removeDuplicates(head);
    
    printf("Lista po usunięciu duplikatów:\n");
    printList(head);
    
    return 0;
}
