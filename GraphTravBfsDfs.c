// Instructions
// A social media platform needs to implement Graph Traversals (BFS & DFS) to find friends and mutual connections between users in their friend network.
// Scenario
// Friend Network:
// Users: A B C D E F
// Edges: A-B, A-C, B-D, B-E, C-F, D-E, E-F
// Tasks to Implement
// Adjacency List Representation
// BFS Traversal (Level Order)
// DFS Traversal (Path Order)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* adj[6];
int visited[6];

struct node* createNode(int v)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

void addEdge(int src, int dest)
{
    struct node* newnode = createNode(dest);
    newnode->next = adj[src];
    adj[src] = newnode;
    newnode = createNode(src);
    newnode->next = adj[dest];
    adj[dest] = newnode;
}

void BFS(int start)
{
    int queue[10], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    
    while(front < rear)
    {
        int v = queue[front++];
        printf("%c ", v + 'A');
        struct node* temp = adj[v];
        
        while(temp)
        {
            if(!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

void DFS(int v)
{
    visited[v] = 1;
    printf("%c ", v + 'A');
    struct node* temp = adj[v];
    
    while(temp)
    {
        if(!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }
}

int main()
{
    for(int i = 0; i < 6; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,5);
    addEdge(3,4);
    addEdge(4,5);

    printf("BFS Traversal: ");
    BFS(0);
    printf("\n");
    
    for(int i = 0; i < 6; i++)
    {
        visited[i] = 0;
    }
    
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");
    
    return 0;
}