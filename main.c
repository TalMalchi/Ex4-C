#include <stdio.h>
#include <malloc.h>
#include "graph.h"

#define try bool __HadError=false; //by using: https://stackoverflow.com/questions/10586003/try-catch-statements-in-c
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) __HadError=true;goto ExitJmp;

#include <stdbool.h>


int main() {

    char action;
    int node_numbers;
    int id_node_src;
    int node_dest;
    int weight;
    NODE **headNode = NULL;//define the head of the Nodelist
    Edge **headEdge = NULL;//define the head of the Nodelist
    NODE *h = &(headNode);

    while (1) {
        scanf("%c/n", &action);
        if (action == 'A') {
            scanf("%d/n", &node_numbers);
            //createGraph( h, node_numbers);
            continue;
        }
        else if (action == 'n') {
            scanf("%d/n", &id_node_src);//get first node
            insertNewNode(h, id_node_src);
            int flag = 1;
            while (flag) { //start to moove over all dest weight dest weight etc. until we get more 'n'
                if (scanf("%d/n", &node_dest) != 0) {
                    insertNewNode(h, node_dest);
                    scanf("%d/n", &weight);
                    insertNewEdge(h, id_node_src, weight, node_dest);
                } else {
                    flag= !flag;
                }
            }
        }
//       else if (action == 'B'){ //add new node
//
//    }
//        else if (action == 'D'){ //remove node
//
//        }
//        else if (action == 'S'){ //Shortest path
//
//        }
//        else if (action == 'T'){ //TSP
//
//        }
        else
            return 0;
        }

}

//}



