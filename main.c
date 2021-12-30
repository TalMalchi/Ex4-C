#include <stdio.h>
#include <malloc.h>
#include "graph.h"

#define try bool __HadError=false; //by using: https://stackoverflow.com/questions/10586003/try-catch-statements-in-c
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) __HadError=true;goto ExitJmp;

#include <stdbool.h>


int main() {


    node *headNode = NULL;//define the head of the Nodelist
    edge **headEdge = NULL;//define the head of the Nodelist
    node *h = &(headNode);

    void build_graph_cmd(pnode *headNode);

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
    // else
    return 0;
    // }

//}

//}



}