#include <stdio.h>
#include "graph.h"
#include <malloc.h>


NODE **headNode = NULL;//define the head of the Nodelist
Edge **headEdge = NULL;//define the head of the Nodelist
NODE *h=&(headNode);

//with using :
//https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html

//void createGraph(NODE **head, int node_numbers){
//    NODE *node_array = (NODE *) malloc(node_numbers * sizeof(NODE));
//    if (node_array == NULL) {
//        return ;
//    }

void insertNewNode (NODE **head,int id) {
    //void insertNewNode (pnode **head,int id) {
   struct NODE *newNode = malloc(sizeof(struct NODE)); //create a new node
    //struct NODE *newNode; //create a new node
    newNode->id = id;
    newNode->next_node = NULL;
    newNode->first_edge = NULL;
    if (*head == NULL) { //if head is NULL, it is an empty list
        *head = newNode;
    } else //else, find the last node and add the newNode
    {
        struct NODE *lastNode= *head;
        while (lastNode->next_node != NULL) //last node's next address will be NULL.
        {
            lastNode = lastNode->next_node; //precede the node to be the next node
        }

        lastNode->next_node= newNode;  //add the newNode at the end of the linked list
    }

}



void insertNewEdge (NODE **head, int src,int weight, int dest) {
    struct Edge *newEdge = malloc(sizeof(struct Edge)); //create a new node
    pnode src_node= getNode(*head, src);
    //src_node->edge->
    newEdge->weight = weight;
    pnode dest_node= getNode(*head, dest);
    newEdge->dest_node = dest_node;
        newEdge->next_edge = NULL;
        if (*head == NULL) { //if head is NULL, it is an empty list
            *head = newEdge;

    } else //else, find the last node and add the newNode
    {
        struct Edge *lastEdge= *head;
        while (lastEdge->next_edge != NULL) //last Edges's next address will be NULL.
        {
            lastEdge = lastEdge->next_edge; //precede the Edge to be the next Edge
        }

        lastEdge->next_edge = newEdge;  //add the newEdge at the end of the linked list
    }
}

pnode getNode(NODE **head, int id){ // retrun a NODE
    pnode p= *head;
    while (p){
        if(p->id== id){ //search for the node with the given id
            return p;
        }
        else {
            p=p->next_node;
        }
    }
}




  /*  int main()
    {
        struct node *head = NULL;

        addLast(&head,10);
        addLast(&head,20);
        addLast(&head,30);

        printList(head);

        return 0;
    }
*/