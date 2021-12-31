#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct Graph {
    int nodes;
   // int size;
}graph;

pnode getNode(node **head, int id);//done
void build_graph_cmd(pnode *head);//done
void insert_node_cmd(pnode *head);//done
// void delete_node_cmd(pnode *head); //no need
void deleteNode(node **head, int key);//done

void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);


#endif
