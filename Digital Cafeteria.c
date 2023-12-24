#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *fpt;
typedef struct
{
    char id[10];
    int food;
    char name[20];
    int expense,menu;

} st_O;

st_O st_Data[50];
int n=0,i=0,j=0,nt=0;


void getData()
{
    fpt = fopen("Bill.txt", "r");
    fscanf(fpt, "%d", &n);
    for(i=1; i<=n; i++)
    {

        fscanf(fpt, "%s", st_Data[i].id);
        fscanf(fpt, "%s", st_Data[i].name);
        fscanf(fpt, "%d", &st_Data[i].menu);
        fscanf(fpt, "%d", &st_Data[i].expense);

    }
    fclose(fpt);

}

void menu_check()
{
    if(st_Data[i].menu==1)
    {
        printf("\tYour ordered Menu is(1): Khichuri with Meat (Price - 60 Taka).\n");
    }
    else if(st_Data[i].menu==2)
    {
        printf("\tYour ordered Menu is(2): Rice with Meat (Price - 60 Taka).\n");
    }
    else if(st_Data[i].menu==3)
    {
        printf("\tYour orderd Menu is(3): Rice with Curry (Price - 50 Taka).\n");
    }
}

void allData()
{
    printf("\n\n");
    for(i=1; i<=n; i++)
    {
        printf("\tStudent ID: %s\n", st_Data[i].id);
        printf("\tName: %s\n", st_Data[i].name);
        menu_check();
        printf("\tBill: %d Taka\n\n", st_Data[i].expense);
    }
}

void swap1()
{
    char t1[10];
    strcpy(t1,st_Data[i].id);
    strcpy(st_Data[i].id,st_Data[j].id);
    strcpy(st_Data[j].id,t1);

}
void swap2()
{
    char t2[50];
    strcpy(t2,st_Data[i].name);
    strcpy(st_Data[i].name,st_Data[j].name);
    strcpy(st_Data[j].name,t2);
}
void swap3()
{
    int t3;
    t3 = st_Data[i].menu;
    st_Data[i].menu = st_Data[j].menu;
    st_Data[j].menu = t3;
}
void swap4()
{
    int t4;
    t4 = st_Data[i].expense;
    st_Data[i].expense = st_Data[j].expense;
    st_Data[j].expense = t4;
}

void torder()
{
    int m1=0,m2=0,m3=0;
    getData();
    for(i=1; i<=n; i++)
    {
        if(st_Data[i].menu==1)
        {
            m1++;
        }
        else if(st_Data[i].menu==2)
        {
            m2++;
        }
        else if(st_Data[i].menu==3)
        {
            m3++;
        }
    }

    printf("\n\t\t\t\t===== Total Orders of Each Menu =====\n");
    printf("\n\n\t(1) Khichuri with Meat (Price - 60 Taka) = %d Plates.\n", m1);
    printf("\t(2) Rice with Meat (Price - 60 Taka) = %d Plates.\n", m2);
    printf("\t(3) Rice with Curry (Price - 50 Taka) = %d Plates.\n", m3);

}

int main()
{
    system("Color E1");
    int t=1;
    int option;
    int totalp;
    int student_number[100];
    int total = 0;
    int order_num, item_code;
    char ID[10];
    while(t==1)
    {
        system("cls");
        printf("\n\n");
        printf("\t\t========Digital Cafeteria========\t\t\t\t\t");
        printf("\n\n\n");

        ///Menu part.

        printf("\tSelect an Option: \n");
        printf("\n\t1. Order Food:\n");
        printf("\t2. Search A Students Invoice:\n");
        printf("\t3. Show All Invoices:\n");
        printf("\t4. Sort Students Data According To Their ID:\n");
        printf("\t5. Change Order:\n");
        printf("\t6. Total Orders of Each Menu\n");
        printf("\t7. Exit.\n");
        printf("\n\tChoose a Number: ");
        scanf("%d", &option);
        getc(stdin);
        switch (option)
        {
        case 1:
            system("cls");
            printf("\n\n");
            printf("\t\t\t===== Order Food =====\n\n");
            printf("\tHow many students data you want to take as Input: ");
            scanf("%d", &nt);
            getData();
            for(i=n+1; i<=n+nt; i++)
            {
                system("cls");
                getc(stdin);
                printf("\n\n");
                printf("\tDate : %s\n", __DATE__);
                printf("\ttime : %s\n\n", __TIME__);
                printf("\tYour student ID(%d) : ", i);
                gets( st_Data[i].id);
                printf("\n\tEnter your name(%d) : ", i);
                gets( st_Data[i].name);
                printf("\n\t--Which Menu You Want For Lunch?--\n\n");
                printf("\tITEM CODE 1. Khichuri with Meat (Price - 60 Taka).\n");
                printf("\tITEM CODE 2. Rice with Meat (Price - 60 Taka).\n");
                printf("\tITEM CODE 3. Rice with Curry (Price - 50 Taka).\n");
                printf("\n\tSelect an Item: ");
                scanf("%d", &item_code);
                if (item_code == 1)
                {
                    st_Data[i].expense = 60;
                    st_Data[i].menu = 1;

                }
                else if (item_code == 2)
                {
                    st_Data[i].expense = 60;
                    st_Data[i].menu = 2;
                }
                else if (item_code == 3)
                {
                    st_Data[i].expense = 50;
                    st_Data[i].menu = 3;
                }

            }
            n = n + nt;
            printf("\n\n\t\t\t\t===== Thank You =====\n");
            printf("\t\t\t=== Your order has been confirmed ===\n");

            fpt = fopen("Bill.txt", "w+");
            fprintf(fpt, "%d\n", n);
            for(i=1; i<=n; i++)
            {
                fprintf(fpt, "%s\n", st_Data[i].id);
                fprintf(fpt, "%s\n", st_Data[i].name);
                fprintf(fpt, "%d\n", st_Data[i].menu);
                fprintf(fpt, "%d\n", st_Data[i].expense);
            }
            fclose(fpt);

            break;

        case 2:
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t===== Search A Students Invoice: =====\n\n");
            printf("\tYour ID: ");
            gets(ID);
            getData();
            for(i=1; i<=n; i++)
            {
                if(strcmp(st_Data[i].id,ID)==0)
                {
                    printf("\n\n\tYour student ID: %s\n", st_Data[i].id);
                    printf("\tYour name: %s\n", st_Data[i].name);
                    menu_check();
                    printf("\tYour Bill: %d Taka\n\n", st_Data[i].expense);
                }
            }

            break;

        case 3:
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t\t===== Show All Invoices: =====\n\n");
            getData();
            allData();
            break;

        case 4:
            system("cls");
            printf("\n\n");
            printf("\t\t\t===== 4. Sort Students Data According To Their ID: =====");
            getData();
            for(i=1; i<=n-1; i++)
            {
                for(j=i+1; j<=n; j++)
                {
                    if(strcmp(st_Data[j].id,st_Data[i].id)<0)
                    {
                        swap1(st_Data[j].id,st_Data[i].id);
                        swap2(st_Data[j].name,st_Data[i].name);
                        swap3(st_Data[j].menu,st_Data[i].menu);
                        swap4(st_Data[j].expense,st_Data[i].expense);
                    }
                }
            }
            allData();


            break;

        case 5:
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t===== Change Order: =====\n\n");
            char tid[10];
            int item_code;
            getData();
            printf("\n\n\tYour ID: ");
            gets(tid);
            for(i=1; i<=n; i++)
            {
                if(strcmp(st_Data[i].id,tid)==0)
                {
                    printf("\n\n\t--Which Menu You Want For Lunch?--\n\n");
                    printf("\tITEM CODE 1. Khichuri with Meat (Price - 60 Taka).\n");
                    printf("\tITEM CODE 2. Rice with Meat (Price - 60 Taka).\n");
                    printf("\tITEM CODE 3. Rice with Curry (Price - 50 Taka).\n");
                    printf("\n\tSelect an Item: ");
                    scanf("%d", &item_code);
                    if (item_code == 1)
                    {
                        st_Data[i].expense = 60;
                        st_Data[i].menu = 1;

                    }
                    else if (item_code == 2)
                    {
                        st_Data[i].expense = 60;
                        st_Data[i].menu = 2;
                    }
                    else if (item_code == 3)
                    {
                        st_Data[i].expense = 50;
                        st_Data[i].menu = 3;
                    }

                }
            }
            printf("\n\n\t\t\t\t===== Thank You =====\n");
            printf("\t\t\t=== Your order has been changed ===\n");

            fpt = fopen("Bill.txt", "w+");
            fprintf(fpt, "%d\n", n);
            for(i=1; i<=n; i++)
            {
                fprintf(fpt, "%s\n", st_Data[i].id);
                fprintf(fpt, "%s\n", st_Data[i].name);
                fprintf(fpt, "%d\n", st_Data[i].menu);
                fprintf(fpt, "%d\n", st_Data[i].expense);
            }
            fclose(fpt);


            break;

        case 6:
            system("cls");
            printf("\n\n");
            torder();
            break;

        case 7:
            system("cls");
            printf("\n\n");
            printf("\t\t\t\t======= Thank You For Coming :) =======\n");
            printf("\t\t\t\t\t======= Good Bye =======\n\n");
            exit(0);
            break;
        default:
            printf("\nERROR\n");
            break;
        }

        printf("\n\tGo to Menu: 1(One)\n");
        printf("\tClose: o(Zero)\n");
        printf("\tWhat Do You Want To Do? : ");
        scanf("%d", &t);
    }

    return 0;
}



