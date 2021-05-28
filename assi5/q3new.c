#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node 
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph 
{
    int numVertices;
    int* visited;
    struct node** adjLists;
};

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
 
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

struct node* createNode(int v) 
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) 
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++) 
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) 
{
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
int ctr=INT_MAX;

void DFS(struct Graph* graph, int vertex) 
{
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  //printf("%d ", vertex);
  if(vertex<ctr)
    ctr=vertex;
  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) 
    {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

void fill(int s,struct Graph* graph,struct Stack* stack)
{
    graph->visited[s]=1;
    struct node* adjList = graph->adjLists[s];
    struct node* temp = adjList;
    while (temp!=NULL)
    {
        int i=temp->vertex;
        if(graph->visited[i]==0)
            fill(i,graph,stack);

        temp = temp->next;
    }
    push(stack,s);
}
int *arr;
int max_vertex=0,max=0;
void printscc(struct Graph* graph,struct Graph* graphrev,struct Stack* stack)
{
    for (int i = 0; i < graph->numVertices; i++)
    if (graph->visited[i] == 0)
        fill(i, graph, stack);
    int count=0;
  while (!isEmpty(stack)) 
  {
    int s = peek(stack);
    pop(stack);

    if (graphrev->visited[s] == 0) 
    {
      DFS(graphrev,s);
      arr[count]=ctr;
      count++;
      ctr=INT_MAX;
      //printf("\n");
    }
  }
}
int ctr1=0;
void BFS_help(struct Graph* graph, int vertex) 
{
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    //printf("%d ",vertex);
    ctr1++;
    while (temp != NULL) 
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) 
        {
            BFS_help(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
int BFS(struct Graph* graph, int vertex)
{
    int v=graph->numVertices;
    for (int i = 0; i < v; i++) 
        graph->visited[i] = 0;
    BFS_help(graph,vertex);
    int t=ctr1;
    ctr1=0;
    return t;
}




int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    struct Graph* graph= createGraph(N); 
    struct Graph* graphrev=createGraph(N);
    struct Stack* stack= createStack(N);
    struct Graph* copy= createGraph(N);
    arr=malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
        arr[i]=-1;
    for(int i=0;i<M;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        addEdge(graph,--x,--y);
        addEdge(copy,x,y);
        addEdge(graphrev,y,x);
    }
    printscc(graph,graphrev,stack);
    //for(int i=0;i<N;i++)
    //    printf("%d->%d ",i,arr[i]);
    for(int i=0;i<N;i++)
    {   int te=arr[i];
        if(te==-1)
            break;
        int temp=BFS(copy,te);
        //printf("%d->%d\n",i+1,temp);
        //printf("\n");
        if(temp>max||(temp==max && te<max_vertex))
        {
            max=temp;
            max_vertex=te;
        }
    }
    printf("%d",max_vertex+1);
    return 0;
}
    

/*
8 7
4 2
2 3
1 2
5 1
5 6
7 1
7 8

8 9
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
7 8
*/