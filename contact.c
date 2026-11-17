#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"


void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    if(addressBook->contactCount==0)
    {
        printf("No contacts available\n");
        return;
    }
    int choice;
    printf("\nSort Contacts by\n");
    printf("1.Name\n");
    printf("2.phone\n");
    printf("3.email\n");
    scanf("%d",&choice);
    Contact temp;
    for(int i=0;i<addressBook->contactCount-1;i++)
    {
        for(int j=i+1;j<addressBook->contactCount;j++)
        {
            switch(choice)
            {
                case 1:
                if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0)
                {
                    temp=addressBook->contacts[i];
                    addressBook->contacts[i]=addressBook->contacts[j];
                    addressBook->contacts[j]=temp;
                }
                break;
                case 2:
                if(strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone)>0)
                {
                    temp=addressBook->contacts[i];
                    addressBook->contacts[i]=addressBook->contacts[j];
                    addressBook->contacts[j]=temp;
                }
                break;
                case 3:
                if(strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email)>0)
                {
                    temp=addressBook->contacts[i];
                    addressBook->contacts[i]=addressBook->contacts[j];
                    addressBook->contacts[j]=temp;
                }
                break;
                default:
                printf("Invalid choice\n");

            }
        }
    }

    printf("\n---Contact List---\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("\nContact %d\n",i+1);
        printf("Name :%s\n",addressBook->contacts[i].name);
        printf("phone :%s\n",addressBook->contacts[i].phone);
        printf("Email :%s\n",addressBook->contacts[i].email);
    }

    
}

void initialize(AddressBook *addressBook) 
{
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
     addressBook->contactCount = 0;
}

void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("contactCount = %d\n", addressBook->contactCount);
    printf("Inside createContact\n");
    int i;
    int index = addressBook->contactCount;

    char name[50];
    char phone[20];
    char email[50];

    printf("Enter Name : ");
    scanf(" %[^\n]", name);

  
    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(name, addressBook->contacts[i].name) == 0)
        {
            printf("Contact already exists\n");
            return;
        }
    }

    printf("Enter Phone Number : ");
    scanf("%s", phone);

  
    if(strlen(phone) != 10)
    {
        printf("Phone number must contain 10 digits\n");
        return;
    }

    for(i = 0; phone[i] != '\0'; i++)
    {
        if(phone[i] < '0' || phone[i] > '9')
        {
            printf("Invalid Phone Number\n");
            return;
        }
    }

  
    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            printf("Phone Number Already Exists\n");
            return;
        }
    }

    printf("Enter Email : ");
    scanf("%s", email);

    if(strchr(email, '@') == NULL)
    {
        printf("Invalid Email\n");
        return;
    }

  
    if(strstr(email, ".com") == NULL)
    {
        printf("Invalid Email\n");
        return;
    }

    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(email, addressBook->contacts[i].email) == 0)
        {
            printf("Email Already Exists\n");
            return;
        }
    }

    strcpy(addressBook->contacts[index].name, name);
    strcpy(addressBook->contacts[index].phone, phone);
    strcpy(addressBook->contacts[index].email, email);

    printf("Index = %d\n", index);

//printf("Before name copy\n");
strcpy(addressBook->contacts[index].name, name);
//printf("After name copy\n");

//printf("Before phone copy\n");
strcpy(addressBook->contacts[index].phone, phone);
//printf("After phone copy\n");

//printf("Before email copy\n");
strcpy(addressBook->contacts[index].email, email);
//printf("After email copy\n");

//printf("Before increment\n");
addressBook->contactCount++;
//printf("After increment\n");

printf("Contact Added Successfully\n");


    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
    char key[50];
    int found = 0;

    printf("\nSearch Contact By\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter Name: ");
            scanf(" %[^\n]", key);

            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if(strcmp(key, addressBook->contacts[i].name) == 0)
                {
                    printf("\nContact Found\n");
                    printf("Name  : %s\n", addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            break;

        case 2:
            printf("Enter Phone Number: ");
            scanf("%s", key);

            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if(strcmp(key, addressBook->contacts[i].phone) == 0)
                {
                    printf("\nContact Found\n");
                    printf("Name  : %s\n", addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            break;

        case 3:
            printf("Enter Email: ");
            scanf("%s", key);

            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if(strcmp(key, addressBook->contacts[i].email) == 0)
                {
                    printf("\nContact Found\n");
                    printf("Name  : %s\n", addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n", addressBook->contacts[i].email);
                    found = 1;
                    break;
                }
            }
            break;

        default:
            printf("Invalid Choice\n");
            return;
    }

    if(found == 0)
    {
        printf("Contact Not Found\n");
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice;
    char key[50];

    printf("Edit contact by:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf(" %[^\n]", key);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        int match = 0;

        switch(choice)
        {
            case 1:
                match = (strcmp(key, addressBook->contacts[i].name) == 0);
                break;

            case 2:
                match = (strcmp(key, addressBook->contacts[i].phone) == 0);
                break;

            case 3:
                match = (strcmp(key, addressBook->contacts[i].email) == 0);
                break;

            default:
                printf("Invalid choice\n");
                return;
        }

        if(match)
        {
            printf("Contact found\n");

            printf("Current Name: %s\n", addressBook->contacts[i].name);
            printf("Current Phone: %s\n", addressBook->contacts[i].phone);
            printf("Current Email: %s\n", addressBook->contacts[i].email);

            printf("\nEnter new details:\n");

            printf("New Name: ");
            scanf(" %[^\n]", addressBook->contacts[i].name);

            printf("New Phone: ");
            scanf(" %[^\n]", addressBook->contacts[i].phone);

            printf("New Email: ");
            scanf(" %[^\n]", addressBook->contacts[i].email);

            printf("Contact updated successfully\n");
            return;
        }
    }

    printf("Contact not found\n");

}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   int choice;
    char key[50];

    printf("Delete contact by:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf(" %[^\n]", key);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        int match = 0;

        switch(choice)
        {
            case 1:
                match = (strcmp(key, addressBook->contacts[i].name) == 0);
                break;

            case 2:
                match = (strcmp(key, addressBook->contacts[i].phone) == 0);
                break;

            case 3:
                match = (strcmp(key, addressBook->contacts[i].email) == 0);
                break;

            default:
                printf("Invalid choice\n");
                return;
        }

        if(match)
        {
            printf("Contact found\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);

            char choiceDel;
            printf("Do you want to delete this contact? (y/n): ");
            scanf(" %c", &choiceDel);

            if(choiceDel == 'n' || choiceDel == 'N')
            {
                printf("Deletion cancelled\n");
                return;
            }

            if(choiceDel != 'y' && choiceDel != 'Y')
            {
                printf("Invalid choice\n");
                return;
            }

            for(int j = i; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            printf("Contact deleted successfully\n");
            return;
        }
    }

    printf("Contact not found\n");
}
