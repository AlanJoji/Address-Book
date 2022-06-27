/* 
Address book 
Created by Alan Joji, Aniket Choudhary, Akshat Gouniyal
Date : 07/06/2022
*/

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LIMIT 20
#define LOC_LIMIT 50

// Structure needs to be implemented.
struct address
{
    long int phone;
    char name[NAME_LIMIT];
    char location[LOC_LIMIT];
};

int num;//Number of contacts
struct address ad[100];  
//struct address *pad = ad;
// Function definitions
int add_select ()
{
    printf("\nAdding a contact");

    printf("\nEnter a name : ");
    fflush(stdin);
    scanf("%[^\n]s", ad[num].name);

    printf("\nEnter a phone number : ");
    scanf("%ld", &ad[num].phone);

    printf("\nEnter an address : ");
    fflush(stdin);
    scanf("%[^\n]s", ad[num].location);

    printf("Address has been saved");
    
    num++;

    return 0;
}

int view_select ()
{
    printf("\nView saved contacts"); 

    if (num != 0)
    {
        int i;

        for (i = 0; i < num; i++)
        {
            printf("\nName : %s", ad[i].name);
            printf("\nPhone : %ld", ad[i].phone);
            printf("\nLocation : %s", ad[i].location);
            printf("\n==========================");
        }
    }

    else
        return 1;

    return 0;
}

int edit_select ()

{
    printf("Edit a contact\n\n");    
    
    if (num!=0)
    { 
        int i;
        for(i=0;i<num;i++)
            {
                printf("%d : ",i+1);
                printf("\nName : %s", ad[i].name);
                printf("\nPhone : %ld", ad[i].phone);
                printf("\nLocation : %s", ad[i].location);
                printf("\n==========================\n");
            }
    }
    printf("Select contact to edit: ");
    int choice;
    scanf("%d",&choice);
    choice=choice-1;   

    printf("\nEnter new name : ");
    fflush(stdin);
    scanf("%[^\n]s", ad[choice].name);

    printf("\nEnter new phone number : ");
    scanf("%ld", &ad[choice].phone);

    printf("\nEnter new address : ");
    fflush(stdin);
    scanf("%[^\n]s", ad[choice].location);

    printf("Address has been changed");

    
    return 0;
}

int delete_select ()
{
    printf("Delete a contact");    
    
    if (num!=0)
    { 
        int i;
        for(i=0;i<num;i++)
            {
                printf("\nContact %d : ",i+1);
                printf("\nName : %s", ad[i].name);
                printf("\nPhone : %ld", ad[i].phone);
                printf("\nLocation : %s", ad[i].location);
                printf("\n==========================\n");
            }
    }

    int choice = 0;

    printf("Enter a choice : ");
    scanf("%d", &choice);

    for (int i = choice; i <= num; i++)
    {
        ad[i] = ad[i + 1];
    }
    
    num--;
    
    return 0;
}

int export_select ()
{
    printf("Export contacts to a file");

    FILE *file1;
    file1=fopen("phonebook.txt","w");

    if(file1==NULL)
    {
        printf("Contacts were not exported");
    }

    else
    {
        if (num != 0)
        {
            int i;

            for (i = 0; i < num; i++)
            {
                printf("\nName : %s", ad[i].name);
                printf("\nPhone : %ld", ad[i].phone);
                printf("\nLocation : %s", ad[i].location);
                fprintf(file1,"%s\t%ld\t%s\n",ad[i].name,ad[i].phone,ad[i].location);
                printf("\n==========================");
            }
        }

        else
        {
            return 1;
        }
    }

    fclose(file1);
    return 0; 
}

int search_select ()
{
    printf("Search for a saved contact");
    printf("\nEnter the contact name :");

    fflush(stdin);

    char search_name[NAME_LIMIT];

    scanf("%[^\n]s", search_name);

    if (num != 0)
    {
        int i;

        for (i = 0; i < num; i++)
        {
            if (strcmp(search_name, ad[i].name) == 0)
            {
                printf("%s was found\n\nContact details : ", search_name);
                printf("\nName : %s", ad[i].name);
                printf("\nPhone : %ld", ad[i].phone);
                printf("\nLocation : %s", ad[i].location);
                printf("\n==========================");

                return 0;
            }
            
            else
                continue;
        }
    }
    
    else
        return 1;
    
    printf("\n%s was not found", search_name);

    return 0;
}

int exit_select ()
{
    printf("Thank you!");
    exit(0);

    return 0;
}

// Main Function
int main ()
{
    printf("\n\nWelcome to the Address Book");

    printf("\n\n+============+============+");

    printf("\n\n1. Add a contact");
    printf("\n2. View saved contacts");
    printf("\n3. Edit saved contacts");
    printf("\n4. Delete a saved contact");
    printf("\n5. Export saved contacts");
    printf("\n6. Search saved contacts");


    printf("\n7. Exit");

    printf("\n\n+============+============+");

    printf("\n\nEnter a choice : ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1 :
        add_select();
        break;
    
    case 2 :
        view_select();
        break;
    
    case 3 :
        edit_select();
        break;
    
    case 4 :
        delete_select();
        break;

    case 5 : 
        export_select();
        break;

    case 6 :
        search_select();
        break;

    case 7 : 
        exit_select();
        break;

    default:
        printf("Invalid Option");
        break;
    }
    main();

    return 0;
}
