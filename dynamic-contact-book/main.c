#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact-book.c"


/*
Build a command-line contact book where users can:
Add contacts (name, phone number)
List all contacts
Search for a contact by name
Delete a contact
Free all memory before exiting */

int main(){
    int mode=0, input_number=0, size=100, contactsize=0, start_index=0, delete_num=0;
    int c;
    Contact *contact;
    
    contact=calloc(1,sizeof(Contact));

    while (1){
    printf("Press [1] to Add\n[2] to List all contacts\n[3] to Delete a contact : ");
    scanf("%d",&mode);
    switch (mode)
    {
    case 1:
        printf("How much do you want to add?");        
        scanf("%d",&input_number);
        contactsize+=input_number;
        Contact *temp=realloc(contact,(input_number+1)*sizeof(Contact));
        contact=temp;
        
        while ((c = getchar()) != '\n' && c != EOF);  
        for(int i=start_index; i<input_number;i++){
            contact[i].name=malloc(size*sizeof(char));
            contact[i].number=malloc(size*sizeof(char));
            printf("Enter name: ");
                  
            fgets(contact[i].name,size,stdin);  
            contact[i].name[strcspn(contact[i].name, "\n")] = '\0';        
            printf("Enter number: ");        
            fgets(contact[i].number,size,stdin);            
            contact[i].number[strcspn(contact[i].number, "\n")] = '\0';

            printf("Name: %s  |  Number: %s\n", contact[i].name, contact[i].number);
            
    }        break;        
    case 2:
            if (contactsize!=0){ 
                for(int i=0;i<contactsize;i++){ 
                    printf("Name [%d]: %s  |  Number: %s\n",i, contact[i].name, contact[i].number);  }
                }
            else{ 
                    printf("Error! Add a contact first\n");                                     
            } break;
    case 3:
            printf("How many contacts do you want to delete? ");
            scanf("%d",&delete_num);
            if (contactsize!=0){ 
                for (int i=0; i<delete_num;i++){
                    free(contact[i].name);
                    free(contact[i].number);
                }
            }
            else{ 
                printf("Error! Add a contact first\n");                                     
            } 
                contactsize -=delete_num;
                temp=realloc(contact, (delete_num)*sizeof(Contact));
                contact = temp;


            break;
    default:
        break;
    }
    }
    free(contact);
    return 0;
}