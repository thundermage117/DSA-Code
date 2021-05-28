#include<stdio.h>
#include<stdlib.h>

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
int ctr=0;
int *arr;
int DFS_help(struct Graph* graph, int vertex) 
{
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;
    if(arr[vertex]!=0)
        return arr[vertex];

    graph->visited[vertex] = 1;
    ctr++;
    int s=0;
    while (temp != NULL) 
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) 
        {
            DFS_help(graph, connectedVertex);
        }
        temp = temp->next;
    }
    return ctr;
}
int DFS(struct Graph* graph, int vertex)
{
    int v=graph->numVertices;
    for (int i = 0; i < v; i++) 
        graph->visited[i] = 0;
    int t=DFS_help(graph,vertex);
    arr[vertex]=t;
    ctr=0;
    return t;
}



int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    struct Graph* graph= createGraph(N); 
    arr=malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
        arr[i]=0;
    for(int i=0;i<M;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        addEdge(graph,--x,--y);
    }
    int max=0, max_vertex=0;
    for(int i=0;i<N;i++)
    {   
        int temp=DFS(graph,i);
        //printf("%d->%d\n",i+1,temp);
        if(temp>max)
        {
            max=temp;
            max_vertex=i+1;
        }
    }
    printf("%d",max_vertex);
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
*/