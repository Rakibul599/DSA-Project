#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char place[100];
    char place1[100];
    char bus[100];
    int km;
    int rent;
    struct Node *next;
};

typedef struct Node node1;
node1 *head=NULL, *last=NULL;

void adddeatails(char s1[100], char s2[100], char s3[100], int distance,int rent)
{
    node1 *temp_node;
    temp_node = (node1 *) malloc(sizeof(node1));
    strcpy((temp_node->place),s1);
    strcpy((temp_node->place1),s2);
    strcpy((temp_node->bus),s3);
    temp_node->km=distance;
    temp_node->rent=rent;
    temp_node->next=NULL;

    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }
}
void SearchDistance(char s[100],char s1[100])
{
    int c=0;
    char data[100];
    char data1[100];
    strcpy(data,s);
    strcpy(data1,s1);
    node1 *temp;
    temp=head;
    printf("\n\t\t---------------------------------------\n");
    printf("\t\t------Your Searching Information------\n\n");
    while(temp!=NULL)
    {
        if(strcmp(temp->place,data)==0 && strcmp(temp->place1,data1)==0)
        {
            c++;
            printf("\t\t\tYour Location\n\t\t\t->->%s\n\n\t\t\tYour Destination\n\t\t\t->->%s\n\n\t\t\tBus Name\n\t\t\t->%s\n\n\t\t\tTotal Kilomiter\n\t\t\t->->%d km\n\n\t\t\tTotal Rent\n\t\t\t->->%d Taka\n\n",temp->place,temp->place1,temp->bus,temp->km,temp->rent);
        }

        temp=temp->next;
    }
    if(c==0)
    {
        printf("\t\t\tOps! Not found\n");
    }
    printf("\n\t\t---------------------------------------\n");
}
void deletedata(char s1[100], char s2[100])
{
    node1 *myNde = head, *previous=NULL;
    int flag = 0;
    char sr[100],sr1[100];
    strcpy(sr,s1);
    strcpy(sr1,s2);
    while(myNde!=NULL)
    {
        if(strcmp(myNde->place,sr)==0 && strcmp(myNde->place1,sr1)==0)
        {
            if(previous==NULL)
                head = myNde->next;
            else
                previous->next = myNde->next;

            printf("Wow! Successfully Deleted");

            flag = 1;
            free(myNde);
            break;
        }

        previous = myNde;
        myNde = myNde->next;
    }

    if(flag==0)
        printf("Data not found!\n");
}
void Display()
{
    node1 *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("---------------------------------\n");
        printf("%s to ", myList->place);
        printf("%s\n", myList->place1);
        printf("Bus Name= %s\n",myList->bus);
        printf("Total kilomiters= %d\n",myList->km);
        printf("Total Rent= %d\n",myList->rent);
        printf("---------------------------------\n");

        myList = myList->next;
    }
}
void admin()
{
    AdminMessage();
    int ch,k,r;
    char str1[100],str2[100],str3[100];
    while(1)
    {
        printf("\n\t\t\t1.Add Place\n\t\t\t2.Display All Place\n\t\t\t3.Delete Data\n\t\t\t0.Main Menu\n");
        printf("\t\t\tChoice Option: ");
        scanf("%d",&ch);
        if(ch==0)
        {
            system("cls");
            break;
        }
        else
        {
        switch(ch)
        {
        case 1:
            system("cls");
            printf("\t\t\tEnter From:");
            scanf("%s",str1);
            printf("\t\t\tEnter To:");
            scanf("%s",str2);
            printf("\t\t\tEnter Bus Name:");
            scanf("%s",str3);
            printf("\t\t\tEnter Kilometer:");
            scanf("%d",&k);
            printf("\t\t\tEnter rent:");
            scanf("%d",&r);
            adddeatails(str1,str2,str3,k,r);
            break;
        case 2:
            system("cls");
            Display();
            break;
        case 3:
            system("cls");
            printf("\t\t\tEnter From: ");
            scanf("%s",str1);
            printf("\t\t\tEnter To: ");
            scanf("%s",str2);
            deletedata(str1,str2);
            break;
        default:
            printf("\t\t\tError please Try Again");
        }
        }
    }
}
void General()
{
    int cha;
    char sr[100],sr1[100];
    while(1)
    {
        GeneralMessage();
        printf("\t\t\t1.Search Bus Route\n\t\t\t0.Main Menu\n");
        printf("\t\t\tChoice Option: ");
        scanf("%d",&cha);
        if(cha==0)
        {
            system("cls");
            break;
        }
        else
        {

        switch(cha)
        {
        case 1:
        system("cls");
        printf("\t\t\tYour current location: ");
        scanf("%s",sr);
        printf("\t\t\tYour current destination: ");
        scanf("%s",sr1);
        SearchDistance(sr,sr1);
        break;
        default:
        system("cls");
        printf("OPS! Try Agan");
        }
        }
    }
}
void pass()
{
    char s[]="rakib0099";
    char s3[]="Rakibul";
    char s1[100],s2[100];
    printf("\t\t\tEnter User Name: ");
    scanf("%s",s2);
    printf("\t\t\tEnter Admin Password:");
    scanf("%s",s1);
    if(strcmp(s,s1)==0 && strcmp(s3,s2)==0)
    {
       system("cls");
       admin();
    }
    else
    {
        system("cls");
        printf("OPS! Your Password is incorrect Try Again\n");
    }

}
void welcomeMessage(){
    printf("\n\n\n");
    printf("\n\t\t\t  ********************************************************\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =                DHAKA CITY                 =");
    printf("\n\t\t\t        =                 BUS ROUTE                 =");
    printf("\n\t\t\t        =                  FINDER                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  ********************************************************\n");
}
void AdminMessage(){
    printf("\n\n\n");
    printf("\n\t\t\t  ********************************************************\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =                ADMIN PANNEL               =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  ********************************************************\n");
}
void GeneralMessage(){
    printf("\n\n\n");
    printf("\n\t\t\t  ********************************************************\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               General public              =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  ********************************************************\n");
}
int main()
{
    system("color A");
    FILE *fptr = fopen("DataBase.txt","r");
    if(fptr == NULL){
		printf("Error!, The file is not found\n");
		exit(1);
	}
	char str1[100],str2[100],str3[100];
	int SZ,k,r;
	fscanf(fptr,"%d",&SZ);
    for(int i=0; i<SZ; i++){
        fscanf(fptr,"%s%s%s%d%d",str1,str2,str3,&k,&r);
        adddeatails(str1,str2,str3,k,r);
        }
    fclose(fptr);
     int ch;
    while(1)
    {
         welcomeMessage();
        printf("\n\t\t\t1.Admin Pannel\n\t\t\t2.General public\n\t\t\t0.Exit\n");
        printf("\t\t\tChose Option:");
        scanf("%d",&ch);
        if(ch==0)
        {
            break;
        }
        switch(ch)
        {
        case 1:
            system("cls");
            pass();
            break;
        case 2:
            system("cls");
            General();
            break;
        default:
            system("cls");
            printf("OPs! Error Try Again");

        }
    }
}
