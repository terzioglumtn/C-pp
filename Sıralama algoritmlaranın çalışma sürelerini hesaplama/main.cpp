#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;
double bubblesort(int b[],int n);
double selectionsort(int s[],int n);
double quicksort(int q[],int first,int last);
double insertionsort(int ins[],int n);
double mergesort(int numbers[], int temp[], int array_size);
void m_sort(int numbers[], int temp[], int left, int right);
void merge(int numbers[], int temp[], int left, int mid, int right);
int main() 
{
	srand(time(NULL));
	int n=64;
	double bt[7];
	double st[7];
	double qt[7];
	double it[7];
	double mt[7];
	for(int j=0;j<7;j++)
	{
	int *d=new int[n];
	int *b=new int[n];
	int *s=new int[n];
	int *q=new int [n];
	int *ins=new int[n];
	int *m=new int[n];
	int *ms=new int[n-1];
	for(int i=0;i<n;i++)
	{
		d[i]=rand();
	}
	for(int i=0;i<n;i++)
	{
		b[i]=d[i];
		s[i]=d[i];
		q[i]=d[i];
		ins[i]=d[i];
		m[i]=d[i];
	}
	
	qt[j]=quicksort(q,0,n-1);
		
	bt[j]=bubblesort(b,n);
		
	st[j]=selectionsort(s,n);
		
	it[j]=insertionsort(ins,n);
		
	mt[j]=mergesort(m,ms,n);
		
	n=n*5;
	cout<<endl;
}
cout<<endl<<"           MERGE            "<<"QUICK            "<<"SELECTION        "<<"BUBBLE           "<<"INSERTION      "<<endl;
int count=64;
for(int i=0;i<7;i++)
{
	if(i==0)
	{
		cout<<count<<"         "<<fixed<<setprecision(3)<<mt[i]<<"            "<<qt[i]<<"            "<<st[i]<<"            "<<bt[i]<<"            "<<it[i]<<endl;
	}
	if(i==1)
	{
		cout<<count<<"        "<<fixed<<setprecision(3)<<mt[i]<<"            "<<qt[i]<<"            "<<st[i]<<"            "<<bt[i]<<"            "<<it[i]<<endl;
	}
	if(i==2 || i==3)
	{
		cout<<count<<"       "<<fixed<<setprecision(3)<<mt[i]<<"            "<<qt[i]<<"            "<<st[i]<<"            "<<bt[i]<<"            "<<it[i]<<endl;
	}
	if(i==4)
	{
		cout<<count<<"      "<<fixed<<setprecision(3)<<mt[i]<<"            "<<qt[i]<<"            "<<st[i]<<"            "<<bt[i]<<"            "<<it[i]<<endl;
	}
	if(i==5)
	{
		cout<<count<<"     "<<fixed<<setprecision(3)<<mt[i]<<"            "<<qt[i]<<"            "<<st[i]<<"           "<<bt[i]<<"           "<<it[i]<<endl;
	}
	if(i==6)
	{
		cout<<count<<"    "<<fixed<<setprecision(3)<<mt[i]<<"            "<<qt[i]<<"            "<<st[i]<<"         "<<bt[i]<<"          "<<it[i]<<endl;
	}
	count=count*5;
}
return 0;
}

double quicksort(int q[],int first,int last)
{
    int pivot,j,temp,i;
	clock_t quicks,quicke;                                
		quicks=clock();
     if(first<last)
	 {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
		 {
             while(q[i]<=q[pivot]&&i<last)
                 i++;
             while(q[j]>q[pivot])
                 j--;
             if(i<j)
			 {
                 temp=q[i];
                  q[i]=q[j];
                  q[j]=temp;
             }
         }

         temp=q[pivot];
         q[pivot]=q[j];
         q[j]=temp;
         quicksort(q,first,j-1);
         quicksort(q,j+1,last);

    }
    quicke=clock();
    double quick=(double) (quicke-quicks)/CLOCKS_PER_SEC;
    return quick;
}

double bubblesort(int b[],int n)
{
		int i,k,swap;
		clock_t bubbles,bubblee;                                 
		bubbles=clock();
		for(i=0;i<n;i++)
		{
		for(k=i+1;k<n;k++)
		{
			if(b[i]>b[k])
			{
				swap=b[i];
				b[i]=b[k];
				b[k]=swap;
			}
		}
	}
    bubblee=clock();
    double bubble=(double) (bubblee-bubbles)/CLOCKS_PER_SEC;      
	return bubble;
}

double selectionsort(int s[],int n)
{
	int i,k,swap;
	clock_t selections,selectione;                                
	selections=clock();
	for(i=0;i<n-1;i++)
	{
	int position=i;
	for(k=i+1;k<n;k++)
	{
	if(s[position]>s[k])
		position=k;
		}
	if(position!=i)
	{
		swap=s[i];
		s[i]=s[position];
		s[position]=swap;
		}
	}
	selectione=clock();
    double selection=(double) (selectione-selections)/CLOCKS_PER_SEC;
    return selection;
}


double insertionsort(int ins[],int n)
{
	int i,j,swap;
	clock_t insertions,insertione;                                
	insertions=clock();
	for(i=1; i<n; i++)
	{
        swap = ins[i];
        j = i;
        while(j > 0 && swap < ins[j-1])
		{
            ins[j] = ins[j-1];
            j--;
        }
        ins[j] = swap;
    }
    insertione=clock();
    double insertion=(double) (insertione-insertions)/CLOCKS_PER_SEC;
    return insertion;
}

double mergesort(int numbers[], int temp[], int array_size)
{
		clock_t merges,mergee;                                
		merges=clock();
        m_sort(numbers, temp, 0, array_size - 1);
		mergee=clock();
    	double merge=(double) (mergee-merges)/CLOCKS_PER_SEC;
    	return merge;
}

void m_sort(int numbers[], int temp[], int left, int right)
{
        int mid;
		if (right > left)
		{
			mid = (right + left) / 2;
			m_sort(numbers, temp, left, mid);
			m_sort(numbers, temp, mid+1, right);
			merge(numbers, temp, left, mid+1, right);
		}
}

void merge(int numbers[], int temp[], int left, int mid, int right)
{
		int i, left_end, num_elements, tmp_pos;
		left_end = mid - 1;
		tmp_pos = left;
		num_elements = right - left + 1;	
		while ((left <= left_end) && (mid <= right))
			{
               	if (numbers[left] <= numbers[mid])
               	{
                       temp[tmp_pos] = numbers[left];
                       tmp_pos = tmp_pos + 1;
                       left = left +1;
               	}
               	else
               	{
                       temp[tmp_pos] = numbers[mid];
                       tmp_pos = tmp_pos + 1;
                       mid = mid + 1;
               	}
       		}

 	    while (left <= left_end)
            {
                       temp[tmp_pos] = numbers[left];
                       left = left + 1;
                       tmp_pos = tmp_pos + 1;
            }
        while (mid <= right)
            {
                       temp[tmp_pos] = numbers[mid];
                       mid = mid + 1;
                       tmp_pos = tmp_pos + 1;
            }
        for (i = 0; i <= num_elements; i++)
            {
                       numbers[right] = temp[right];
                       right = right - 1;
            }
}












