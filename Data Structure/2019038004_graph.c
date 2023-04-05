#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"
/****************************Pre-defined functions : TO NOT TOUCH ******************************************/
/*Add a node from the linked list*/
node* add_node(node* n, interval v) {
   node* head = n;
   node* newNode = (node*)malloc(sizeof(node));
   if (newNode == NULL) {
      printf("alloc error");
      exit(-1);
   }

   newNode->item = v;
   newNode->next = NULL;
   // if first node (head == null)
   if (head == NULL) {
      head = newNode;
   }
   // after second node
   else {
      node* tail = n;
      // find tail
      while (tail->next) {
         tail = tail->next;
      }
      tail->next = newNode;
   }

   return head;
}
/*Delete the node with item v from the linked list*/
node* delete_node(node* n, interval v) {
   node* head = n;
   node* cur = n;
   node* prev = n;
   int found = 0;
   while (cur) {
      if (cur->item.leftmost == v.leftmost &&
          cur->item.rightmost == v.rightmost) {
         found = 1;
         break;
      }
      prev = cur;
      cur = cur->next;
   }

   // if v is in adj_list : delete cur node
   if (found) {
      // if first node
      if (cur == prev) {
         head = cur->next;
      } else {
         node* nextNode = cur->next;
         prev->next = nextNode;
      }
      free(cur);
   }

   return head;
}

/*Print an error message*/
void print_error(void) { printf("Error\n"); }
/*************************************************************************************************************/

/*Constrcut the interval graph*/
void construct(Graph* g, char* file) {
//implement your function in here
    FILE* fp = fopen(file, "r");
    char slice[] = " \n,";
    char str[256];
    int count = 0;
    int vertex = fgetc(fp) - 48;
    g->num_vertices = vertex;
    if (vertex > MAX_VERTICES)
    {
        print_error();
        g = NULL;
        return;
    }
    fgets(str, 256, fp);
    if (fp != NULL)
    {
        char* token = NULL;
        while (!feof(fp))
        {
            fgets(str, 256, fp);
            token = strtok(str, slice);
            g->map_interval[count].leftmost = atoi(token);
            token = strtok(NULL, slice);
            g->map_interval[count].rightmost = atoi(token);
            token = strtok(NULL, slice);
            if (token != NULL)
            {
                g = NULL;
                return;
            }
            count += 1;
        }
        if (count < vertex)
        {
            print_error();
            g = NULL;
            return;
        }

    }
    for (int i = 0; i < vertex; i++)
    {
        g->adj_list[i] = NULL;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (!(g->map_interval[i].leftmost > g->map_interval[j].rightmost || g->map_interval[i].rightmost < g->map_interval[j].leftmost))
            {
                interval temp;
                temp.leftmost = g->map_interval[j].leftmost;
                temp.rightmost = g->map_interval[j].rightmost;
                g->adj_list[i] = add_node(g->adj_list[i], temp);
            }
            
        }
    }
    fclose(fp);
}


/*Print map_interval array and adjacency matrix*/
void print_graph(Graph* g) {
//implement your function in here
    for (int i = 0; i < g->num_vertices; i++)
    {
        printf("List %d = [%d, %d]\n", i, g->map_interval[i].leftmost, g->map_interval[i].rightmost);
    }
    for (int i = 0; i < g->num_vertices; i++)
    {
        for (int j = 0; j < g->num_vertices; j++)
        {
            int chk = 0;
            node* search = g->adj_list[j];
            while (search != NULL)
            {
                if (g->map_interval[i].leftmost == search->item.leftmost && g->map_interval[i].rightmost == search->item.rightmost)
                {
                    chk = 1;
                }
                search = search->next;
            }
            printf("%d ", chk);
        }
        printf("\n");
    }
}


/*Check the adjacency between vertex v and u*/
int adjacent(Graph* g, interval v, interval u) {
    //implement your function in here
    int vp = -1;
    int up = -1;
    int chk = 0;
    for (int i = 0; i < g->num_vertices; i++)
    {
        if ((g->map_interval[i].leftmost == v.leftmost) && (g->map_interval[i].rightmost == v.rightmost))
        {
            vp = i;
        }
        if ((g->map_interval[i].leftmost == u.leftmost) && (g->map_interval[i].rightmost == u.rightmost))
        {
            up = i;
        }
    }
    if (vp == -1 || up == -1)
    {
        print_error();
        return 0;
    }
    node* search = g->adj_list[vp];
    while (search != NULL)
    {
        if (search->item.leftmost == u.leftmost && search->item.rightmost == u.rightmost)
        {
            chk = 1;
            break;
        }
        search = search->next;
    }
    return chk;
}


/*Return the degree of vertex v*/
int degree(Graph* g, interval v) {
//implement your function in here
    int vp = -1;
    int deg = 0;
    for (int i = 0; i < g->num_vertices; i++)
    {
        if ((g->map_interval[i].leftmost == v.leftmost) && (g->map_interval[i].rightmost == v.rightmost))
        {
            vp = i;
        }
    }
    if (vp == -1)
    {
        print_error();
        return 0;
    }

    node* search = g->adj_list[vp];
    while (search != NULL)
    {
        deg++;
        search = search->next;
    }
    return deg;
}


/* Add a vertex v to g*/
void add_vertex(Graph* g, interval v) {
//implement your function in here
    if (g->num_vertices == MAX_VERTICES)
    {
        print_error();
        return;
    }
    int vp = -1;
    for (int i = 0; i < g->num_vertices; i++)
    {
        if ((g->map_interval[i].leftmost == v.leftmost) && (g->map_interval[i].rightmost == v.rightmost))
        {
            vp = i;
            break;
        }
    }
    if (vp != -1)
    {
        print_error();
        return;
    }
    g->num_vertices += 1;
    g->adj_list[g->num_vertices - 1] = NULL;
    g->map_interval[g->num_vertices - 1].leftmost = v.leftmost;
    g->map_interval[g->num_vertices - 1].rightmost = v.rightmost;
    for (int i = 0; i < g->num_vertices-1; i++)
    {
        if (!(g->map_interval[i].leftmost > v.rightmost || g->map_interval[i].rightmost < v.leftmost))
        {
            interval temp;
            temp.leftmost = v.leftmost;
            temp.rightmost = v.rightmost;
            g->adj_list[i] = add_node(g->adj_list[i], temp);
        }
    }
    for (int i = 0; i < g->num_vertices - 1; i++)
    {
        if (!(g->map_interval[i].leftmost > v.rightmost || g->map_interval[i].rightmost < v.leftmost))
        {
            interval temp;
            temp.leftmost = g->map_interval[i].leftmost;
            temp.rightmost = g->map_interval[i].rightmost;
            g->adj_list[g->num_vertices-1] = add_node(g->adj_list[g->num_vertices - 1], temp);
        }
    }
}


/*Delete a vertex v from g*/
void delete_vertex(Graph* g, interval v) {
//implement your function in here
    int vp = -1;
    for (int i = 0; i < g->num_vertices; i++)
    {
        if ((g->map_interval[i].leftmost == v.leftmost) && (g->map_interval[i].rightmost == v.rightmost))
        {
            vp = i;
            break;
        }
    }
    if (vp == -1)
    {
        print_error();
        return;
    }
    interval temp = g->map_interval[vp];
    for (int i = 0; i < g->num_vertices; i++)
    {
        g->adj_list[i] = delete_node(g->adj_list[i], temp);
    }
    for (int i = vp; i < g->num_vertices-1; i++)
    {
        g->map_interval[i].leftmost = g->map_interval[i + 1].leftmost;
        g->map_interval[i].rightmost = g->map_interval[i + 1].rightmost;
        g->adj_list[i] = g->adj_list[i + 1];
    }
    g->map_interval[g->num_vertices - 1].leftmost = 0;
    g->map_interval[g->num_vertices - 1].rightmost = 0;
    g->num_vertices -= 1;
}


/*Check connectivity*/
int connectivity(Graph* g) {
//implement your function in here
    Stack* s = (Stack*)malloc(sizeof(Stack));
    stackInit(s);
    int chk[MAX_VERTICES] = { 0 };
    int next = 0;
    int cnt = 0;
    push(s, g->map_interval[next]);
    chk[next] = 1;
    while (!stackIsEmpty(s))
    {
        interval temp = pop(s);
        int rem = -1;
        for (int i = 0; i < g->num_vertices; i++)
        {
            if (temp.leftmost == g->map_interval[i].leftmost && temp.rightmost == g->map_interval[i].rightmost)
            {
                rem = i;
                break;
            }
        }
        node* search = g->adj_list[rem];
        while (search != NULL)
        {
            for (int i = 0; i < g->num_vertices; i++)
            {
                if (search->item.leftmost == g->map_interval[i].leftmost && search->item.rightmost == g->map_interval[i].rightmost)
                {
                    if (chk[i] != 1)
                    {
                        push(s, search->item);
                        chk[i] = 1;
                        break;
                    }
                }
            }
            search = search->next;
        }
    }
    for (int i = 0; i < g->num_vertices; i++)
    {
        if (chk[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

/*Check 2-connectivity*/
int two_connectivity(Graph* g) {
//implement your function in here
    int cnt[MAX_VERTICES] = { 0 };
    int chk = 0;
    interval rem;
    for (int i = 0; i < g->num_vertices; i++)
    {
        cnt[i] = degree(g, g->map_interval[i]);
    }
    for (int i = 0; i < g->num_vertices; i++)
    {
        if (cnt[i] == g->num_vertices - 1)
        {
            chk += 1;
            rem = g->map_interval[i];
        }
    }

    if (chk == 1)
    {
        printf("CUT VERTEX = [%d, %d]\n", rem.leftmost, rem.rightmost);
        return 0;
    }
    return 1;

}

/*Check 2-edge-connectivity*/
int two_edge_connectivity(Graph* g) {
//implement your function in here
    int cnt[MAX_VERTICES] = { 0 };
    int chk = 0;
    interval rem;
    interval rem_2;
    for (int i = 0; i < g->num_vertices; i++)
    {
        cnt[i] = degree(g, g->map_interval[i]);
    }
    for (int i = 0; i < g->num_vertices; i++)
    {
        if (cnt[i] == 1)
        {
            rem = g->map_interval[i];
            rem_2 = g->adj_list[i]->next->item;
            break;
        }
    }

    if (chk == 1)
    {
        printf("CUT EDGE = ([%d,%d], [%d,%d])\n", rem.leftmost, rem.rightmost, rem_2.leftmost, rem_2.rightmost);
        return 0;
    }
    return 1;
}


/*i) Print the shortest path from v to u, and ii) return the length of the path*/
int shortest_path(Graph* g, interval v, interval u) {
//implement your function in here
    Queue* q = (Queue*)malloc(sizeof(Queue));
    queueInit(q);
    int dis[MAX_VERTICES];
    int save[MAX_VERTICES][MAX_VERTICES];
    memset(save, -1, sizeof(save));
    int next = -1;
    for (int i = 0; i < g->num_vertices; i++)
    {
        if (v.leftmost == g->map_interval[i].leftmost && v.rightmost == g->map_interval[i].rightmost)
        {
            next = i;
            break;
        }
    }
    enqueue(q, g->map_interval[next]);
    for (int i = 0; i < g->num_vertices; i++)
    {
        if (i == next)
        {
            dis[i] = 0;
        }
        else
        {
            dis[i] = -1;
        }
    }
    save[next][dis[next]] = next;
    while (!queueIsEmpty(q))
    {
        interval temp = dequeue(q);
        for (int i = 0; i < g->num_vertices; i++)
        {
            if (temp.leftmost == g->map_interval[i].leftmost && temp.rightmost == g->map_interval[i].rightmost)
            {
                next = i;
                break;
            }
        }
        if (temp.leftmost == u.leftmost && temp.rightmost == u.rightmost)
        {
            break;
        }
        int rem = -1;
        for (int i = 0; i < g->num_vertices; i++)
        {
            if (temp.leftmost == g->map_interval[i].leftmost && temp.rightmost == g->map_interval[i].rightmost)
            {
                rem = i;
                break;
            }
        }
        node* search = g->adj_list[rem];
        while (search != NULL)
        {
            for (int i = 0; i < g->num_vertices; i++)
            {
                if (search->item.leftmost == g->map_interval[i].leftmost && search->item.rightmost == g->map_interval[i].rightmost && dis[i] == -1)
                {
                    enqueue(q, search->item);
                    dis[i] = dis[next] + 1;
                    for (int j = 0; j < dis[i]; j++)
                    {
                        save[i][j] = save[next][j];
                    }
                    save[i][dis[i]] = i;
                }
            }
            search = search->next;
        }
    }
    printf("Shortest path from [%d, %d] to [%d, %d] : ", v.leftmost, v.rightmost, u.leftmost, u.rightmost);
    int i = 0;
    while (save[next][i] != -1 && i < MAX_VERTICES)
    {
        printf("[%d, %d] ", g->map_interval[save[next][i]].leftmost, g->map_interval[save[next][i]].rightmost);
        i++;
    }
    printf("\n");
    return dis[next];


}

