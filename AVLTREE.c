
#include<stdio.h>
#include<stdlib.h>
#define bool int
 
struct node
{
  int data;
  struct node* lc;
  struct node* rc;
};
void find(int dt,struct node **par,struct node **loc);
struct node *root;

void insert(int dt)
{
	struct node *par,*loc,*temp;
	
	find(dt,&par,&loc);
	
	if(loc!=NULL)
	{printf("node is already presesnt");
	return;
	}
	
	else
	{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=dt;
	temp->lc=NULL;
	temp->rc=NULL;
	
	if(par==NULL)
	{
		root=temp;
	}
	else
	{
		if(dt<par->data)
		{
			par->lc=temp;
			printf("inserting lc child %d",temp->data);
			
		}
		else
		{
		par->rc=temp;
		printf("inserting rc child %d",temp->data);
		}
	}	
	}
}

void find(int dt,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;
	if(root==NULL)
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	
	if(dt==root->data)
	{
	
	*loc=root;
	*par=NULL;
	return;
	}
	
	if(dt<root->data)
	{
		ptr=root->lc;
	}
	else 
		ptr=root->rc;
	ptrsave=root;
	
	while(ptr!=NULL)
	{
		if(dt==ptr->data)
		{
		*loc=ptr;
		*par=ptrsave;
		return;
		}
	
		ptrsave=ptr;
		
			if(dt<ptr->data)
			ptr=ptr->lc;
			else
			ptr=ptr->rc;
		
	}
	
	*loc=ptr;
	*par=ptrsave;
	return;
}
 
 
 void inorder(struct node *r)
{
	if(r!=NULL)
	{
		inorder(r->lc);
		printf("%d\t",r->data);
		inorder(r->rc);
	}
}


void preorder(struct node *r)
{
	if(r!=NULL)
	{
	printf("%d\t",root->data);
	inorder(r->lc);	
	inorder(r->rc);
	}
}

void postorder(struct node *r)
{
	if(r!=NULL)
	{
	
	inorder(r->lc);
	inorder(r->rc);
	printf("%d\t",r->data);
	}
}



bool isBalanced(struct node *root, int* height)
{
   
  int lh = 0, rh = 0;  
 
  
  int l = 0, r = 0;
     
  if(root == NULL)
  {
    *height = 0;
     return 1;
  }
 
  
  l = isBalanced(root->lc, &lh);
  r = isBalanced(root->rc,&rh);
 
 
  *height = (lh > rh? lh: rh) + 1;
     
 
  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;
     
 
  else return l&&r;
}
 
 

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->lc = NULL;
    node->rc = NULL;
 
    return(node);
}
 
int main()
{
  int height = 0;
    
  
 int dt,ch=1;	
	while(ch!=0)
	{	
	printf("\nTo stop inserting enter 0\n to insert enter 1 \nto display enter 3");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	printf("\nenter the value of the node");
	scanf("%d",&dt);
	insert(dt);
	break;
	

	
	case 3:		
	printf("\nINORDER \n");
	inorder(root);
	printf("\nPREORDER \n");
	preorder(root);
	printf("\nPOSTORDER \n");
	postorder(root);
	break;
}
}
  if(isBalanced(root, &height))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");    
 
  getchar();
  return 0;
}
