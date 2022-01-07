#include <stdio.h>
#include "graph.h"
#include <malloc.h>
//#include <math.h>
#define INFINITY 999999
int node_numbers;
int MAX_id=-1;

//with using :
//https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html

void insertNewNode(node **head, int id) {
    //void insertNewNode (pnode **head,int id) {
    struct GRAPH_NODE_ *newNode = malloc(sizeof(struct GRAPH_NODE_)); //create a new node
    printf("inserting node_id_num=%d\n",id);
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
    if(MAX_id<id+1)
    {
        MAX_id=id+1;
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
    //just for debugging
//    if (curr_node->edges== NULL)
//    {
//        printf("delete succeed");
//    }

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
    MAX_id=-1;
    if (*head == NULL) {
        return;
    }
    pnode temp = *head; //init temp node to the head
    edge *edge_temp;
    while (temp!=NULL) { // go all over the nodes
        node *curr_node = temp; //init curr node
        edge_temp = temp->edges; // init temp_edge to point the edges of
        while (edge_temp!=NULL) { //go all over the edges in the node
            edge *curr_edge = edge_temp;
            edge_temp = edge_temp->next; // increase the edge by 1
            free(curr_edge);
        }
        temp = temp->next;
        printf("deleting node num:%d\n",curr_node->node_num);
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
//int **allocate_board(int Rows, int Cols)
//{
//    // allocate Rows rows, each row is a pointer to int
//    int **board = (int **)malloc(Rows * sizeof(int *));
//    int row;
//
//    // for each row allocate Cols ints
//    for (row = 0; row < Rows; row++) {
//        board[row] = (int *)calloc(Cols , sizeof(int));
//    }
//
//    return board;
//}

int * allocfunc( int rows, int cols){
    int i;
    int ** array;
    /* allocate the array */
    array = malloc(rows * sizeof *array);
    for (i=0; i<rows; i++)
    {
        array[i] = malloc(cols * sizeof *array[i]);
    }
    for (i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            //printf("i=%d j=%d " ,i,j);
            array[i][j] = 0;
        }
    }
    //printf("\narr=%d\n", array);
    return array;
}

//function put all weights in matrix num_of_nodes*num_of_nodes by src and node
//int **initMAT(pnode *headNode)
void initMAT(node **headNode,int **matOfEdgesAndNodes)
{//define mat numOfNodes*numOfNodes and the weight of every edge is written in it cell
//int matOfEdgesAndNodes[node_numbers][node_numbers];=allocate_board(node_numbers, node_numbers);//decleare a memory to matrix
    //int **matOfEdgesAndNodes = allocate_board(node_numbers,node_numbers);//decleare a memory to matrix
    struct GRAPH_NODE_ *tempNode = *headNode;//define head of the list as a temp node
    while (tempNode != NULL) //moving all over nodes in graph
    {
        struct edge_ *tempEdge = tempNode->edges;//define head of the list as a temp edge

        while(tempEdge != NULL)//moving all over edge in one node
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
int *Dijkstra(pnode *head,int **Graph, int num_of_nodes_in_g, int start) {//by using : https://www.programiz.com/dsa/dijkstra-algorithm

    int cost[num_of_nodes_in_g][num_of_nodes_in_g];/* 2D array declaration*/
    int *distance=(int*)malloc(num_of_nodes_in_g * sizeof(int));
    int pred[num_of_nodes_in_g];
    int visited[num_of_nodes_in_g];
    int count;
    int mindistance;
    int nextnode=0, i, j;
    //printf("nextnode=%d\n",nextnode);
    // Creating cost matrix
    for (i = 0; i < num_of_nodes_in_g; i++)
        for (j = 0; j < num_of_nodes_in_g; j++) {
            //printf("Graph[i][j]:%d i=%d j=%d\n", Graph[i][j], i, j);
            //printf("INFINITY = %d\n", INFINITY);
            if (Graph[i][j] == 0) { //init all values as infinity
                cost[i][j] = INFINITY;
                //printf("cost inf=%d\n", cost[i][j]);
            }
            else
                cost[i][j] = Graph[i][j];
        }
    //printf("stam1 start=%d\n",start);
    for (i = 0; i < num_of_nodes_in_g; i++) {
        //printf("stam3 i=%d start=%d\n",i,start);
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
//    for (i = 0; i < num_of_nodes_in_g; i++){
//        for (j = 0; j < num_of_nodes_in_g; j++){
//            printf("%d ",cost[i][j],i,j);
//        }
//        printf("\n");
//    }
//    for (j = 0; j < num_of_nodes_in_g; j++){
//            printf("%d ",distance[j],j);
//        }
    //for (j = 0; j < num_of_nodes_in_g; j++){
     //   printf("%d ",pred[j],j);
    //}
        //printf("start=%d\n",start);
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    //printf("\n distance1 = ");
//    for (j = 0; j < num_of_nodes_in_g; j++){
//        printf("d=%d j=%d ",distance[j],j);
//    }
    while (count < num_of_nodes_in_g - 1) {
        mindistance = INFINITY;
        //printf("Yuval1 nextnode=%d\n",nextnode);
        for (i = 0; i < num_of_nodes_in_g; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
                //printf("Yuval3 nextnode=%d\n",nextnode);
            }
        //printf("Yuval2 nextnode=%d mindistance=%d\n",nextnode,mindistance);
        if(mindistance!=INFINITY) {
            visited[nextnode] = 1;
        }
        for (i = 0; i < num_of_nodes_in_g; i++)
            if (!visited[i]) {
                //printf("mindistance=%d mindistance + cost[nextnode][i]=%d\n",mindistance,mindistance + cost[nextnode][i]);
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        count++;
    }
    //this is distance array:
    //index=dest:     0   1   2   ... n
    //weight:         x   y   z   ... f
//    printf("\n distance = ");
//    for (j = 0; j < num_of_nodes_in_g; j++){
//        printf("d=%d j=%d ",distance[j],j);
//    }
    return distance;//distance is array that the Distance from source to i is distance[i]
}
void printfunc(int** array, int rows, int cols)
{
    int i, j;
    printf("r=%d, c=%d\n",rows,cols);
    for (i=0; i<rows; i++)
    {
        for (j=0; j<cols; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}
int shortsPath_cmd(pnode *head,int src,int dest) {
    int **GeneralMAt;
    printf("in shortest path src=%d dest=%d MAX_id=%d\n",src,dest,MAX_id);
    GeneralMAt=allocfunc(MAX_id,MAX_id);//decleare a matrix
    printfunc(GeneralMAt, MAX_id,MAX_id);
    initMAT(head,GeneralMAt);//put inside values od weight
    printfunc(GeneralMAt, MAX_id,MAX_id);
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
    distance = Dijkstra(head,GeneralMAt, MAX_id, src);
    printf("Dijsktra shortest path:%ld\n",distance[dest]) ;
    return distance[dest];
}


void TSP(pnode *head) {
    int cities, temp; //total number of the cities
    int min_dis = INFINITY;
    int temp_dis = 0;
    scanf(" %d", &cities);

///////////check if malloc isnt null///////
    int *arr = (int *) malloc(cities * sizeof(int)); //init array of the cities
    for (int i = 0; i < cities; ++i) {
        scanf(" %d", &arr[i]);
        printf("in TSP check city %d ",arr[i]);
    }
    printf("\n");
    //int *arr_copy = (int *) malloc(cities * sizeof(int)); //create copy array
    //memcpy(arr_copy, arr, cities);
    for (int j = 1; j <= cities; j++) {
        temp_dis = 0;
        for (int i = 0; i < cities - 1; i++) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        for (int k = 0; k < cities - 1 && temp_dis != INFINITY; k++) {

            int curr_dis = shortsPath_cmd(head, arr[k], arr[k + 1]);
            if (curr_dis == INFINITY)
                temp_dis = INFINITY;
            else
                temp_dis += curr_dis;
        }
        //printf("temp_dis=%d min_dis=%d\n",temp_dis,min_dis);
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