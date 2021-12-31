#include <stdio.h>
#include "graph.h"
#include <malloc.h>


//with using :
//https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html

void insertNewNode(node **head, int id) {
    //void insertNewNode (pnode **head,int id) {
    node *newNode = malloc(sizeof(node)); //create a new node
    //struct NODE *newNode; //create a new node
    newNode->node_num = id;
    newNode->next = NULL;
    newNode->edges = NULL;
    if (*head == NULL) { //if head is NULL, it is an empty list
        *head = newNode;
    } else //else, find the last node and add the newNode
    {
        struct GRAPH_NODE_ *lastNode = *head;
        while (lastNode->next != NULL && lastNode->node_num !=
                                         id) //until last node's next address will be NULL.(check if the node already exist in the list)
        {
            lastNode = lastNode->next; //precede the node to be the next node
        }

        if (lastNode->node_num !=
            id)//if we exit from the while because (lastNode->node_num==id) we will not add the new node, if it do not exist ,than :
        {
            lastNode->next = newNode;  //we will add the newNode at the end of the linked list
        }
    }

}


void insertNewEdge(edge **head,int id, int weight, int dest) {
    edge *newEdge = malloc(sizeof(edge)); //create a new node
    //pnode src_node= getNode(*head, src);
    //src_node->edge->
    newEdge->weight = weight;
    pnode dest_node = getNode(*head, dest);
    newEdge->endpoint = dest_node;
    newEdge->next = NULL;
    node *curr_node;
    curr_node= getNode(head, id);
    if (curr_node->edges == NULL) { //if head is NULL, it is an empty list
        *head = newEdge;

    } else //else, find the last node and add the newNode
    {
        struct edge_ *lastEdge = curr_node->edges;
        while (lastEdge->next != NULL) //last Edges's next address will be NULL.
        {
            lastEdge = lastEdge->next; //precede the Edge to be the next Edge
        }

        lastEdge->next = newEdge;  //add the newEdge at the end of the linked list
    }
}

pnode getNode(node **head, int id) { // retrun a NODE
    pnode p = *head;
    while (p) {
        if (p->node_num == id) { //search for the node with the given id
            return p;
        } else {
            p = p->next;
        }

    }
    return 0; //if the node not in the graph

}

void build_graph_cmd(pnode *head) {
    //deleteGraph_cmd(head);
    int node_numbers;
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


void deleteNode(node **head, int key) {
    struct node *temp = NULL;//temp is used to freeing the memory
    //key found on the head node.
    //move to head node to the next and free the head.
    if ((*head)->node_num == key) {
        temp = *head;    //backup to free the memory
        *head = (*head)->next;
        free(temp);
    } else {
        struct GRAPH_NODE_ *current = *head;
        while (current->next != NULL) {
            //if yes, we need to delete the current->next node
            if (current->next->node_num == key) {
                temp = current->next;
                //node will be disconnected from the linked list.
                current->next = current->next->next;
                free(temp);
                break;
            }
                //Otherwise, move the current node and proceed
            else {
                current = current->next;
            }
        }
    }
}

void deleteGraph_cmd(pnode *head) {
    node temp = **head; //init temp node to the head
    edge *edge_temp;
    while (temp.next != NULL) { // go all over the nodes
        node *curr_node = &temp; //init curr node
        edge_temp = temp.edges; // init temp_edge to point the edges of
        while (edge_temp != NULL) { //go all over the edges in the node
            edge *curr_edge= edge_temp;
            edge_temp= edge_temp->next; // increase the edge by 1
            free(curr_edge);
        }
        temp= temp.next;
        free(curr_node);


        //deleteNode(head,)
    }

}

void add_new_node(pnode *head){
    int id;
    scanf(" %d", &id);
    if(getNode(head, id)==0){ //check if the node exist in the graph
        insertNewNode(*head, id);
    }
    else { // if the node in the graph delete the ou edges
        edge *edgeTemp;
        node *curr_node= getNode(*head, id);
        edgeTemp = curr_node->edges ; // init temp_edge to point the edges of
        while (edgeTemp != NULL) { //go all over the edges in the node
            edge *curr_edge= edgeTemp;
            edgeTemp= edgeTemp->next; // increase the edge by 1
            free(curr_edge);
        }
        int weight;
        int dest;
        while (scanf(" %d", &dest)) { //start to moove over all dest weight dest weight etc. until we get more 'n'
            insertNewNode(head, dest);
            scanf(" %d", &weight);
            insertNewEdge(head, id, weight, dest);
        }

    }


}

