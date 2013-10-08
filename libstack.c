__thread struct Node *top;

struct Node
{
    int Data;
    struct Node *next;
}*key;

void popStack()
{
    struct Node *temp, *var=top;
    if(var==top)
    {
        top = top->next;
        free(var);
    }
    else
    printf("\nStack Empty");
}

void push(int value)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->Data=value;
    if (top == NULL)
    {
         top=temp;
         top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

void display()
{
     struct Node *var=top;
     if(var!=NULL)
     { 
          printf("\nElements are as:\n");
          while(var!=NULL)
          {
               printf("\t%d\n",var->Data);
               var=var->next;
          } 
     printf("\n");
     }
     else
     printf("\nStack is Empty");
}