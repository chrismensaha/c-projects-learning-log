#include <stdio.h>
#include <stdlib.h>
#include "contact-book.c"


/*
Build a command-line contact book where users can:
Add contacts (name, phone number)
List all contacts
Search for a contact by name
Delete a contact
Free all memory before exiting */

int main(){
    int mode=0, add=0, size=100, c;
    Contact *contact;
    
    contact=calloc(1,sizeof(Contact));
    printf("Press [1] to add");
    scanf("%d",&mode);
    switch (mode)
    {
    case 1:
        printf("How much do you want to add?");
        scanf("%d",&add);
        Contact *temp=realloc(contact,(add+1)*sizeof(Contact));
        contact=temp;
        
        while ((c = getchar()) != '\n' && c != EOF);  
        contact[0].name=malloc(size*sizeof(char));
        printf("Enter name:");        
        fgets(contact[0].name,size,stdin);
        printf("%s",contact[0].name);
        break;
    
    default:
        break;
    }

    free(contact);
    return 0;
}