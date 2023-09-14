#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char pass[20] = "uk.off"; // Admin password
int top=-1;
int st[60];
void push(int sap){
    if(top==60){
        printf("All voters have voted!\n");
        return;
    }else{
        st[++top]=sap;
    }
}



struct Candidate* head = NULL;
int valid_sap[60]={18428,17803,18160,18207,17939,17881,18410,18487,18036,18212,18214,18164,18203,19054,18099,18187,18647,18138,17691,18189,18099,18199,18566,18591,17944,18753,18648,18218,17689,18748,17953,18652,19120,17957,18762,18000,18401,18180,17820,17846,18684,17629,18729,18245,18194,18564,17919,18633,18754,17646,17924,18526,17702,18720};
char std_names[60][60]={"MAYANK GARG",
  "NUPUR KHATRI",
  "VASU CHAUDHARY",
  "ADITYA RATHORE",
  "ANNIESHA KULLU",
  "VIBHU DIXIT",
  "RAVI PHOUR",
  "GAURI GOYAL",
  "PRACGI GUPTA",
  "AKSHAT MALIK",
  "SHREYAN KAMBOJ",
  "SHIVANGI RAJPUT",
  "GARIMA ANAND",
  "RISHABH RAWAT",
  "LOKESH SHARMA",
  "ANIKA CHAUDHARY",
  "VAISHNAVI",
  "DRISHTI GUPTA",
  "RADHAMOHAN",
  "DISHITA",
  "LOKESH",
  "AYUSH RAWAT",
  "MAYANK AGARWAL",
  "NAMAN KUMAR",
  "SATVIK KUMAR",
  "MAYANK KASHYAP",
  "DEEKSHA TOMER",
  "VAIBHAV BISHT",
  "HIMANSHU",
  "HARSHIT PANT",
  "PRIYANSHI MITTAL",
  "SAKSHAM BHASKAR",
  "SANIYA IQBAL",
  "YASH GUPTA",
  "PRATYUSH MISHRA",
  "ALKA SINGH",
  "ANIRUDH NEGI",
  "DIVYADEEP KAUR",
  "PRIYANSHI YADAV",
  "YASH SHUKLA",
  "RISHAB RANJAN",
  "MOHD ALTAMASH",
  "KRISHNA GUPTA",
  "SAHIL SINGH",
  "ARYAN GUPTA",
  "ARSHIYA MALIK",
  "GRACY MEHRA",
  "PRIYANSHU",
  "ABHAY SHUKLA",
  "SHUBHAM KUMAR",
  "JEET MISHRA",
  "VAISHNO PATHAK",
  "AMAN ASHUTOSH",
  "KRISHNA SHARMA"
};



struct Candidate {
    char name[20];
    char party[20];
    int votes;
    struct Candidate* next;
};


struct Candidate* new_candidate(char name[], char party[]) {
    struct Candidate* node = (struct Candidate*) malloc(sizeof(struct Candidate));
    strcpy(node->name, name);
    strcpy(node->party, party);
    node->votes = 0;
    node->next = NULL;
    return node;
}


void add_candidate(char name[], char party[]) {
    struct Candidate* node = new_candidate(name, party);
    if (head == NULL) {
        head = node;
    }
    else {
        struct Candidate* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}


void leaders() {
    int i=1;
    printf("\n\t\tNAME\t\t\t        PARTY\n");
    printf("--------------------------------------------------\n");
    struct Candidate* temp = head;
    while (temp != NULL) {
        printf("%d\t\t%s\t\t%s\n",i,temp->name, temp->party);
        temp = temp->next;
        i++;
    }
}

bool in_st(int sap){
    if(top==-1 ){
        return false;
    }else{
        for(int i=top;i>=0;i--){
            if(st[i]==sap){
                return true;
            }
        }
    }
}


void menu() {
    printf("\n---DEHRADUN ELECTIONS 2023---\n");
    printf("PRESS 1 TO VOTE\n");
    printf("PRESS 2 TO VIEW CURRENT RESULT (ADMIN ONLY)\n");
    printf("PRESS 3 TO ADD NEW CANDIDATE(S) (ADMIN ONLY)\n");
    printf("PRESS 0 TO EXIT\n");
}


void vote() {
    int choice, valid_voter = 0;
    int sap;
    char voter_name[30];

    printf("\nENTER LAST FIVE DIGITS OF YOUR SAP ID: ");
    scanf("%d",&sap);
    if(in_st(sap)==true){
                printf("YOU HAVE ALREADY VOTED ONCE,YOU CANT VOTE AGAIN!\n");
                return;
            }
    for (int i = 0; i < 60; i++) {
        if (sap == valid_sap[i]) {
            valid_voter = 1;
            printf("NAME:%s\nSAP ID:10000%d",std_names[i],valid_sap[i]);
            strcpy(voter_name,std_names[i]);
            break;
        }
    }

    if (valid_voter) {

        printf("\nHello %s,Select the candidate you want to vote for:\n",voter_name);
        leaders();
        printf("\n");
        scanf("%d", &choice);

        struct Candidate* temp = head;
        int i = 1;
        while (temp != NULL && i != choice) {
            temp = temp->next;
            i++;
        }

        if (temp != NULL && i == choice) {
            temp->votes++;
            push(sap);
            printf("\nThank you for voting!\n");
        } else {
            printf("\nInvalid choice. Please select a valid candidate.\n");
        }
    }else {
        printf("\nSorry, you are not a valid voter. Please check your name and try again.\n");
    }
}




int validate_password() {
    char password[20];
    printf("\nEnter the admin password: ");
    scanf("%s", password);
    if (strcmp(password, pass) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void result() {
    int i=1;
    if (validate_password()) {
        printf("\nCURRENT ELECTION RESULTS\n");
        printf("\n\t\tNAME\t\t\t\t\tPARTY\tVOTES\n");
        printf("-----------------------------------------------------------\n");
       struct Candidate* temp = head;
        while (temp != NULL) {
        printf("%d\t\t%s\t\t %s\t\t%d\n",i,temp->name, temp->party,temp->votes);
        temp = temp->next;
        i++;
    }
    }
    else {
        printf("\nAccess denied. Invalid password.\n");
    }
}

void addc(){
    if(validate_password()){
        int n;
        char name[50], party[20];
        printf("ENTER THE NUMBER OF CANDIDATES YOU WANT TO ADD: ");
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            printf("Enter the name and party of the candidate: \n");
            scanf(" %s %s", name, party);
            add_candidate(name,party);
        }
    } else {
        printf("INCORRECT PASSWORD! ACCESS DENIED\n");
    }
}


int main() {
    add_candidate("Dr Biplab Dhar   ", "BJP");
    add_candidate("Dr Surjeet Chahal", "AAP");
    add_candidate("Dr Preeti Gupta  ", "INC");
    add_candidate("Pankaj Verma     ", "BSP");
    add_candidate("Dr Nafees Ahamad ", "UKD");

    int choice;
    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vote();
                break;
            case 2:
                result();
                break;
            case 3:
                addc();
            case 0:
                continue;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    } while (choice != 0);

    struct Candidate* temp = head;
    while (temp != NULL) {
        struct Candidate* next_node = temp->next;
        free(temp);
        temp = next_node;
    }

    return 0;
}
