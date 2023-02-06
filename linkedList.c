#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 99999

struct Node{
    int c;
    struct Node* next;
};

struct Node* reverseList(struct Node* originalList){
    time_t reverseOperationStarts;
	time(&reverseOperationStarts);

    struct Node* newList = (struct Node*) malloc(sizeof(struct Node));

    newList->next = NULL;
    newList->c = originalList->c;

    struct Node *current = originalList->next;

    while (1){
        if (current == NULL) break;
        struct Node *node = (struct Node*) malloc(sizeof(struct Node));
        node->c = current->c;
        node->next = newList;
        newList = node;
        current = current->next;
    }

    time_t reverseOperationEnds;
	time(&reverseOperationEnds);
    printf("Time to reverse List :%f \n",difftime(reverseOperationEnds,reverseOperationStarts));

    return newList;
}

void printList(struct Node* list){
    struct Node* current = list;
    
    while (1){
        if(current == NULL) break;
        printf("memory address :%p\tvalue :%d\n",current,current->c);
        current = current->next;
    }
    
}

int main(){
    time_t programStarts;
	time(&programStarts);

    int k;
    struct Node* list = (struct Node*) malloc(sizeof(struct Node));
    list->c = 13;
    
    struct Node *current = list;

    time_t listPopulationStarts;
	time(&listPopulationStarts);

    for(k=1; k<SIZE; k++){
        struct Node *node = (struct Node*) malloc(sizeof(struct Node));
        node->c = current->c + 1;
        current->next = node;
        current = current->next;
    }
    current->next = NULL;

    time_t listPopulationEnds;
	time(&listPopulationEnds);
    printf("Time to populate List :%f \n",difftime(listPopulationEnds,listPopulationStarts));

    // printList(list);

    struct Node* reversedList = reverseList(list);
    // printList(reversedList);

    printf("list :%p current :%p\n",list,current);
    printf("size of Node %ld\n",sizeof(struct Node));

    time_t programEnds;
	time(&programEnds);
    printf("Total time to run program :%f \n",difftime(programEnds,programStarts));
    return 0;
}