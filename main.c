#include <stdio.h>
#include <malloc.h>
#include "graph.h"

#define try bool __HadError=false; //by using: https://stackoverflow.com/questions/10586003/try-catch-statements-in-c
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) __HadError=true;goto ExitJmp;

#include <stdbool.h>


//node *headNode = NULL;//define the head of the Nodelist
edge **headEdge = NULL;//define the head of the Nodelist
//node *h = &(headNode);

int main() {
    char action;
    pnode head ={0,0,NULL};
    while (scanf(" %c", &action)!= EOF){
    //scanf(" %c", &action);
        build_graph_cmd(head);
        if (action == 'A') {
        //struct GRAPH_NODE_ *headNode = (struct GRAPH_NODE_ *) malloc(1 * sizeof(struct GRAPH_NODE_));
         build_graph_cmd(head);

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
   }
         else return 0;
        }

//}

//}

    }

