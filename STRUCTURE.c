Q1) Write a C program to create a structure called student to store your rollno, 
name, age. Create an array to input 5 students data and then create an UDF to 
display details where age>=20. 

#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int age;
};

void display(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        if (s[i].age >= 20) {
            printf("%d %s %d\n", s[i].roll, s[i].name, s[i].age);
        }
    }
}

int main() {
    struct Student s[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &s[i].roll);
        getchar();  // consume newline after roll
        fgets(s[i].name, 50, stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0;  // remove newline
        scanf("%d", &s[i].age);
    }
    display(s, 5);
    return 0;
}

Q2) Write a program to create a structure for products of a super market. Store 
product no, name and cost for N products using dynamic memory allocation. 
Display the products whose cost is in between 100 rupees to 1000 rupees. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int pno;
    char name[50];
    float cost;
};

void display(struct Product p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i].cost >= 100 && p[i].cost <= 1000) {
            printf("%d %s %.2f\n", p[i].pno, p[i].name, p[i].cost);
        }
    }
}

int main() {
    struct Product *p;
    int n;

    scanf("%d", &n);
    p = malloc(n * sizeof(struct Product));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].pno);
        getchar();  // consume newline after number input
        fgets(p[i].name, 50, stdin);
        p[i].name[strcspn(p[i].name, "\n")] = 0;  // remove trailing newline
        scanf("%f", &p[i].cost);
    }

    display(p, n);

    free(p);
    return 0;
}
