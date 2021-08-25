#include<iostream>
using namespace std;

int main()
{
    int n, v, i, j, adjMat[10][10], ne = 0, no = 0, ni, count =0;
    printf ("\nInput the number of nodes in Graph: ");
    scanf ("%d", &n);
    printf ("\nInput the adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {   for (j = 0; j <n; j++)
        { scanf ("%d", &adjMat[i][j]);
          if (adjMat[i][j] == 1)
            count++;
        }
    }
    for(i = 0; i < n; i++){ ni = 0;
        for(j = 0; j<n; j++){ if (adjMat[i][j] == 1) ni++;}
        if ((ni % 2 == 0) && (ni != 0)) ne++;
        else no++;}
    
    printf ("\nNumber of vertices --> %d", n);
    printf ("\nNumber of even vertices --> %d", ne);    
    printf ("\nNumber of odd vertices -->  %d", no);
    printf ("\nNumber of edges --> %d", count / 2);
}