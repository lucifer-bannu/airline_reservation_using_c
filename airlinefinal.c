#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void loadData();
void writeData();
void display();
void reserve();
void cancel();
void search();

int main(void);

struct passengers
{
    char passport[10];
    char name[50];
    char origin[50];
    char destination[50];
    char seatNum[5];
} x[100];

int n, i, j, g, num = 0, sum = 0, a = 0;

int main()
{
    int choice;
    loadData();
    printf("*************************************");
    printf(" Welcome To airline reservation ");
    printf("*************************************");
    while (choice != 4)
    {
        printf("\n**Enter your choice**\n");
        printf("\n  1. RESERVE SEAT");
        printf("\n  2. CANCEL TICKET");
        printf("\n  3. DISPLAY PASSENGER DATA");
        printf("\n  4. SEARCH PASSENGER DATA");
        printf("\n  5. EXIT SYSTEM");
        printf("\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            reserve();
            break;
        case 2:
            cancel();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
        {
            writeData();
            exit(0);
            break;
        }
        default:
            printf("\nInvalid Choice");
        }
    }
}

void loadData()
{
    FILE *fp = fopen("passengerDetails.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("passengerDetails.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n");
        return;
    }
    num = fread(x, sizeof(struct passengers), 100, fp);
    fclose(fp);
};

void writeData()
{
    FILE *fp = fopen("passengerDetails.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct passengers), num, fp);

    fclose(fp);
}

void display()
{
    if(num == 0)
    {
        printf("No records found");
    }
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("passport number : ");
        puts(x[i].passport);
        printf("Passenger Name : ");
        puts(x[i].name);
        printf("Destination(to) : ");
        puts(x[i].destination);
        printf("Origin(from) : ");
        puts(x[i].origin);
        printf("Enter seat number : ");
        puts(x[i].seatNum);
        printf("\n");
    }
}
void reserve()
{

    // printf("\n");
    printf("How many tickets do you want to book : ");
    scanf("%d", &n);
    fflush(stdin);
    sum = n + num;
    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        fflush(stdin);
        fflush(stdin);
        getchar();
        printf("Enter passenger Name : ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter the passport number : ");
        gets(x[i].passport);
        fflush(stdin);
        printf("Enter destination(to) : ");
        gets(x[i].destination);
        fflush(stdin);
        printf("Enter the origin(from) : ");
        gets(x[i].origin);
        fflush(stdin);
        printf("Enter seat number : ");
        gets(x[i].seatNum);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
    printf("Ticket booking is successful");
    return;
};

void cancel()
{
    int f = 0;
    char s[50];
    printf("Enter the your passport number : ");
    getchar();
    gets(s);
    fflush(stdin);
    while(s==x[f].passport)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].destination,x[f+1].destination);
                strcpy(x[f].origin,x[f+1].origin);
                strcpy(x[f].passport,x[f+1].passport);
                strcpy(x[f].seatNum,x[f+1].seatNum);
                f++;
                printf("Ticket has been cancelled\n");
            }
            num--;
            writeData();
            return;
};

void search()
{
    int h, f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Passport number.\n2.Name\n3.Destination\n4.Origin.\n5.Seat number.\n");
    printf("Enter the option : ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Passport number of the passenger : ");
        getchar();
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].passport)==0)
            {
                printf("\n");
                printf("Passport Number : ");
                puts(x[g].passport);
                printf("Name : ");
                puts(x[g].name);
                printf("Destination(to) : ");
                puts(x[g].destination);
                printf("Origin : ");
                puts(x[g].origin);
                printf("Seat No : ");
                puts(x[g].seatNum);
                printf("\n");
                return;
            }
            else 
                printf("Not Found\n");
        }
    }
    else if (h == 2)
    {
        fflush(stdin);
        printf("Enter passenger name : ");
        getchar();
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (!strcmp(u,x[g].name))
            {
                printf("\n");
                printf("Passport Number : ");
                puts(x[g].passport);
                printf("Passenger Name : ");
                puts(x[g].name);
                printf("Destination(to) : ");
                puts(x[g].destination);
                printf("Origin(from) : ");
                puts(x[g].origin);
                printf("Seat Num:");
                puts(x[g].seatNum);
                printf("\n");
                return;
            }
            else
            {
                printf("\nNot Found...\n");
            }
            
        }
                // printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        printf("Enter destination(to) : ");
        getchar();
        gets(u);
        for (g = 0; g < num; g++)
        {
            if (!strcmp(u, x[g].destination))
            {
                printf("\n");
                printf("Passport Number : ");
                puts(x[g].passport);
                printf("Passenger Name : ");
                puts(x[g].name);
                printf("Destination(to) : ");
                puts(x[g].destination);
                printf("Origin(from) : ");
                puts(x[g].origin);
                printf("Seat Num:");
                puts(x[g].seatNum);
                printf("\n");
                return;
            } 
        }
        printf("Not Found\n");
    }
    else if (h == 4)
    {
        printf("Enter Origin(from) : ");
        getchar();
        gets(u);
        for (g = 0; g < num; g++)
        {
            if (!strcmp(u, x[g].origin))
            {
                printf("\n");
                printf("Passport Number : ");
                puts(x[g].passport);
                printf("Passenger Name : ");
                puts(x[g].name);
                printf("Destination(to) : ");
                puts(x[g].destination);
                printf("Origin(from) : ");
                puts(x[g].origin);
                printf("Seat Num:");
                puts(x[g].seatNum);
                printf("\n");
                return;
            }
        }
        printf("Not Found\n");
    }
    else if (h == 5)
    {
        printf("Enter Seat number : ");
        getchar();
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (!strcmp(u, x[g].seatNum))
            {
                printf("\n");
                printf("Passport Number : ");
                puts(x[g].passport);
                printf("Passenger Name : ");
                puts(x[g].name);
                printf("Destination(to) : ");
                puts(x[g].destination);
                printf("Origin(from) : ");
                puts(x[g].origin);
                printf("Seat Num:");
                puts(x[g].seatNum);
                printf("\n");
                return;
            }
        }
        printf("Not Found\n");
    }
    else
        printf("\n\nInvalid input\n\n");
};
