//#ifndef GRAPH_
//#define GRAPH_

typedef struct NODE *pnode;;

typedef struct Edge {
    int weight;
    pnode dest_node;
    struct Edge *next_edge;
} Edge, *pedge;


typedef struct NODE{
    int id;
    pedge first_edge;
    struct NODE *next_node;
} NODE, *pnode;


void createGraph(NODE **head, int node_numbers);
void insertNewNode (NODE **head,int id);
void insertNewEdge (NODE **head, int src,int weight, int dest);
pnode getNode(NODE **head, int id); // retrun a NODE


//void build_graph_cmd(pnode *head);
//void insert_node_cmd(pnode *head); //done

/*void delete_node_cmd(pnode *head);
//all here:
//https://www.log2base2.com/data-structures/linked-list/deleting-a-node-in-linked-list.html
*/

//get node, see here:
//https://www.log2base2.com/data-structures/linked-list/searching-a-node-in-singly-linked-list.html


//void printGraph_cmd(pnode head); //for self debug
//void deleteGraph_cmd(pnode* head);
//void shortsPath_cmd(pnode head);
//void TSP_cmd(pnode head);

//#endif
