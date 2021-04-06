//PARANTHESIS REPRESENTATION FROM input

#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* p;
	struct node* left;
	int data;
	struct node* right;
};

struct qnode{
    struct node* data;
    struct qnode* next;
    
};

struct queue{
    struct qnode* head;
    struct qnode* tail;
};

struct node* NewNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->p = NULL;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	return temp;
	
}


struct queue* Enqueue(struct queue* Q,struct node* temp){
    struct qnode* qnod = (struct qnode*)malloc(sizeof(struct qnode));
    qnod->data = temp;
    qnod->next = NULL;
    if(Q->head == NULL && Q->tail == NULL){
        Q->head = qnod;
        Q->tail = qnod;
        return Q;
    }
    Q->tail->next = qnod;
    Q->tail = qnod;
    return Q;
}


struct node* Dequeue(struct queue* Q){
    if(Q->head == NULL)return NULL;
    if(Q->head == Q->tail ){
        struct node* temp = Q->head->data;
        Q->head = NULL;
        Q->tail = NULL;
        return temp;
    }
    struct node* temp = Q->head->data;
    Q->head = Q->head->next;
    return temp;
}

struct node* INSERT(struct node* root,int k){
	struct node* temp = NewNode(k);
	if(root == NULL){
		root = temp;
		return root;
	}
	else{
		struct node* ptr = root;
		
		struct queue* Q = (struct queue*)malloc(sizeof(struct queue));
		Q->head= NULL;
		Q->tail = NULL;
		while(ptr!= NULL){
			if(ptr->left!= NULL){
				Q = Enqueue(Q,ptr->left);
			}
			else{
				ptr->left = temp;
				temp->p = ptr;
				return root;
			}
			
			if(ptr->right!= NULL){
				Q = Enqueue(Q,ptr->right);
				
			}
			else{
				ptr->right = temp;
				temp->p = ptr;
				return root;
				
			}
			ptr = Dequeue(Q);
		}
	}
}


void PRINT(struct node* temp){
	if(temp == NULL){
		printf("( ) ");
		return;
	}
	printf("( ");
	printf("%d ",temp->data);
	PRINT(temp->left);
	PRINT(temp->right);
	if(temp->p == NULL )printf(")");
	else printf(") ");
	
}

void main(){
	struct node* root = NULL;
	
	char x;
	int k;
	
	while(1){
		scanf("%c",&x);
		
		if(x=='i'){
			scanf("%d",&k);
			root = INSERT(root,k);
		}
		if(x=='p'){
			PRINT(root);
		}
		if(x=='e'){break;}
	}


}

