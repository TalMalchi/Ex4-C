#include <stdio.h>
#include <malloc.h>
#include "graph.h"

#define try bool __HadError=false; //by using: https://stackoverflow.com/questions/10586003/try-catch-statements-in-c
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) __HadError=true;goto ExitJmp;


//pnode **headNode = NULL;//define the head of the Nodelist
edge **headEdge = NULL;//define the head of the Nodelist
//node *h = &(headNode);

int main() {
    char action;
    pnode head = NULL;
    while (scanf(" %c", &action) != EOF) {
        //scanf(" %c", &action);
        //build_graph_cmd(head);
        if (action == 'A') {
            build_graph_cmd(&head);
        } else if (action == 'B') { //add new node
            add_new_node(&head);
        }
//        else if (action == 'D'){ //remove node
//
//        }
        else if (action == 'S') { //Shortest path
            int src, dest;
            scanf(" %d", &src);
            scanf(" %d", &dest);
            shortsPath_cmd(&head, src, dest);
        }
//        else if (action == 'T'){ //TSP
//

//        else {
//            return 0;
//        }
    }
}

//}

//}



