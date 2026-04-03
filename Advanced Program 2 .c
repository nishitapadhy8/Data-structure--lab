#include <stdio.h>
#include <stdlib.h>

struct node {
    int acno;
    char name[50];
    float balance;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *temp, *ptr;
    int i;
    for (i = 0; i < n; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter account number: ");
        scanf("%d", &temp->acno);
        printf("Enter name: ");
        scanf("%s", temp->name);
        printf("Enter balance: ");
        scanf("%f", &temp->balance);

        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
            head = temp;
        else {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
        }
    }
}

void total_balance() {
    struct node *temp = head;
    float total = 0;
    while (temp != NULL) {
        total += temp->balance;
        temp = temp->next;
    }
    printf("\nTotal Balance of all customers = %.2f\n", total);
}

int main() {
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);
    create(n);
    total_balance();
    return 0;
}