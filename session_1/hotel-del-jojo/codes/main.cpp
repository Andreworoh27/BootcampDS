#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct
struct Room
{
    char roomnum[6];
    char place[50];
    long long price;
};
struct Customer
{
    char custnum[6];
    char name[25];
    int age;
    char event[100];
    char place[50];
    int year;
    Room n;
    Customer * ptr;
};
//global var
int now =0;

//utilities
#include "customer.h"
void menu(Customer * head);

void menu(Customer* head){
    puts("Hotel Del Jojo");
    puts("1. Add new customer");
    puts("2. Read data");
    puts("3. Update data");
    puts("4. Remove data");
    puts("5. exit");
    printf("Choice [1-5] >>");
    int choice;
    scanf("%d",&choice); getchar();
    switch (choice)
    {
    case 1:
        create(head);
        now++;
        menu(head);
        break;
    case 2:
        read(head);
        menu(head);
        break;
    case 3:
        read(head);
        update(head);
        push(head);
        menu(head);
        break;
    case 4:
        read(head);
        printf("Enter ID:");
        char code[6];
        scanf("%s",code);getchar();
        remove(&head,code);
        read(head);
        menu(head);
        break;
    case 5:
        puts("Hotel Del Jojo");
        exit(1);
        break;
    default:
        puts("input invalid");
        menu(head);
        break;
    }
}

void import_data_from_file(Customer * head){
    FILE * fp = fopen("../customer/customer_data.txt","r");
    FILE * room = fopen("../room/room.txt","r");
    char temp[225];
    Customer * current = head;
    for(int i=0;!(feof(fp));i++){
        fscanf(fp,"%[^,],%[^,],%d,%[^,],%[^,],%d,%[^\n]\n",current->custnum,current->name,&current->age,current->event,current->place,&current->year,current->n.roomnum);
        if (strcmp(current->n.roomnum,"R001")==0){
            strcpy(current->n.place,"Pantai");
            current->n.price=3000000;
        }
        if (strcmp(current->n.roomnum,"R002")==0){
            strcpy(current->n.place,"Rooftop");
            current->n.price=4500000;
        }
        if (strcmp(current->n.roomnum,"R003")==0){
            strcpy(current->n.place,"Taman");
            current->n.price=5000000;
        }
        if (strcmp(current->n.roomnum,"R004")==0){
            strcpy(current->n.place,"Bar");
            current->n.price=1250000;
        }
        now++;
        current= current->ptr;
    }
    fclose(fp);
    fclose(room);
    puts("data after import from file");
    Customer * current2=head;
    for (int i=0;i<now;i++){
        printf("%s %s %d %s %s %d %s\n",current2->custnum,current2->name,current2->age,current2->event,current2->place,current2->year,current2->n.roomnum);
        current2=current2->ptr;
    }
}

int main(){
    Customer * head = (Customer*) malloc(sizeof(Customer));
    head->ptr=NULL;
    Customer * current= (Customer*) malloc (sizeof(Customer));
    head->ptr=current;
    current->ptr=NULL;
    current = (Customer*) malloc (sizeof(Customer));
    current->ptr=NULL;

    Customer * address = head;
    while(address->ptr!=NULL){
        address= address->ptr;
    }
    address->ptr= current;

    import_data_from_file(head);
    menu(head);
}