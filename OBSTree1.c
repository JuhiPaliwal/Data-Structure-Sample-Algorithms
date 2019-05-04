
#include <stdio.h>
#include <limits.h>
 

int sum(int freq[], int i, int j);
 

int optCost(int freq[], int i, int j)
{int r;
   
   if (j < i)      
     return 0;
   if (j == i)     
     return freq[i];
 
   
   int fsum = sum(freq, i, j);
 
   
   int min = INT_MAX;
 //printf("\nmin is %d\n",min);
  
   
   for ( r = i; r <= j; ++r)
   {
       int cost = optCost(freq, i, r-1) + optCost(freq, r+1, j);
       if (cost < min)
          min = cost;
   }
 
   
   return min + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    
     return optCost(freq, 0, n-1);
}
 

int sum(int freq[], int i, int j)
{
    int s = 0;int k;
    for (k = i; k <=j; k++)
       s += freq[k];
    return s;
}
 

int main()
{
	int i,j;
	int t;	
    int keys[10];
    int freq[10];
    int n;
    printf("enter the number of nodes");
    scanf("%d",&t);
    printf("Enter the values of the nodes");
    for(i=0;i<t;i++)
    {
    scanf("%d",&keys[i])	;
	}
   
    n=t;
    
    printf("Enter the frequencies of the nodes");
    for(i=0;i<t;i++)
    {
    scanf("%d",&freq[i])	;
	}
    printf("Cost of Optimal BST is %d ", optimalSearchTree(keys, freq, n));
    return 0;
}
