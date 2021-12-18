void autoadd(Customer * current,Customer * head){
    Customer* temp = head;
    while (temp -> ptr != NULL){
        temp = temp->ptr;
    }
    // printf("dari struct:%s\n",temp->custnum);
    char tempnum[6];
    strcpy(tempnum,temp->custnum);
    // printf("dari struct:%s\n",temp->custnum);
    char dup[6];
    for (int i=0;i<6;i++){
        if (tempnum[i]>'0' && tempnum[i]<='9'){
            if (tempnum[i]=='9'){
                dup[i]='1';
                dup[i+1]='0';
                break;
            }
            else{
                tempnum[i]+=1;
                dup[i]=tempnum[i];
            }
        }
        else{
            dup[i]=tempnum[i];
        }
    }
    // printf("tempnum:%s\ndup: %s\n",tempnum,dup);
    strcpy(current->custnum,dup);
}

void create(Customer * head){
    Customer* current = (Customer*)malloc(sizeof(Customer));
    current->ptr=NULL;
    autoadd(current,head);
    Customer* temporary= head;
    while(temporary->ptr!=NULL){
        temporary= temporary->ptr;
    }
    temporary->ptr=current;

    printf("customer number now: %s\n",current->custnum);
    printf("Name (lowercase letters) :");
    scanf("%s",current->name);getchar();

    do{
    printf("Age :");
    scanf("%d",&current->age);getchar();
    }while(current->age>100 || current->age<0);

    printf("Year :");
    scanf("%d",&current->year);getchar();
    printf("Cause of death (max 225 letrers) :");
    scanf("%[^\n]",current->event);getchar();
    printf("Resting Place (max 225 letters): ");
    scanf("%s",current->place);getchar();

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
        strcpy(current->n.place,"Pantai");
        current->n.price=3000000;
    }
    else if (strcmp(temp,"Rooftop")==0){
        strcpy(current->n.place,"Rooftop");
        current->n.price=4500000;
    }
    else if (strcmp(temp,"Taman")==0){
        strcpy(current->n.place,"Taman");
        current->n.price=5000000;   
    }
    else{
        strcpy(current->n.place,"Bar");
        current->n.price=1250000;
    }
}

void read(Customer*head){
    Customer * current = head;
    printf("|   |  ID  |  Name  | Age  |   Room   |\n");
    printf("|---|------|--------|------|----------|\n");
    for (int i=1;i<=now;i++){
        printf("| %d |%-6s| %-6s |  %d  | %-8s |\n",i,current->custnum,current->name,current->age,current->n.place);
        current=current->ptr;
    }
}

void remove(Customer ** head, char *code){
    Customer * current = *head;
    Customer * previous = * head;
    int position=1;
    while (1){
        if (strcmp(current -> custnum,code)==0){
            break;
        }
        else{
            current = current -> ptr;
            position++;
        }
    }

    if (position==1){
        *head= current->ptr;
        current->ptr=NULL;
        free(current);
    }

    else if (position!=now){
        int i=1;
        while (i!=position-1){
            previous = current;
            current= current->ptr;
            i++;
        }
        previous->ptr= current->ptr;
        free(current);
        current= NULL;
    }

    else if (position == now){
        while (current->ptr!=NULL){
            previous=current;
            current=current->ptr;
        }
        previous->ptr=NULL;
        free(current);
    }

    now--;
}

void update(Customer* head){
    int valid=0;
    char temp[6];
    Customer * id;

    do{
        printf("Enter ID: ");
        scanf("%s",temp);getchar();
        Customer * curr = head;
        while (curr->ptr!=NULL){
            if (strcmp(curr->custnum,temp)==0){
                valid=1;
                id= curr;
                break;
            }
            else{
                curr = curr->ptr;
            }
        }
        if (strcmp(curr->custnum,temp)==0){
            valid=1;
        }
    }while(valid==0);

    // printf("%s",id->custnum);
    char newplace[25];
    int flag=0;
    do{
        printf("Insert new room (Pantai,Rooftop,Taman,Bar): ");
        scanf("%s",newplace);getchar();
        if(strcmp(newplace,"Pantai")==0 || strcmp(newplace,"Rooftop")==0 || strcmp(newplace,"Taman")==0 || strcmp(newplace,"Bar")==0){
            flag=1;
        }
    }
    while(flag==0);

    if (strcmp(newplace,"Pantai")==0){
        strcpy(id->n.place,"Pantai");
        strcpy(id->n.roomnum,"R001");
        id->n.price=3000000;
    }
    else if (strcmp(newplace,"Rooftop")==0){
        strcpy(id->n.place,"Rooftop");
        strcpy(id->n.roomnum,"R002");
        id->n.price=4500000;
    }
    else if (strcmp(newplace,"Taman")==0){
        strcpy(id->n.place,"Taman");
        strcpy(id->n.roomnum,"R003");
        id->n.price=5000000;   
    }
    else{
        strcpy(id->n.place,"Bar");
        strcpy(id->n.roomnum,"R004");
        id->n.price=1250000;
    }
}

void push(Customer * head){
    char input;
    printf("do you want to push data to database? (y/n)");
    scanf("%c",&input);
    if (input=='y'){
        FILE * fp=fopen("../customer/customer_data.txt","w");
        Customer * current = head;
        while (current->ptr!=NULL){
            fprintf(fp,"%s,%s,%d,%s,%s,%d,%s\n",current->custnum , current->name , current->age , current->event , current->place , current->year , current->n.roomnum);
            current= current->ptr;
        }
        fprintf(fp,"%s,%s,%d,%s,%s,%d,%s\n",current->custnum , current->name , current->age , current->event , current->place , current->year , current->n.roomnum);
        fclose(fp);
    }
    else if (input=='n'){
        puts("data tidak di kirim ke database");
    }
    else{
        puts("input salah");
        push(head);
    }
}