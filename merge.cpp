#include<bits/stdc++.h>
#include <thread>

// Broj elemenata za sortirat 
#define MAX 200000

using namespace std;
int Merge(int A[],int p, int q,int r)     
{

    int n1,n2,i,j,k; 
       
    n1=q-p+1;
    n2=r-q;             
    int L[n1],R[n2];
    //inicijalizacija lijeve strane niza L[]
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }
    //inicijalizacija desne strane R[]
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;
    //Uspoređivanje strana ispajanje
    //u jedan sortirani niz 
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
        }
    }
    while(i<n1)             
    {
        A[k++]=L[i++];
    }
    
    while(j<n2)
    {
        A[k++]=R[j++];
    }
}

int MergeSort(int A[],int p,int r)    
{
    int q;                                
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}


int main()
{
    int n = MAX;
    
    int A[n],i;
    for (int i = 0; i < n; i++) 
		A[i] = rand() % 100;
    
	
    clock_t t1, t2; 
	t1 = clock();
    MergeSort(A,0,n-1);
    cout<<"The Sorted List is\n";
    t2 = clock();
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    
    
    cout << "Time taken: " << (t2 - t1) / 
			(double)CLOCKS_PER_SEC << endl;
	
	return 0;
}
