/*author : suraj kamble
version : 1.0

 */

#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};


	struct node *start= NULL;

struct node  *insert(struct node *start,int value){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode ->data = value;
	newnode ->next = start;
	start= newnode;
	return start;

}




void display(struct node *start){
	struct node *temp;
	temp = start;
	if(start == NULL){
		printf("empty list\n");
		exit(0);
	}
	while(temp->next!=NULL){

		temp= temp->next;
		printf("%d\t",temp->data);
	}
}

int Delete_Given(struct node *start, int given){
	struct node *temp,*preptr,*cptr;
	int count=0;
	temp=preptr=cptr=start;
	if(start == NULL){
		printf("\a");

		printf("no elements in the list\n");
		exit(0);
		}else{
			while(temp->data !=given){
				preptr  = temp;
				temp = temp->next;
				++count;
				cptr = temp;


			}
			preptr->next = cptr->next;
			free(cptr);
		}
	return count;
}

 // void PrintRev(struct node *start){
 //   struct node *temp,preptr;
 //   temp=start;

 //   while(temp->next!=NULL){

	// temp = temp->next;

	// }

	// while(temp !=start){



	// }

 // }




int menu(){
	int ch;

	printf("\n1.insert a node\n2.display\n3.exit\n4.Delete Given node\n5.clear screen\n");
	printf("\nenter choice\n");
	scanf("%d",&ch);

	return ch;
}

main(){
	int value,ch,given,pos;
system("cls");
	do{
		ch = menu();
		switch(ch){
			case 1:
				printf("enter the data to insert\n");
				scanf("%d",&value);
				start = insert(start,value);

				break;

			case 2:
				display(start);

				break;

				case 3:
					printf("\a");
					printf("bye bye\n");
					exit(0);

			case 4:
				printf("enter the element to delete in the list\n");
				scanf("%d",&given);
				 pos=Delete_Given(start,given);

				 printf("deleted item location is %d",pos);

				 break;
			case 5:
                system("cls");
                break;

		}

	}while(1);
}







