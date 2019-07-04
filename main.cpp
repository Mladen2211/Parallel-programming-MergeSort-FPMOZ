#include<bits/stdc++.h>
#include <thread>

// Broj elemenata za sortirat 
#define MAX 2000000

using namespace std;

//t1 = clock();
int Merge(int A[],int p, int q,int r)     
{

    int n1,n2,i,j,k; 
       
    n1=q-p+1;
    n2=r-q;             
    int *L,*R;
    L = new int [n1];
    R = new int [n2];
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
    //Usporeðivanje strana ispajanje
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
int callThread(int A[]){
	
	int n = MAX;
	
	int a = n/2;
	
	thread th1,th2;
	//t1=clock();
	th1 = thread(MergeSort,A, a+1, n-1);
	
    th2 = thread(MergeSort,A,0, a);
    
    th1.join();
    th2.join();
    Merge(A,0, a, n);
    //t2=clock();
}

int main()
{	int *A, i;
	A = new int[MAX];
	clock_t t1, t2;
    int n = MAX;

	
    for (int i = 0; i < n; i++) 
		A[i] = rand();

	t1 = clock();
    callThread(A);
    //auto end = chrono::steady_clock::now();
    cout<<"The Sorted List is\n";
    t2 = clock();
    for(i=0;i<n;i++)
    {
        //cout<<A[i]<<" ";
    }
    cout << "Time taken: " << (t2 - t1) / 
			(double)CLOCKS_PER_SEC << endl;
	return 0;
}
