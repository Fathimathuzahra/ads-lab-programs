#include<stdio.h>
void main()
{
int n,m,a[20],b[20],c[40],i,j,k,z;
printf("Enter the size of first array : ");
scanf("%d",&n);
printf("Enter the array elements : ");
for(i=0;i<n;i++)
{
        scanf("%d",&a[i]);
}
printf("Enter the size of Second array : ");
scanf("%d",&m);
printf("Enter the array elements  : ");
for(i=0;i<m;i++)
{
        scanf("%d",&b[i]);
}
k=n+m;
for(z=0,i=0,j=0;z<k;z++)
{
        if(i>=n)
        {
                c[z]=b[j];
                j++;
        }
        else if(j>=m)
        {
                c[z]=a[i];
                i++;
        }
        else if(a[i]<b[j] && i<n )
        {
                c[z]=a[i];
                i++;
        }
        else
        {
                c[z]=b[j];
                j++;
        }
}
printf("The sorted array is as given below : ");
for(i=0;i<k;i++)
{
        printf(" %d ",c[i]);
}
printf("\n");
}


  ALGORITHM
Step 1: Start.  
Step 2: Declare variables `n`, `m`, `a[20]`, `b[20]`, `c[40]`, `i`, `j`, `k`, `z`.  
Step 3: Print "Enter the size of first array:".  
Step 4: Read the size of the first array `n`.  
Step 5: Print "Enter the array elements:".  
Step 6: Set `i = 0`. Repeat Step 7 until `i < n`.  
Step 7: Read the element `a[i]`.  
Step 8: Increment `i = i + 1` and go to Step 6.  
Step 9: Print "Enter the size of second array:".  
Step 10: Read the size of the second array `m`.  
Step 11: Print "Enter the array elements:".  
Step 12: Set `i = 0`. Repeat Step 13 until `i < m`. 
Step 13: Read the element `b[i]`. 
Step 14: Increment `i = i + 1` and go to Step 12.  
Step 15: Set `k = n + m` (size of the merged array).  
Step 16: Set `i = 0`, `j = 0`, and `z = 0`. Repeat Steps 17-22 until `z < k`.  
Step 17: If `i >= n`, go to Step 19.  
Step 18: If `j >= m`, go to Step 20.  
Step 19: If `a[i] < b[j]` and `i < n`, set:  
  - `c[z] = a[i]`  
  - Increment `i = i + 1`  
  - Increment `z = z + 1`  
  - Go to Step 16.  
Step 20: Otherwise, set:  
  - `c[z] = b[j]`  
  - Increment `j = j + 1`  
  - Increment `z = z + 1`  
  - Go to Step 16.  
Step 21: Print the merged sorted array `c`.  
Step 22: Stop.  

---
