#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree=NULL,*ptr,*stack[MAXSIZE],*stackA[MAXSIZE],*stackB[MAXSIZE];
int top=-1,topA=-1,topB=-1;
struct node *create_node(int key)
{
    ptr=malloc(sizeof(struct node));
    ptr->data=key;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
struct node *insert_node(struct node *tree,int key)
{
    if(tree==NULL)
    {
        tree=create_node(key);
        return tree;
    }
    if(key<tree->data)
    {
        tree->left=insert_node(tree->left,key);
    }
    else if(key>tree->data)
    {
        tree->right=insert_node(tree->right,key);
    }
    return tree;
}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {       
        inorder(tree->left);
        printf("%d\t",tree->data);
        inorder(tree->right);
    }
}

void postorder(struct node *tree)
{
    if(tree!=NULL)
    {       
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t",tree->data);
    }
}
void preorder_nonrecursive(struct node *tree)
{
    while(1)
    {
        if(tree!=NULL)
        {
            printf("%d\t",tree->data);
            top++;
            stack[top]=tree;
            tree=tree->left;
        }
        else
        {
            if(top!=-1)
            {
                tree=stack[top];
                top--;
                tree=tree->right;
            }
            else
            {
                break;
            }
        }
    }
}

void inorder_nonrecursive(struct node *tree)
{
    while(1)
    {
        if(tree!=NULL)
        {
            top++;
            stack[top]=tree;
            tree=tree->left;
        }
        else
        {
            if(top!=-1)
            {
                tree=stack[top];
                top--;
                printf("%d\t",tree->data);
                tree=tree->right;
            }
            else
            {
                break;
            }
        }
    }
}
void postorder_nonrecursive(struct node *tree)
{
    topA++;
    stackA[topA]=tree;
    //while(tree!=NULL)
    //{
    while(topA!=-1)
    {
        tree=stackA[topA];
        topA--;
        topB++;
        stackB[topB]=tree;
        if(tree->left!=NULL)
        {
            topA++;
            stackA[topA]=tree->left;
        }
        if(tree->right!=NULL)
        {
            topA++;
            stackA[topA]=tree->right;
        } 
    }
    while(topB!=-1)
    {
        tree=stackB[topB];
        topB--;
        printf("%d\t",tree->data);
    }
   // }
}
void tree_search(struct node *tree,int val)
{
    if(tree==NULL)
        printf("%d not found.",val);
    else if(val==tree->data)
        printf("%d exists in the tree.",val);
    else if(val<tree->data)
        tree_search(tree->left,val);
    else
        tree_search(tree->right,val);
}
void main()
{
    int n,key,ch,val;
    printf("\t\tBINARY SEARCH TREE----->");
    printf("\n1.CREATE THE TREE.");
    printf("\n2.PREORDER(RECURSIVE) TRAVERSAL.");
    printf("\n3.INORDER(RECURSIVE) TRAVERSAL.");
    printf("\n4.POSTORDER(RECURSIVE) TRAVERSAL.");
    printf("\n5.PREORDER(NON-RECURSIVE) TRAVERSAL.");
    printf("\n6.INORDER(NON-RECURSIVE) TRAVERSAL.");
    printf("\n7.POSTORDER(NON-RECURSIVE) TRAVERSAL.");
    printf("\n8.SEARCH A VALUE IN THE TREE.");
    printf("\n9.SORT THE TREE.");
    printf("\n10.EXIT.");
    do{
        printf("\n\nEnter choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nHow many keys do you want to enter?\n");
            scanf("%d",&n);
            printf("\nEnter the keys :\n\n");
            for(int i=1;i<=n;i++)
            {
                printf("Enter key %d : ",i);
                scanf("%d",&key);
                tree=insert_node(tree,key);
            }
            break;
            case 2:
            printf("\nPreorder Traversal of the tree is :\n");
            preorder(tree);
            break;
            case 3:
            printf("\nInorder Traversal of the tree is :\n");
            inorder(tree);
            break;
            case 4:
            printf("\nPostorder Traversal of the tree is :\n");
            postorder(tree);
            break;
            case 5:
            printf("\nNon-Recursive Preorder Traversal is :\n");
            preorder_nonrecursive(tree);
            break;
            case 6:
            printf("\nNon-Recursive Inorder Traversal is :\n");
            inorder_nonrecursive(tree);
            break;
            case 7:
            printf("\nNon-Recursive Postorder Traversal is :\n");
            postorder_nonrecursive(tree);
            break;
            case 8:
            printf("\nEnter the value to be searched :\n");
            scanf("%d",&val);
            tree_search(tree,val);
            break;
            case 9:
            printf("\nThe tree in sorted order is :\n");
            inorder(tree);
            break;
            case 10:
            printf("THANKS FOR USING ;)");
            break;
            default:
            printf("INVALID CHOICE!!!!");
            break;
        }
    }while(ch!=10);
}