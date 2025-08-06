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
    int mode=0, input_number=0, size=100, contactsize=0, delete_num=0, starting_num=10;
    int c, user_exit;
    Contact *contact;
    
    contact=calloc(starting_num,sizeof(Contact));

    while (1){
        printf("Press [1] to Add a contact, [2] to List all contacts, or [3] to Delete a contact: ");
        scanf("%d",&mode);
        switch (mode)
        {
        case 1:
            printf("# of contacts to add: ");        
            scanf("%d",&input_number);
            if (input_number<=0){
                printf("INVALID INPUT! Try Again\n"); break;}
            else {                
                Contact *temp=realloc(contact,(contactsize+input_number)*sizeof(Contact));
                if (!temp) {
                    printf("Error! Memory allocation failed\n");
                    break;
                    }
                contact=temp;

                int start_index = contactsize;
                contactsize+=input_number;

                while ((c = getchar()) != '\n' && c != EOF);  
                for(int i=start_index; i<start_index+input_number;i++){
                    contact[i].name=malloc(size*sizeof(char));
                    contact[i].number=malloc(size*sizeof(char));
                    printf("Enter name: ");             
                    fgets(contact[i].name,size,stdin);  
                    contact[i].name[strcspn(contact[i].name, "\n")] = '\0';  

                    printf("Enter number: ");        
                    fgets(contact[i].number,size,stdin);            
                    contact[i].number[strcspn(contact[i].number, "\n")] = '\0';

                    printf("You have entered: {%s, %s}\n", contact[i].name, contact[i].number);              
                    printf("Press [1] to continue | Press [0] to exit: ");
                    scanf("%d",&user_exit);

                    if (user_exit==0){ 
                        for(int i=0;i<contactsize;i++){
                            free(contact[i].name);
                            free(contact[i].number);
                        }
                        return 0;}
                    else continue;
                    }
                }        
        
        break;        
        case 2:
                if (contactsize==0){ printf("Empty contactbook! Please add a contact first\n"); break;}
                else{ 
                    for(int i=0;i<contactsize;i++){ 
                        printf("Name: %s  |  Number: %s\n", contact[i].name, contact[i].number);}                                                                            
                    } break;
        case 3:
                if (contactsize!=0){
                    printf("How many contacts do you want to delete? ");
                    scanf("%d",&delete_num); 
                    if (delete_num > contactsize) {
                        printf("Deletion request too large!\n");
                        break;
                            }
                    else{
                        for (int i=0; i<delete_num;i++){
                            free(contact[i].name);
                            free(contact[i].number);
                            realloc(contact, contactsize * sizeof(Contact));
                    }
                }
            }
                else{ 
                    printf("Error! Add a contact first\n");                                     
                } 
                break;
        default:
            break;
        }
        }
    free(contact);
    return 0;
}