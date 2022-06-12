/* 
Address book 
Created by Alan Joji, Aniket Choudhary, Akshat Gouniyal
Date : 07/06/2022
*/

// Header files
#include <stdio.h>
#include <stdlib.h>

#define NAME_LIMIT 20
#define LOC_LIMIT 50

// Structure needs to be implemented
struct address
{
    long int phone;
    char name[NAME_LIMIT];
    char location[LOC_LIMIT];
};

int num;//Number of contacts
struct address ad[100];  

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
    printf("Edit a contact");    

    
    return 0;
}

int delete_select ()
{
    printf("Delete a contact");    

    
    return 0;
}

int export_select ()
{
    printf("Export contacts to a file");    
  
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
    printf("\n5. Export saved contacts"); // Functionality will be implemented later

    printf("\n6. Exit");

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
        exit_select();
        break;

    default:
        printf("Invalid Option");
        break;
    }
    main();

    return 0;
}