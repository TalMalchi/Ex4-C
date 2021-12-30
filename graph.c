#include <stdio.h>
#include "graph.h"
#include <malloc.h>




//with using :
//https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html

//void createGraph(NODE **head, int node_numbers){
//    NODE *node_array = (NODE *) malloc(node_numbers * sizeof(NODE));
//    if (node_array == NULL) {
//        return ;
//    }

void insertNewNode (node **head,int id) {
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
        struct GRAPH_NODE_ *lastNode= *head;
        while (lastNode->next != NULL && lastNode->node_num!=id) //until last node's next address will be NULL.(check if the node already exist in the list)
        {
            lastNode = lastNode->next; //precede the node to be the next node
        }

        if (lastNode->node_num!=id)//if we exit from the while because (lastNode->node_num==id) we will not add the new node, if it do not exist ,than :
        {
            lastNode->next= newNode;  //we will add the newNode at the end of the linked list
        }
    }

}



void insertNewEdge (edge **head,int weight, int dest) {
    struct edge_ *newEdge = malloc(sizeof(struct edge_)); //create a new node
    //pnode src_node= getNode(*head, src);
    //src_node->edge->
    newEdge->weight = weight;
    pnode dest_node= getNode(*head, dest);
    newEdge->endpoint = dest_node;
    newEdge->next = NULL;
    if (*head == NULL) { //if head is NULL, it is an empty list
        *head = newEdge;

    } else //else, find the last node and add the newNode
    {
        struct edge_ *lastEdge= *head;
        while (lastEdge->next != NULL) //last Edges's next address will be NULL.
        {
            lastEdge = lastEdge->next; //precede the Edge to be the next Edge
        }

        lastEdge->next = newEdge;  //add the newEdge at the end of the linked list
    }
}

pnode getNode(node **head, int id){ // retrun a NODE
    pnode p= *head;
    while (p){
        if(p->node_num== id){ //search for the node with the given id
            return p;
        }
        else {
            p=p->next;
        }
    }
}
void build_graph_cmd(pnode *head) {
    char action;
    int node_numbers;
    int id_node_src;
    int node_dest;
    int weight;
    while (1) {
        scanf("%c", &action);
        if (action == 'A') {
            scanf("%d", &node_numbers);
            //createGraph( h, node_numbers);
            continue;
        } else if (action == 'n') {
            scanf("%d", &id_node_src);//get first node
            insertNewNode(head, id_node_src);
            int flag = 1;
            while (flag) { //start to moove over all dest weight dest weight etc. until we get more 'n'
                if (scanf("%d", &node_dest) != 0) {
                    insertNewNode(head, node_dest);
                    scanf("%d", &weight);
                    insertNewEdge(head, weight, node_dest);
                } else {
                    flag = !flag;
                }
            }
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
            struct node *current = *head;
            while (current->next != NULL) {
                //if yes, we need to delete the current->next node
                if (current->next->node_num == key) {
                    temp = current- next;
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