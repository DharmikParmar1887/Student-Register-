#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char Name[10];
    int Number;
    struct node *left;
    struct node *right;
};

struct node* makeNode(struct node *r,struct node **root)           //Function to make tree
{
    struct node *temp=*root;
    struct node *f=(struct node*)malloc(sizeof(struct node));
     printf("Enter name: ");
        scanf("%s",f->Name);
        printf("Enter Roll-number(Temporary given at admission time): ");
        scanf("%d",&f->Number);
        f->left=NULL;
        f->right=NULL;

    if(*root==NULL)
    {

        r=f;
        *root=r;
        return r;
    }

           while(1)
            {
             if(strcmp(temp->Name,f->Name)>0)
             {
                 if(temp->left==NULL)
                 {temp->left=f;
                  break;}
             temp=temp->left;
             }
             else
              {
                   if(temp->right==NULL)
                {temp->right=f;
                 break;}
                   temp=temp->right;
              }
            }


    return r;
}

struct node* search(struct node *root,char *name,struct node **parent)  /* Function to search(Which will return the node and it's parent node*/
{

    int count=0;

    struct node *s;s=root;int l=strlen(name);

    while(1)
    {

        if(strcmp(s,name)==0)
        {count++;
            break;}
        else if(strcmp(s,name)<0)
            {if(s->right==NULL)
              break;
             *parent=s;
            s=s->right;}
        else
            {if(s->left==NULL)
              break;
              *parent=s;
            s=s->left;}
    }

    if(count!=0)
    {
      return s;}
      else
      {printf("\nNo such person!\n");
       return NULL;}
}


void inOrder(struct node *root)  // To print In-Order
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%s ",root->Name);
        inOrder(root->right);
    }
}

void postOrder(struct node *root) // To print Post-Order
{
    if(root!=NULL)
    {
        postOrder(root->right);
        printf("%s ",root->Name);
        postOrder(root->left);
    }
}

void del(struct node *root,char *name)       // To delete
{
    struct node *parent=NULL;
    struct node *temp;
temp=search(root,name,&parent);
if(temp==NULL)                               // If no such element exist
    printf("\nNo such person exist...\n");



else
{
    if(temp->left==NULL&&temp->right==NULL)     // Leaf node condition
        {

       if(parent->left==temp)
          parent->left=NULL;
       else
        parent->right=NULL;
        free(temp);}

    else if(temp->left==NULL||temp->right==NULL)  // Node with one child condition
    {
        if(temp->left!=NULL)
        {
            if(strcmp(parent->Name,name)<0)
            {

                parent->right=temp->left;
                free(temp);
            }
            else
            {

                parent->left=temp->left;
                free(temp);
            }

        }
        else
        {

             if(strcmp(parent->Name,name)>0)
            {

                parent->left=temp->right;
                free(temp);
            }
            else
            {

                parent->right=temp->right;
                free(temp);
            }
        }
    }
    else                                            // ode with two child condition
    {

        struct node *backup=temp,*parent2=NULL;
        parent2=temp;
        temp=temp->left;



        while(1)
            {if(temp->right==NULL)
             break;
             parent2=temp;
             temp=temp->right;}


         (backup->Number)=(temp->Number);
         strcpy(backup->Name,temp->Name);

         if(backup->left==temp)
            backup->left=NULL;
         else
            parent2->right=NULL;
         free(temp);


    }
}

}

int main()
{
    struct node *root=NULL,*r=NULL,*parent=NULL;
     char s[10];
    int a;
    while(1)
    {
        printf("\n1.Enter\n2.Delete\n3.Search\n4.Ascending\n5.Descanding\n6.Exit\n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            r=makeNode(r,&root);
            break;
        case 2:
            printf("Enter name you want to Delete: ");
            scanf("%s",s);
            del(root,s);
            break;
        case 3:

            printf("Enter name you want to search: ");
            scanf("%s",s);
            struct node *searched=search(root,s,&parent);
            printf("searched successfully\n");
            if(searched!=NULL)
                printf("\nName: %s\nNumber: %d\n",searched->Name,searched->Number);

            break;
        case 4:
            printf("In Ascending dictionary order: ");
            inOrder(root);
            break;
        case 5:
            printf("In Descanding descanding order: ");
            postOrder(root);
            break;
        case 6:
            return 0;
        }
    }
}
