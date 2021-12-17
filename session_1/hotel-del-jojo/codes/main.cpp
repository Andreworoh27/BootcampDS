#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct
struct Room
{
    char roomnum[7];
    char place[50];
    long long price;
};
struct Customer
{
    char custnum[5];
    char name[25];
    int age;
    char event[100];
    char place[50];
    int year;
    Room n;
};
//global var 
Customer n[100];
int hapus[100]={0};
int now=3;
int counterhapus=0;
char generate[7]="C003";
int idxgenerate=3;


//utilities
void menu();

void import_data_from_file(){
    FILE * fp = fopen("../customer/customer_data.txt","r");
    char temp[225];
    int counter=0;
    for(int i=0;!(feof(fp));i++){
        fscanf(fp,"%[^,],%[^,],%d,%[^,],%[^,],%d,%[^\n]\n",n[i].custnum,n[i].name,&n[i].age,n[i].event,n[i].place,&n[i].year,n[i].n.roomnum);
        counter++;
    }
    fclose(fp);
    puts("data after import from file");
    for (int i=0;i<counter;i++){
        printf("%s %s %d %s %s %d %s\n",n[i].custnum,n[i].name,n[i].age,n[i].event,n[i].place,n[i].year,n[i].n.roomnum);
    }
    for (int i=0;i<3;i++){
        hapus[i]=i;
    }
}

void autoadd(){
    for (int i=0;i<now;i++){
        int flag=0;
        for (int j=0;j<counterhapus;j++){
            if (i==hapus[j]){
                flag=1;
                break;
            }
        }
        if (flag==1){
            continue;
        }
        else{
            char temp[7];
            for (int i=0;i<5;i++){
                if (i==idxgenerate){
                    // printf("before :%s\n",generate);
                    generate[idxgenerate]+=1;
                    temp[i]=generate[i];
                    // printf("after :%s\n",generate);
                }
                else{
                    temp[i]=generate[i];
                }
            }
            strcpy(n[now].custnum,temp);
            break;
        }
    }
}

void read(){
    for (int i=0;i<now;i++){
        printf("\n\nCustomer ke %d:\n",i+1);
        printf("Customer code : %s\n",n[i].custnum);
        printf("Customer name : %s\n",n[i].name);
        printf("Customer age : %d\n",n[i].age);
        printf("Customer Cause of death : %s\n",n[i].event);
        printf("Customer resting place : %s\n",n[i].place);
        printf("Customer year : %d\n",n[i].year);
        // printf("Customer room : %)
    }
    menu();
}

void create(){
    autoadd();
    printf("customer number now: %s\n",n[now].custnum);
    printf("Name (lowercase letters) :");
    scanf("%s",n[now].name);getchar();

    do{
    printf("Age :");
    scanf("%d",&n[now].age);getchar();
    }while(n[now].age>100 || n[now].age<0);

    printf("Year :");
    scanf("%d",&n[now].year);getchar();
    printf("Cause of death (max 225 letrers) :");
    scanf("%[^\n]",n[now].event);getchar();
    printf("Resting Place (max 225 letters): ");
    scanf("%s",n[now].place);getchar();
    now++;
    menu();
}

void menu(){
    puts("Hotel Del Jojo");
    puts("1. Add new customer");
    puts("2. Read data");
    puts("3.Update data");
    puts("4. Remove data");
    puts("5. exit");
    printf("Choice [1-5] >>");
    int choice;
    scanf("%d",&choice); getchar();
    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        read();
        break;
    case 3:
        // update();
        break;
    case 4:
        // remove();
        break;
    case 5:
        exit(1);
        break;
    default:
        puts("input invalid");
        system("cls");
        menu();
        break;
    }
}

int main(){
    FILE * fp = NULL;
    import_data_from_file();
    menu();
}

