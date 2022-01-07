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
        if (action == 'A') {//worke good
            deleteGraph_cmd(&head);//done.after debugging
            head = NULL;
            build_graph_cmd(&head);//done.after debugging
        } else if (action == 'B') { //done.after debugging
            add_new_node(&head);
        }
        else if (action == 'D'){ //remove node ,need to check
          Delete_node(&head);
        }
        else if (action == 'S') { //Shortest path
            //printf("Going");
            int src, dest, ans;
            scanf(" %d", &src);
            scanf(" %d", &dest);
            ans= shortsPath_cmd(&head, src, dest);
            printf("Dijsktra shortest path:%ld", ans);
        }
        else if (action == 'T') { //TSP
            TSP(&head);
        }

        else {
            return 0;
        }
    }
}

//}

//}



