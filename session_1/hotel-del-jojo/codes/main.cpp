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
    FILE * room = fopen("../room/room.txt","r");
    char temp[225];
    int counter=0;
    for(int i=0;!(feof(fp));i++){
        fscanf(fp,"%[^,],%[^,],%d,%[^,],%[^,],%d,%[^\n]\n",n[i].custnum,n[i].name,&n[i].age,n[i].event,n[i].place,&n[i].year,n[i].n.roomnum);
        if (strcmp(n[i].n.roomnum,"R001")==0){
            strcpy(n[i].n.place,"Pantai");
            n[i].n.price=3000000;
        }
        if (strcmp(n[i].n.roomnum,"R002")==0){
            strcpy(n[i].n.place,"Rooftop");
            n[i].n.price=4500000;
        }
        if (strcmp(n[i].n.roomnum,"R003")==0){
            strcpy(n[i].n.place,"Taman");
            n[i].n.price=5000000;
        }
        if (strcmp(n[i].n.roomnum,"R004")==0){
            strcpy(n[i].n.place,"Bar");
            n[i].n.price=1250000;
        }
        counter++;
    }
    fclose(fp);
    fclose(room);
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
        printf("Customer room : %s\n",n[i].n.place);
        printf("Customer price :%lld\n",n[i].n.price);
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

    char temp[25];
    int flag=0;
    do{
    printf("Room type (Pantai,Rooftop,Taman,Bar):");
    scanf("%s",temp);getchar();
    if(strcmp(temp,"Pantai")==0 || strcmp(temp,"Rooftop")==0 || strcmp(temp,"Taman")==0 || strcmp(temp,"Bar")==0){
        flag=1;
    }
    }while(flag==0);

    if (strcmp(temp,"Pantai")==0){
        strcpy(n[now].n.place,"Pantai");
        n[now].n.price=3000000;
    }
    else if (strcmp(temp,"Rooftop")==0){
        strcpy(n[now].n.place,"Rooftop");
        n[now].n.price=4500000;
    }
    else if (strcmp(temp,"Taman")==0){
        strcpy(n[now].n.place,"Taman");
        n[now].n.price=5000000;   
    }
    else{
        strcpy(n[now].n.place,"Bar");
        n[now].n.price=1250000;
    }
    now++;
    menu();
}
void searching (){
    for (int i=0;i<now;i++){
        
    }
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