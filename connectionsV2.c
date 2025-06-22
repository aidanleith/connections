//Connections Game
//December 16, 2023

//To do List:
    //add theme names when guessed correctly
    //potentially add telling someone how many they got right (ex: 1 away...)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 30
#define TOTALSTRINGS 16

//global variables for lives and num correct
int LIVES = 4;
int CORRECT = 0;

//node struct
typedef struct node{
    char word[MAXLEN];
    int group;
    struct node* next;
} node;

//functions
node* fillLL(node* head, char myWord[MAXLEN], int set);
void printWords(node* head);
int checkWords(node* head, char** myGuesses);
node* removeNodes(node* head, int i);
int getIndex(node* head, char** myGuesses);

//main function
int main(){

    node* start = NULL;

    start = fillLL(start, "bank", 1);
    start = fillLL(start, "pages", 3);
    start = fillLL(start, "carrot", 4);
    start = fillLL(start, "save", 1);
    start = fillLL(start, "gall", 2);
    start = fillLL(start, "stash", 1);
    start = fillLL(start, "girl", 3);
    start = fillLL(start, "coal", 4);
    start = fillLL(start, "guts", 2);
    start = fillLL(start, "business", 3);
    start = fillLL(start, "bone", 3);
    start = fillLL(start, "snow", 4);
    start = fillLL(start, "sticks", 4);
    start = fillLL(start, "nerve", 2);
    start = fillLL(start, "store", 1);
    start = fillLL(start, "stones", 2);


    char** guesses = malloc(4 * sizeof(char*));
    for(int i=0;i<4;i++){
        guesses[i] = malloc(MAXLEN * sizeof(char));
    }

    while(LIVES != 0 && CORRECT !=4){

        printf("LIVES REMAINING: %d\n", LIVES);

        printWords(start);

        printf("\nEnter your guesses: ");

        for(int i=0;i<4;i++){
            scanf("%s", guesses[i]);
        }

        if(checkWords(start, guesses) == 1){
            printf("CONGRATS!\n");
            CORRECT++;
            int myIndex = getIndex(start, guesses);
            start = removeNodes(start, myIndex);
        }
        else{
            printf("WAH WAH wrong\n");
            LIVES--;
        }

    }

    if(LIVES==0){
        printf("you failed\n");
    }

    if(CORRECT==4){
        printf("you did it!!!");
    }


    return 0;
}

node* fillLL(node* head, char myWord[MAXLEN], int set){

    node* pNew = malloc(sizeof(node));
    strcpy(pNew->word, myWord);
    pNew->group = set;
    pNew->next = NULL;

    node* current = head;

    if(head==NULL){
        return pNew;
    }

    while(current->next != NULL){
        current = current->next;
    }

    current->next = pNew;

    return head;

}


//print out word bank
void printWords(node* head){

    int i=0;

    node* current = head;

    while(current != NULL){

        printf(" %s ", current->word);

        i++;

        if(current->next != NULL){
            current = current->next;
        }
        else{
            break;
        }

        if(i%4==0){
            printf("\n");
        }
    }

}

//checking if words entered match, return 1 if guess is correct
int checkWords(node* head, char** myGuesses){

    int complete = 0;
    int k = 0;
    int i=0;
    node* current = head;
    int* indexes = malloc(4 * sizeof(int));


        while(current != NULL){
            for(int k=0;k<4;k++){
                if(strcmp(current->word, myGuesses[k])==0){
                    indexes[i] = current->group;
                    i++;
                }
            }
            current = current->next;
        }


    //check if any numbers in indexes array do not match, return 0
    for(int i=0;i<3;i++){
        if(indexes[i] != indexes[i+1]){
           return 0;
        }
    }

    //else we can return 1
    return 1;

}

node* removeNodes(node* head, int i){

    node* current = head;
    node* prev =NULL;

    while(current != NULL){
        if(current->group == i){
            if(prev == NULL){
                node* temp = current;
                head = current->next;
                current = head;
                free(temp);
            }
            else{
                node* temp = current;
                prev->next = current->next;
                current = current->next;
                free(temp);
            }
        } else{
           prev = current;
           current = current->next;
        }
    }

    return head;

}

int getIndex(node* head, char** myGuesses){

    node* current = head;

    while(current!=NULL){
        if(strcmp(current->word, myGuesses[0])==0){
            return current->group;
        }else{
            current = current->next;
        }
    }

}



