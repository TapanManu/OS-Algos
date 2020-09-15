#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data[10];
	struct node* lc;
	struct node* rc;
};
struct node*ptr,*root;

void inorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lc);
		printf("%s\t",ptr->data);
		inorder(ptr->rc);
			
	}	
	else
	{
		return ;
	}
} 
struct node* searchparent(char* key,struct node* ptr,struct node* parent)
{   
    struct node*ptr1,*ptr2,*par;;
    ptr1=(struct node*)malloc(sizeof(struct node));
    ptr2=(struct node*)malloc(sizeof(struct node));
    printf("parent directory:%s\n",parent->data);
    if(strcmp((ptr->data),key))
    {
        ptr1=ptr->lc;
        ptr2=ptr->rc;
        if(ptr1!=NULL)
        {   printf("hi1");
            printf("parent data:%s\n",ptr->data);
            printf("ptr left child:%s\n",ptr1->data);
            par=searchparent(key,ptr1,ptr);
            
            
            	if(!strcmp(par->data,key))
            	{
                	return par;
            	}
           	
        }
        if(ptr2!=NULL)
        {
            printf("parent data:%s\n",ptr->data);
            printf("ptr right child:%s\n",ptr2->data);
            par=searchparent(key,ptr2,ptr);
            
            
            	if(!strcmp(par->data,key))
           	 		{
                		return par;
            		}
            
        }
    }
    else if(!strcmp(ptr->data,key))
    {
        printf("hi3\n");
        return ptr;   
    }
}
void insert_tree(struct node* root)
{
	struct node* ptr,*l,*new;
	char key[10];
	int opt=1;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=root;
	new=(struct node*)malloc(sizeof(struct node));
    l=(struct node*)malloc(sizeof(struct node));
	printf("enter the node in which you want to insert the data");
	scanf("%s",key);
	l=searchparent(key,ptr,root);
	if(l==NULL)
	{
		printf("search is unsuccessful\n");
		return;
	}
		if((l->lc==NULL)||(l->rc==NULL))
		{
			printf("choose to left(1) or right(0)");
			scanf("%d",&opt);
			if (opt==1)
			{
				if(l->lc==NULL)
				{
					l->lc=new;
					printf("data to be inserted\n");
					scanf("%s",(new->data));
					new->lc=NULL;
					new->rc=NULL;
				}
				else
					printf("cannot insert\n");
			}
			else if(opt==0)
			{
				if(l->rc==NULL)
				{
					l->rc=new;
					printf("data to be inserted\n");
					scanf("%s",(new->data));
					new->lc=NULL;
					new->rc=NULL;
				}	
				else
					printf("cannot insert\n");
			}
		}	
		else
		{
			printf("insertion not possible");
		}
}
void create_tree(struct node* ptr,int count)
{
	int ch=1,ch1=1,ch2=1;
	struct node* new,*new1;
	printf("\ndo you want to enter data again?\n");
	scanf("%d",&ch);
	if(ch==0)
	{
		printf("no data entry\n");
		return;
	}
	printf("\npress 1 to insert as left child of %s\n",ptr->data);
	scanf("%d",&ch1);
	if(ch1==1 && (ptr->lc==NULL))
	{
		new=(struct node*)malloc(sizeof(struct node));
		printf("enter the data of node");
		scanf("%s",(new->data));
		printf("\nptr->data:%s\n",new->data);
		new->lc=NULL;
		new->rc=NULL;
		ptr->lc=new;
		create_tree(ptr->lc,2*count);
	}
	else
	{
		printf("no insertion at left node\n");
	}
	printf("press 1 to insert as right child of %s\n",ptr->data);
	scanf("%d",&ch2);
	if(ch2==1 && (ptr->rc==NULL))
	{
		new1=(struct node*)malloc(sizeof(struct node));
		printf("enter the data of node");
		scanf("%s",(new1->data));
		printf("ptr->data:%s\n",new1->data);
		new1->lc=NULL;
		new1->rc=NULL;
		ptr->rc=new1;
		create_tree(ptr->rc,2*count+1);
	}
	else
	{
		printf("no insertion at right node\n");
	}
}	
void main()
{
	int count=1;
	root=(struct node*)malloc(sizeof(struct node));
	printf("enter data to root\n");
	scanf("%s",(root->data));
	create_tree(root,count);
	printf("directory structure\n");
	inorder(root);
	printf("\n");
	insert_tree(root);
	printf("\ndirectory structure\n");
	inorder(root);
}
/*
enter data to root
root

do you want to enter data again?
1

press 1 to insert as left child of root
home
enter the data of node
ptr->data:home

do you want to enter data again?
0
no data entry
press 1 to insert as right child of root
1
enter the data of nodefiles
ptr->data:files

do you want to enter data again?
0
no data entry
directory structure
home	root	files	
enter the node in which you want to insert the datahome
parent directory:root
hi1parent data:root
ptr left child:home
parent directory:root
hi3
choose to left(1) or right(0)1
data to be inserted
tapan

directory structure
tapan	home	root	files	
*/
