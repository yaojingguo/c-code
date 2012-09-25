#include <stdio.h>

#define MAX 6
#define INF 998

int allselected(int *selected) {
  int i;
  for (i=0; i< MAX; i++)
    if(selected[i] == 0)
      return 0;
  return 1;
}

void shortpath(int cost[][MAX], int *distance) {
  int selected[MAX] = {0};
  int current = 0, i, k, dc, smalldist, newdist;

  for(i=0; i<MAX; i++)
    distance[i] = INF;

  selected[current]=1;
  distance[0]=0;
  current=0;

  while (!allselected(selected)) {
    smalldist = INF;
    dc = distance[current];
    k = -1;
    for (i=0; i<MAX; i++) {
      if (selected[i] == 0) {                                             
        newdist = dc + cost[current][i];
        if (newdist < distance[i]) {
          distance[i] = newdist;
        }
        if (distance[i] < smalldist) {
          smalldist = distance[i];
          k = i;
        }
      }
    }
    if (k == -1)
      break;
    current = k;
    selected[current] =1;
    printf("current: %d\n", current);
  }
}

int main() {
  int cost[MAX][MAX]= { 
    {INF, INF,  10, INF,  30, 100},
    {INF, INF,   5, INF, INF, INF},
    {INF, INF, INF,  50, INF, INF},
    {INF, INF, INF, INF, INF,  10},
    {INF, INF, INF,  20, INF,  60},
    {INF, INF, INF, INF, INF, INF}
  };

  int distance[MAX];
  shortpath(cost, distance);

  int i;
  for (i=0; i<MAX; i++)
    printf("%d: %d\n", i, distance[i]);
  return 0;
}
