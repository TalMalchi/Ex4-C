#include <stdio.h>
#include "graph.h"
#include <malloc.h>
#include <math.h>
int node_numbers;


//with using :
//https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html

void insertNewNode(node **head, int id) {
    //void insertNewNode (pnode **head,int id) {
    struct GRAPH_NODE_ *newNode = malloc(sizeof(struct GRAPH_NODE_)); //create a new node
    //struct NODE *newNode; //create a new node
    newNode->node_num = id;
    newNode->next = NULL;
    newNode->edges = NULL;
    if (*head == NULL) { //if head is NULL, it is an empty list
        *head = newNode;
    } else //else, find the last node and add the newNode
    {
        struct GRAPH_NODE_ *lastNode = *head;
        while (lastNode->next != NULL && lastNode->node_num !=id) //until last node's next address will be NULL.(check if the node already exist in the list)
        {
            lastNode = lastNode->next; //precede the node to be the next node
        }

        if (lastNode->node_num !=id)//if we exit from the while because (lastNode->node_num==id) we will not add the new node, if it do not exist ,than :
        {
            lastNode->next = newNode;  //we will add the newNode at the end of the linked list
        }
    }

}


void insertNewEdge(node **Nhead,int Nsrc, int weight, int dest) {
    struct edge_ *newEdge = malloc(sizeof(struct edge_)); //create a new node
    //pnode src_node= getNode(*head, src);
    //src_node->edge->
    newEdge->weight = weight;
    pnode src_node = getNode(Nhead, Nsrc);
    pnode dest_node = getNode(Nhead, dest);
    newEdge->endpoint = dest_node;
    newEdge->next = NULL;
    if (src_node->edges == NULL) { //if head is NULL, it is an empty list
        src_node->edges = newEdge;

    } else //else, find the last node and add the newNode
    {
        struct edge_ *lastEdge = src_node->edges;
        while (lastEdge->next != NULL) //we will moove over all edges in node,last Edges's next address will be NULL.
        {
            lastEdge = lastEdge->next; //precede the Edge to be the next Edge
        }

        lastEdge->next = newEdge;  //add the newEdge at the end of the linked list
    }
}

pnode getNode(node **head, int id) { // retrun a NODE
    pnode p = *head;
    while (p!= NULL) {
        if (p->node_num == id) { //search for the node with the given id
            return p;
        } else {
            p = p->next;
        }
    }
    return NULL;//if node is not exist
}


void build_graph_cmd(pnode *head) {
    //deleteGraph_cmd(head);
    int id_node_src;
    int node_dest;
    int weight;
    int counter;
    char n;
    scanf(" %d", &node_numbers); //scan node numbers
    while (counter < node_numbers) {
        scanf(" %c", &n); //scan char 'n'
        counter++;
        scanf(" %d", &id_node_src);//get first node
        insertNewNode(head, id_node_src);
        while (scanf(" %d", &node_dest)) { //start to moove over all dest weight dest weight etc. until we get more 'n'
            insertNewNode(head, node_dest);
            scanf(" %d", &weight);
            insertNewEdge(head,id_node_src, weight, node_dest);
        }
    }
}

//function delete edges go out from node
void deleteEdges(node **head, int id)///////////////////////////////problem in while!!!
{
//    node *curr_node= getNode(*head, id);
    node *curr_node= getNode(head, id);

    if(curr_node->edges== NULL)//if there are no edges in this node
    {
        return;
    }
//    struct edge *temp = NULL;//temp is used to freeing the memory
    edge *temp;//temp is used to freeing the memory
    while (curr_node->edges!=NULL)//moove over all edges
//    while (curr_node->edges!=NULL)//moove over all edges
    {
        temp = curr_node->edges;
//        curr_node->edges->next = curr_node->edges->next->next;//edge will be disconnected from the linked list.
        curr_node->edges = curr_node->edges->next;//edge will be disconnected from the linked list.

        free(temp);//free memory
    }
    if (curr_node->edges== NULL)
    {
        printf("delete succeed");
    }

}


//void deleteGraph_cmd(pnode *head) {
//    if (*head == NULL) {
//        return;
//    }
//    pnode temp = *head; //init temp node to the head
//    edge *edge_temp;
//    while (temp) { // go all over the nodes
//        node *curr_node = temp; //init curr node
//        edge_temp = temp->edges; // init temp_edge to point the edges of
//        while (edge_temp) { //go all over the edges in the node
//            edge *curr_edge = edge_temp;
//            edge_temp = edge_temp->next; //


//function delete node (ONLY the node!!)
void deleteNode(node **head, int key) {
    struct node *temp = NULL;//temp is used to freeing the memory

    //key found on the head node.
    //move to head node to the next and free the head.
    if ((*head)->node_num == key) {
        temp = *head;    //backup to free the memory
        *head = (*head)->next;
        free(temp);
    } else { //if head is not == key
        struct GRAPH_NODE_ *current = *head;
        while (current->next != NULL) {//we will moove over all nodes
            if (current->next->node_num == key) {//if yes, we need to delete the current->next node
                temp = current->next;
                //node will be disconnected from the linked list.
                current->next = current->next->next;
                free(temp);//free memory
                break;
            }
            else { //Otherwise, move the current node and proceed
                current = current->next;
            }
        }
    }
}

void deleteGraph_cmd(pnode *head) {
    if (*head == NULL) {
        return;
    }
    pnode temp = *head; //init temp node to the head
    edge *edge_temp;
    while (temp) { // go all over the nodes
        node *curr_node = temp; //init curr node
        edge_temp = temp->edges; // init temp_edge to point the edges of
        while (edge_temp) { //go all over the edges in the node
            edge *curr_edge = edge_temp;
            edge_temp = edge_temp->next; // increase the edge by 1
            free(curr_edge);
        }
        temp = temp->next;
        free(curr_node);
        //deleteNode(head,)
    }

}

//D function - delete node and it is out edges
void Delete_node(pnode *head) {
    int id;
    scanf(" %d", &id);//id of the new node
//    if (getNode(head, id) == 0) { //check if the node exist in the graph. if it do not exist
//        insertNewNode(*head, id);//we will insert this node
//    } else { // if the node in the graph, delete it is edges
        deleteEdges(*head, id);//delete all edges go out from this node
    //}
    //function delete node (ONLY the node!!)
    deleteNode(*head, id);
}








//B function
void add_new_node(pnode *head){
    int id;
    scanf(" %d", &id);//id of the new node
    if(getNode(head, id)==0){ //check if the node exist in the graph. if it do not exist
        //insertNewNode(*head, id);//we will insert this node
//        insertNewNode(&head, id);
        insertNewNode(head, id);

    }
    else { // if the node in the graph, delete it is edges
        deleteEdges(head, id);//delete all edges go out from this node
//        edge *edgeTemp;
//        node *curr_node= getNode(*head, id);
//        edgeTemp = curr_node->edges ; // init temp_edge to point the edges of
//        while (edgeTemp != NULL) { //go all over the edges in the node
//            edge *curr_edge= edgeTemp;
//            edgeTemp= edgeTemp->next; // increase the edge by 1
//            free(curr_edge);
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



//function to decleare a memory to matrix, by using :https://easysavecode.com/8DQJlYam
int **allocate_board(int Rows, int Cols)
{
    // allocate Rows rows, each row is a pointer to int
    int **board = (int **)malloc(Rows * sizeof(int *));
    int row;

    // for each row allocate Cols ints
    for (row = 0; row < Rows; row++) {
        board[row] = (int *)malloc(Cols * sizeof(int));
    }

    return board;
}

//function put all weights in matrix num_of_nodes*num_of_nodes by src and node
//int **initMAT(pnode *headNode)
void initMAT(node **headNode,int **matOfEdgesAndNodes)
{//define mat numOfNodes*numOfNodes and the weight of every edge is written in it cell
//int matOfEdgesAndNodes[node_numbers][node_numbers];=allocate_board(node_numbers, node_numbers);//decleare a memory to matrix
    //int **matOfEdgesAndNodes = allocate_board(node_numbers,node_numbers);//decleare a memory to matrix
    struct GRAPH_NODE_ *tempNode = *headNode;//define head of the list as a temp node
    while (tempNode->next != NULL) //moving all over nodes in graph
    {
        struct edge_ *tempEdge = tempNode->edges;//define head of the list as a temp edge

        while(tempEdge->next != NULL)//moving all over edge in one node
        {
printf("tempNode->node_num: %ld ",tempNode->node_num);
printf("tempEdge->endpoint->node_num: %ld ",tempEdge->endpoint->node_num);
printf("tempEdge->weight: %ld\n",tempEdge->weight);

            matOfEdgesAndNodes[tempNode->node_num][tempEdge->endpoint->node_num]=tempEdge->weight;//define every cell as [edge src][edge dest]
            tempEdge = tempEdge->next;
        }
        tempNode = tempNode->next;
        }
//    return matOfEdgesAndNodes;
}
int* Dijkstra(pnode *head,int **Graph, int num_of_nodes_in_g, int start) {//by using : https://www.programiz.com/dsa/dijkstra-algorithm

    int cost[num_of_nodes_in_g][num_of_nodes_in_g];/* 2D array declaration*/
    int distance[num_of_nodes_in_g];
    int pred[num_of_nodes_in_g];
    int visited[num_of_nodes_in_g];
    int count;
    int mindistance;
    int nextnode, i, j;
    // Creating cost matrix
    for (i = 0; i < num_of_nodes_in_g; i++)
        for (j = 0; j < num_of_nodes_in_g; j++)
            if (Graph[i][j] == 0) //init all values as infinity
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];

    for (i = 0; i < num_of_nodes_in_g; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < num_of_nodes_in_g - 1) {
        mindistance = INFINITY;

        for (i = 0; i < num_of_nodes_in_g; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < num_of_nodes_in_g; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    //this is distance array:
    //index=dest:     0   1   2   ... n
    //weight:         x   y   z   ... f

    return distance;//distance is array that the Distance from source to i is distance[i]
}

int shortsPath_cmd(pnode *head,int src,int dest) {
    int **GeneralMAt=allocate_board(node_numbers,node_numbers);//decleare a matrix
    initMAT(head,GeneralMAt);//put inside values od weight
    int check = 0;
    node *tempNodeP = *head;
    if (tempNodeP == NULL)//if the graph empty
    {
        printf("Dijsktra shortest path:%ld",-1) ;
    }
    if (src == dest) //if source is equal to dest
    {
        printf("Dijsktra shortest path:%ld",0) ;
    }
    int *distance;
    //Dijkstra(pnode *head,int **Graph, int num_of_nodes_in_g, int start)
    distance = Dijkstra(head,GeneralMAt, node_numbers, src);
    //printf("Dijsktra shortest path:%ld",distance[dest]) ;
    return distance[dest];
}