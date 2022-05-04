#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}NODE;

NODE* insert(NODE* root,int num){
   NODE*  new_node;
    if (root==NULL)
    {
        root=new_node;
        return root;
    }

    NODE*temp=root;
    while (temp!=NULL)
     {
        if (num<temp->data)
        {
           if (temp->lchild!=NULL)
            {
                temp->lchild=new_node;
                break;
            }
            else
            {
                temp=temp->lchild;
            }
         }
        else
            {
                 if (temp->rchild!=NULL)
            {
                temp->rchild=new_node;
                break;
            }
            else
            {
                temp=temp->rchild;
            }
            }
        }
  return root;
     }


NODE*create(NODE*root){
    int n,num;
    printf("enter no of elements you want to put: ");
    scanf("%d",&n);
    printf("enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        root= insert(root, num);
    }
    return root;
}



void display_leaf(NODE*root){
    if(root==NULL)
    {
        printf("NO INPUT GIVEN");
        return;
    }

    if((root->lchild=NULL) && (root->rchild=NULL))
    {
    printf("%d",root->data);
    }
    else
    {
        display_leaf (root->lchild);
        display_leaf (root->rchild);

    }
}

int search(NODE *root,int key){
  if(root->data==key){
    return 1;
  }
  else if(key<root->data)
    search(root->lchild,key);
   
  else if(key>root->data)
    search(root->rchild,key);
  else
    printf("%d is NOT present",key);
   
  }

NODE *predesesure(NODE *temp){
  temp=temp->lchild;
  while(temp->rchild!=NULL){
    temp=temp->rchild;
  }
  return temp;
}

NODE *dlt_node(NODE *root,int val){
  if(root==NULL){
    return NULL;
  }
  else if(root->data==val){
    free(root);
      return NULL;
  }
  else if(val > root->data){
    root->rchild=dlt_node(root->rchild,val);
  }
  else if(val < root->data){
    root->lchild=dlt_node(root->lchild,val);
  }
  else{
    NODE *pre=predesesure(root);
    root->data=pre->data;
    root->lchild=dlt_node(root->lchild,pre->data);
  }
 return root; 
}


void inorder(NODE *root)
{
  if(root!=NULL){
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
    }    
}

void preorder(NODE *root)
{
  if(root!=NULL){
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
    }    
}

void postorder(NODE *root)
{
  if(root!=NULL){
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
    }    
}


int main()
{
    int obs, i,key,n,x,y,ht;
    NODE *root;
    do
    {
        printf("\n\n1.Create BST\n2.Insert\n3.Select Transeversal to Display\n4.Search Element\n5.Display Leaf Node\n6.Delete Node\n0.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d", &obs);
        switch (obs)
        {

        case 1:
            root = create(root);
            break;
          case 2:
            printf("enter the no to be inserted: ");
            scanf("%d",&key);
            insert(root,key);
        case 3:
            printf("\n1.Inorder transversal\n2.Preorder    transversal\n3.Postorder transversal");
                printf("\nEnter type no to Display:");
                scanf("%d",&y);
              switch(y){
                case 1:
                    inorder(root);
                    break;
                case 2:
                    preorder(root);
                    break;
                case 3:
                    postorder(root);
                    break;
                }
              break;
        case 4:printf("Enter no to Search:");
                scanf("%d",&key);
            if(search(root,key)){
              printf("\n%d is present",key);
            }
            else{
              printf("\n%d is NOT present",key);
            }
            break;
        case 5:display_leaf(root);
              break;
        case 6:
            printf("Enter no to Dlt:");
            scanf("%d",&x);
            dlt_node(root,x);
            printf("\n*******Node is Deleted Succesfully*******");
          break;
              
  }
        }
     while (obs != 0);

    return 0;
}
