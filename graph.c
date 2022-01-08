#include <stdio.h>
#include "graph.h"
#include <malloc.h>
//#include <math.h>
#define INFINITY 999999
int node_numbers;
int MAX_id = -1;

//with using :
//https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html

void insertNewNode(node **head, int id)
{
    if (*head == NULL)//if head is NULL, it is an empty list
    {                                                                     
        struct GRAPH_NODE_ *newNode = malloc(sizeof(struct GRAPH_NODE_)); //create a new node
        newNode->node_num = id;
        newNode->next = NULL;
        newNode->edges = NULL;

        *head = newNode;
    }
    else //else, find the last node and add the newNode
    {
        struct GRAPH_NODE_ *lastNode = *head;
        while (lastNode->next != NULL && lastNode->node_num != id) //until last node's next address will be NULL.(check if the node already exist in the list)
        {
            lastNode = lastNode->next; //precede the node to be the next node
        }

        if (lastNode->node_num != id) //if we exit from the while because (lastNode->node_num==id) we will not add the new node, if it do not exist ,than :
        {
            struct GRAPH_NODE_ *newNode = malloc(sizeof(struct GRAPH_NODE_)); //create a new node
            newNode->node_num = id;
            newNode->next = NULL;
            newNode->edges = NULL;
            lastNode->next = newNode; //we will add the newNode at the end of the linked list
        }
    }
    if (MAX_id < id + 1)
    {
        MAX_id = id + 1;
    }
}

void insertNewEdge(node **Nhead, int Nsrc, int weight, int dest)
{
    struct edge_ *newEdge = malloc(sizeof(struct edge_)); //create a new node
    newEdge->weight = weight;
    pnode src_node = getNode(Nhead, Nsrc);
    pnode dest_node = getNode(Nhead, dest);
    newEdge->endpoint = dest_node;
    newEdge->next = NULL;
    if (src_node->edges == NULL)
    { //if head is NULL, it is an empty list
        src_node->edges = newEdge;
    }
    else //else, find the last node and add the newNode

    {
        struct edge_ *lastEdge = src_node->edges;
        while (lastEdge->next != NULL) //we will moove over all edges in node,last Edges's next address will be NULL.
        {
            lastEdge = lastEdge->next; //precede the Edge to be the next Edge
        }

        lastEdge->next = newEdge; //add the newEdge at the end of the linked list
    }
}

pnode getNode(node **head, int id)
{ // retrun a NODE
    pnode p = *head;
    while (p != NULL)
    {
        if (p->node_num == id)
        { //search for the node with the given id
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return NULL; //if node is not exist
}

void build_graph_cmd(pnode *head)
{
    int id_node_src = 0;
    int node_dest = 0;
    int weight = 0;
    int counter = 0;
    char n = 'a';
    scanf(" %d", &node_numbers); //scan node numbers
    while (counter < node_numbers)
    {
        scanf(" %c", &n); //scan char 'n'
        counter++;
        scanf(" %d", &id_node_src); //get first node
        insertNewNode(head, id_node_src);

        while (scanf(" %d", &node_dest))
        { //start to moove over all dest weight dest weight etc. until we get more 'n'
            insertNewNode(head, node_dest);
            scanf(" %d", &weight);
            insertNewEdge(head, id_node_src, weight, node_dest);
        }
    }
}

//function delete edges go out from node
void deleteEdges_FromNode(node **head, int id)
{
    node *curr_node = getNode(head, id);

    if (curr_node->edges == NULL) //if there are no edges in this node
    {
        return;
    }
    edge *temp; //temp is used to freeing the memory
    while (curr_node->edges != NULL) //moove over all edges
                                     //    while (curr_node->edges!=NULL)//moove over all edges
    {
        temp = curr_node->edges;
        curr_node->edges = curr_node->edges->next; //edge will be disconnected from the linked list.

        free(temp); //free memory
    }
}

//function delete node (ONLY the node!!)
void deleteNode(node **head, int key)
{
    node *temp = NULL; //temp is used to freeing the memory

    //key found on the head node.
    //move to head node to the next and free the head.
    if ((*head)->node_num == key)
    {
        temp = *head; //backup to free the memory
        *head = (*head)->next;
        free(temp);
    }
    else
    { //if head is not == key
        struct GRAPH_NODE_ *current = *head;
        while (current->next != NULL)
        { //we will moove over all nodes
            if (current->next->node_num == key)
            { //if yes, we need to delete the current->next node
                temp = current->next;
                //node will be disconnected from the linked list.
                current->next = current->next->next;
                free(temp); //free memory
                break;
            }
            else
            { //Otherwise, move the current node and proceed
                current = current->next;
            }
        }
    }
}

void deleteGraph_cmd(pnode *head)
{
    MAX_id = -1;
    if (*head == NULL)
    {
        return;
    }
    pnode temp = *head; //init temp node to the head
    edge *edge_temp;
    while (temp != NULL)
    {                            // go all over the nodes
        node *curr_node = temp;  //init curr node
        edge_temp = temp->edges; // init temp_edge to point the edges of
        while (edge_temp != NULL)
        { //go all over the edges in the node
            edge *curr_edge = edge_temp;
            edge_temp = edge_temp->next; // increase the edge by 1
            free(curr_edge);
        }
        temp = temp->next;
        free(curr_node);
    }
}

//D function - delete node and it is out & in edges
void Delete_node(pnode *head)
{
    int id;
    scanf(" %d", &id); //id of the new node
    deleteEdges_TONode(head, id);

    deleteEdges_FromNode(head, id); //delete all edges go out from this node

    
    //function delete node (ONLY the node!!)
    deleteNode(head, id);
}

//function delete edges go out from node
void deleteEdges_TONode(node **head, int id)
{
    struct GRAPH_NODE_ *tempNode = *head; //define head of the list as a temp node
    struct edge_ *tempEdge;
    while (tempNode != NULL) //moving all over nodes in graph
    {

        if (tempNode->edges != NULL && tempNode->edges->endpoint->node_num == id)
        {

            tempEdge = tempNode->edges; //backup to free the memory
            tempNode->edges = tempNode->edges->next;
            free(tempEdge);
        }
        else if (tempNode->edges != NULL)
        {
            struct edge_ *currEdge = tempNode->edges; //define head of the list as a temp edge

            while (currEdge->next != NULL) //moving all over edge in one node
            {

                if (currEdge->next->endpoint->node_num == id) //if this is the dest node, we will remove this edge
                {

                    tempEdge = currEdge->next;
                    //node will be disconnected from the linked list.
                    currEdge->next = currEdge->next->next;
                    free(tempEdge);
                }
                else
                {
                    currEdge = currEdge->next;
                }
            }
        }
        tempNode = tempNode->next;
    }
}

//B function
void add_new_node(pnode *head)
{
    int id;
    scanf(" %d", &id); //id of the new node
    if (getNode(head, id) == 0)
    {
        insertNewNode(head, id);
    }
    else  // if the node in the graph, delete it is edges
    { 
        deleteEdges_FromNode(head, id); //delete all edges go out from this node
    }
    int weight;
    int dest;
    while (scanf(" %d", &dest))
    { //start to moove over all dest weight dest weight etc. until we get more 'n'
        insertNewNode(head, dest);
        scanf(" %d", &weight);
        insertNewEdge(head, id, weight, dest);
    }
}

int **allocfunc(int rows, int cols)
{
    int i;
    int **array;
    /* allocate the array */
    array = malloc(rows * sizeof *array);
    for (i = 0; i < rows; i++)
    {
        array[i] = malloc(cols * sizeof *array[i]);
    }
    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            array[i][j] = 0;
        }
    }
    return array;
}

void initMAT(node **headNode, int **matOfEdgesAndNodes)
{

    struct GRAPH_NODE_ *tempNode = *headNode; //define head of the list as a temp node
    while (tempNode != NULL)                  //moving all over nodes in graph
    {
        struct edge_ *tempEdge = tempNode->edges; //define head of the list as a temp edge

        while (tempEdge != NULL) //moving all over edge in one node
        {
            matOfEdgesAndNodes[tempNode->node_num][tempEdge->endpoint->node_num] = tempEdge->weight; //define every cell as [edge src][edge dest]
            tempEdge = tempEdge->next;
        }
        tempNode = tempNode->next;
    }
}
int *Dijkstra(pnode *head, int **Graph, int num_of_nodes_in_g, int start)
{ //by using : https://www.programiz.com/dsa/dijkstra-algorithm

    int cost[num_of_nodes_in_g][num_of_nodes_in_g]; /* 2D array declaration*/
    int *distance = (int *)malloc(num_of_nodes_in_g * sizeof(int));
    int visited[num_of_nodes_in_g];
    int count = 0;
    int mindistance = 0;
    int nextnode = 0, i = 0, j = 0;
    // Creating cost matrix
    for (i = 0; i < num_of_nodes_in_g; i++)
        for (j = 0; j < num_of_nodes_in_g; j++)
        {
            if (Graph[i][j] == 0)
            { //init all values as infinity
                cost[i][j] = INFINITY;
            }
            else
                cost[i][j] = Graph[i][j];
        }
    for (i = 0; i < num_of_nodes_in_g; i++)
    {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < num_of_nodes_in_g - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < num_of_nodes_in_g; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }

        if (mindistance != INFINITY)
        {
            visited[nextnode] = 1;
        }
        for (i = 0; i < num_of_nodes_in_g; i++)
            if (!visited[i])
            {

                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                }
            }
        count++;
    }
    return distance; //distance is array that the Distance from source to i is distance[i]
}
void printfunc(int **array, int rows, int cols)
{
    int i, j;
    printf("r=%d, c=%d\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
int shortsPath_cmd(pnode *head, int src, int dest)
{
    int **GeneralMAt;
    GeneralMAt = allocfunc(MAX_id, MAX_id); //decleare a matrix
    initMAT(head, GeneralMAt);              //put inside values od weight
    int *distance;
    distance = Dijkstra(head, GeneralMAt, MAX_id, src);
    int tempDistance = distance[dest];
    for (int i = 0; i < MAX_id; i++) /* deallocate the array */
    {
        free(GeneralMAt[i]);
    }
    free(GeneralMAt);

    free(distance); /* deallocate the array */
    return tempDistance;
}

void TSP(pnode *head)
{
    int cities, temp; //total number of the cities
    int min_dis = INFINITY;
    int temp_dis = 0;
    scanf(" %d", &cities);

    ///////////check if malloc isnt null///////
    int *arr = (int *)malloc(cities * sizeof(int)); //init array of the cities
    for (int i = 0; i < cities; ++i)
    {
        scanf(" %d", &arr[i]);
    }
    for (int j = 1; j <= cities; j++)
    {
        temp_dis = 0;
        for (int i = 0; i < cities - 1; i++)
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        for (int k = 0; k < cities - 1 && temp_dis != INFINITY; k++)
        {

            int curr_dis = shortsPath_cmd(head, arr[k], arr[k + 1]);
            if (curr_dis == INFINITY)
                temp_dis = INFINITY;
            else
                temp_dis += curr_dis;
        }
        if (temp_dis < min_dis)
            min_dis = temp_dis;
    }
    if (min_dis == INFINITY)
    {
        min_dis = -1;
    }
    printf("TSP shortest path: %d \n", min_dis);
    free(arr);
}