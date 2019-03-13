/*
Jacky Li

*/
//Header Files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Create a node structure of link list
struct node {
   char* data;
   int key;
   struct node *next;
};
struct node *head = NULL;
//Insert function
void ins(char* str) {

   struct node *ptr = head;
   struct node *temp = head;

   struct node *current = head;
   struct node *prev = head;
   
   // Create a link list node with given data
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = 1;
   link->data = malloc(12 * sizeof(char));
   strcpy(link->data,str);
   link->next = NULL;


   if(head == NULL){
        // If head doesn't exist then make this node as head
        head = link;
   }
   else{

        // Traverse the link list
        while(ptr!= NULL) {

            // If given string is found in link list
            if(strcmp(ptr->data, str)==0){
                ptr->key += 1;

                // If count of head is increased, it will be greatest, no need to sort again
                // sort the link list if the node is not head
                if(ptr!=head){

                    // Traverse the link list to check where to fit modified node
                    while(current!=NULL && current->key > ptr->key) {
                      prev = current;
                      current = current->next;
                    }
                    
                    // If it's the same node then no need to reset the connections, If not then reset the links
                    if(current != ptr) {
                      temp->next = ptr->next;
                      ptr->next = current;

                      // If this node becomes the node with largest key, then head should be reset
                      if(current == head) {
                        head = ptr;
                      } else {
                        prev->next = ptr;
                      }
                    }

                }
                return;
            }

            temp = ptr;
            ptr = ptr->next;

        }

      // If string doesn't already exist in link list
      temp->next = link;

   }
}
//del function
void del(char* data){

    struct node *ptr = head;
    struct node *temp = head;

   struct node *current = head;
   struct node *prev = head;

    if(ptr==NULL){
        printf("The list is empty. \n");fflush(stdout);
        return;
    }

    // Traverse the link list
    while(ptr!= NULL){

         // If given string is found in link list
        if(strcmp(ptr->data,data)==0){

            // Node with key value as 1, should be removed from link list (else condition)
            if(ptr->key != 1) {

                // For node with key value greater than 1 : links should be reset to maintain sorted link list
                // Traverse the link list to find where to fit modified node
                while(current!=NULL && current->key > ptr->key-1) {
                    prev = current;
                    current = current->next;
                }

                // If it's the same node then no need to reset the connections, If not then reset the links 
                if(prev != ptr) {
                    if(ptr == head) head = ptr->next; // Reset the head, if it's ptr is head node
                    temp->next = ptr->next;
                    ptr->next = current;
                    prev->next = ptr;
                }
            } else {
                // Node with key value as 1, should be removed from link list
                if(ptr==head){
                    head = ptr->next;
                } else{
                    temp->next = ptr->next;
                    ptr->next = NULL;
                }
            }
            // Decrement the key value of node
            ptr->key -= 1;
            return;
        }
        temp = ptr;
        ptr = ptr->next;
    }
}
//forcedelete function
void fde(int val){
    struct node *ptr = head;
    struct node *temp = head;

    if(ptr == NULL){
        printf("The list is empty. \n");fflush(stdout);
        return;
    }

	//start from the beginning
    while(ptr != NULL){
        if(ptr->key <= val){
            if(ptr==head){
              head = NULL;
            } else {
              temp->next = NULL;
            }
        }
        temp = ptr;
        ptr = ptr->next;
    }
}
//printstatistics function
void pst() {

   struct node *ptr = head;

    if(ptr==NULL){
        printf("The list is empty. \n");fflush(stdout);
        return;
    }
    int c=0, max = 0, min = ptr->key;
    float sum = 0;

   //start from the beginning
   while(ptr != NULL) {
        sum += ptr->key;
        if(ptr->key > max){
            max = ptr->key;
        }
        if(ptr->key < min){
            min = ptr->key;
        }
        c++;
        ptr = ptr->next;
   }
   sum = sum/c;
   printf("The number of nodes in the list: %d\nThe maximum count in the list: %d\nThe minimum count in the list: %d\nThe average count in the list :%f\n",c,max,min,sum);fflush(stdout);
}
//printlist function
void prl() {

   struct node *ptr = head;

   if(ptr==NULL){
    printf("The list is empty. \n");fflush(stdout);
    return;
   }

   //start from the beginning
   while(ptr != NULL) {
      printf("%s :  %d\n",ptr->data,ptr->key);fflush(stdout);
      ptr = ptr->next;
   }
}
//print using count range function
void pcr(int v1, int v2) {

   struct node *ptr = head;

   if(ptr==NULL){
    printf("The list is empty. \n");fflush(stdout);
    return;
   }

   //start from the beginning
   while(ptr != NULL) {
        if(ptr->key >=v1 && ptr->key<=v2)
            printf("%s :  %d\n",ptr->data,ptr->key);fflush(stdout);
        ptr = ptr->next;
   }
}
//print prefix function
void ppr(char* s) {

   struct node *ptr = head;

   if(ptr==NULL){
      printf("The list is empty. \n");fflush(stdout);
      return;
   }

   int len1 = strlen(s), len2;

   //start from the beginning
   while(ptr != NULL) {
	   
        len2 = strlen(ptr->data);

        if( len2 >= len1 && strncmp(s,ptr->data,len1)==0){
            printf("%s :  %d\n",ptr->data,ptr->key);fflush(stdout);
        }

      ptr = ptr->next;
   }
}
//print suffix function
void psu(char* s) {
   struct node *ptr = head;

   if(ptr==NULL){
    printf("The list is empty. \n");fflush(stdout);
    return;
   }

   int len1 = strlen(s), len2;

   //start from the beginning
   while(ptr != NULL) {

        len2 = strlen(ptr->data);

        if( len2 >= len1 && strncmp(s, ptr->data + len2-len1 ,len1)==0){
            printf("%s :  %d\n",ptr->data,ptr->key);fflush(stdout);
        }

      ptr = ptr->next;
   }
}
//main function
int main(){

    char command[100], cmd[3] = "str";
    char strng[20];
    int val[2], count=0;

	//loop to read commands and proceed to their functions
    while(strcmp(cmd, "end")!=0) {
		printf("Command?");fflush(stdout);
        scanf("%s", cmd);

        if(strcmp(cmd,"ins")==0){

            scanf("%s", strng);
            ins(strng);
        }
        else if(strcmp(cmd,"del")==0){
            scanf("%s", strng);
            del(strng);
        }
        else if(strcmp(cmd,"fde")==0){
            scanf("%d", &val[0]);
            fde(val[0]);
        }
        else if(strcmp(cmd,"pst")==0){
            pst();
        }
        else if(strcmp(cmd,"prl")==0){
            prl();
        }
        else if(strcmp(cmd,"pcr")==0){
            scanf("%d %d", &val[0], &val[1]);
            pcr(val[0], val[1]);
        }
        else if(strcmp(cmd,"ppr")==0){
            scanf("%s", strng);
            ppr(strng);
        }
        else if(strcmp(cmd,"psu")==0){
            scanf("%s", strng);
            psu(strng);
        }

    }

    return 1;
}

