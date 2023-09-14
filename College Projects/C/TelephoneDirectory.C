#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[60];
    char phone[60];
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int contact_count=0;

void menu() {
    printf("\n");
    printf("---PHONEBOOK---\n");
    printf("1) VIEW CONTACTS (A-Z)\n");
    printf("2) VIEW CONTACTS (Z-A)\n");
    printf("3) SEARCH BY NAME\n");
    printf("4) SEARCH BY NUMBER\n");
    printf("5) ADD NEW CONTACT\n");
    printf("6) RENAME CONTACT\n");
    printf("7) CHANGE NUMBER\n");
    printf("8) DELETE CONTACT\n");
    printf("9) EXIT\n");
    printf("\n");
}

void display() {
    Node *temp = head;
    printf("\n----CONTACT DETAILS-----\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Phone Number: %s\n", temp->phone);
        printf("\n");
        temp = temp->next;
    }
}

void display_rev() {
    Node *temp = tail;
    printf("\n----CONTACT DETAILS-----\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Phone Number: %s\n", temp->phone);
        printf("\n");
        temp = temp->prev;
    }
}

void search_name(char *sname) {
    if (contact_count == 0) {
        printf("PHONEBOOK IS EMPTY!\n");
        return;
    }
    int low = 0;
    int high = contact_count - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        Node *temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        if (strcmp(temp->name, sname) == 0) {
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            return;
        }
        else if (strcmp(temp->name, sname) < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("%s CONTACT NOT FOUND!\n", sname);
}

void search_no(char *sno) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->phone, sno) == 0) {
            printf("Name: %s\n", temp->name);
            printf("Phone Number: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("%s: NO SUCH PHONE NUMBER IN PHONEBOOK!!\n", sno);
}

void del_con(char* sname,int cnt){
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, sname) == 0) {
            if (temp == head && temp == tail) {
                head = NULL;
                tail = NULL;
            } else if (temp == head) {
                head = temp->next;
                head->prev = NULL;
            } else if (temp == tail) {
                tail = temp->prev;
                tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            if(cnt==0){
                printf("\nCONTACT DELETED SUCCESSFULLY!\n");
            }
            if(cnt==1){
                printf("\nCONTACT RENAMED SUCCESSFULLY\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("\nNO SUCH CONTACT ON PHONEBOOK!\n");
}

void add_no(char *sname, char *sno,int cnt) {
    Node *new_cont = (Node *) malloc(sizeof(Node));
    strcpy(new_cont->name, sname);
    strcpy(new_cont->phone, sno);

    if (head == NULL) {
        new_cont->prev = NULL;
        new_cont->next = NULL;
        head = new_cont;
        tail = new_cont;
    } else {
        Node *temp = head;
        while (temp != NULL && strcmp(temp->name, sname) < 0) {
            temp = temp->next;
        }

        if (temp == NULL) {
            new_cont->prev = tail;
            new_cont->next = NULL;
            tail->next = new_cont;
            tail = new_cont;
        } else if (temp == head) {
            new_cont->prev = NULL;
            new_cont->next = head;
            head->prev = new_cont;
            head = new_cont;
        } else {
            new_cont->prev = temp->prev;
            new_cont->next = temp;
            temp->prev->next = new_cont;
            temp->prev = new_cont;
        }
    }
    if(cnt==0){
    printf("\nCONTACT SAVED SUCCESSFULLY\n");
    }
}

void rename(char* sname){
    char nm[60];
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, sname) == 0) {
            printf("ENTER THE NEW NAME OF THE CONTACT: ");
            scanf("%s",nm);
            add_no(nm,temp->phone,1);
            del_con(temp->name,1);
            return;
        }
        temp = temp->next;
    }
    printf("%s CONTACT NOT FOUND! \n", sname);
}

void reno(char* sname){
    char nm[60];
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, sname) == 0) {
            printf("ENTER THE NEW NUMBER: ");
            scanf("%s",nm);
            strcpy(temp->phone,nm);
            return;
        }
        temp = temp->next;
    }
    printf("%s CONTACT NOT FOUND! \n", sname);
}

int main() {
    int choice=0;
    char sname[30];
    char sno[30];
    int no;
    do{
        menu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display();
                break;
            case 2:
                display_rev();
                break;
            case 3:
                printf("\nENTER THE NAME: ");
                scanf("%s",sname);
                search_name(sname);
                break;
            case 4:
                printf("\nENTER THE NUMBER: ");
                scanf("%s",sno);
                search_no(sno);
                break;
            case 5:
                printf("\nENTER THE NUMBER OF CONTACTS YOU WANT TO ADD:\n");
                scanf("%d",&no);
                for(int i=0;i<no;i++){
                    printf("\nENTER THE NAME OF THE CONTACT TO ADD: ");
                    scanf("%s",sname);
                    printf("\nENTER THE PHONE NUMBER OF THE CONTACT : ");
                    scanf("%s",sno);
                    add_no(sname,sno,0);
	                contact_count++;
                }
                break;
            case 6:
                printf("\nENTER THE NAME OF CONTACT TO RENAME: \n");
                scanf("%s",sname);
                rename(sname);
                break;
            case 7:
                printf("\nENTER THE NAME OF CONTACT TO CHANGE NUMBER: \n");
                scanf("%s",sname);
                reno(sname);
                break;
            case 8:
                printf("\nENTER THE NAME OF THE CONTACT TO BE DELETED: ");
                scanf("%s",sname);
                del_con(sname,0);
                contact_count--;
                break;
            default:
                break;

        }
    }while(choice!=9);
    

    return 0;
}

