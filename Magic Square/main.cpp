#include <iostream>

using namespace std;

void MagicSquareType(int **square,int size);
void PrintMagicSquare(int **square,int size);
void OddMagicSquare(int **square,int size);
void DoublyEvenMagicSquare(int **square,int size);
void SinglyEvenMagicSquare(int **square,int size);

int main()
{ 
  int size,i,k;
  printf("Enter size of square: ");
  scanf("%d", &size);
  cout << endl << endl;
  
  int **square;
  square = new int *[size];
  for(int i=0;i<size;i++)
    square[i]=new int[size];
    
  for(int i=0;i<size;i++)
  {
  	for(int k=0;k<size;k++)
  	{
  		square[i][k]=0;
	}
  }

  if (size<3)
  {
    printf("\nError: Size must be greater than 2\n\n");
    return -1;
  }
  
  MagicSquareType(square,size);  
  PrintMagicSquare(square,size);
  return 0;
}

void MagicSquareType(int **a,int size)
{
  if (size%2==1)                           //n is Odd
    OddMagicSquare(a,size);
  else                                     //n is even
    if (size%4==0)                         //doubly even order
      DoublyEvenMagicSquare(a,size);
    else                                   //singly even order
      SinglyEvenMagicSquare(a,size);
}

void OddMagicSquare(int **a,int size)
{
  
  int nsqr=size * size;
  int i=0,j=size/2;                        // start position

  for (int k=1;k<=nsqr;++k) 
  {
    a[i][j]=k;

    i=i-1;
    j=j+1;

    if (k%size==0) 
    { 
      i=i+2; 
      --j; 
    }
    else 
    {
      if (j==size) 
        j=j-size;
      else if (i<0) 
        i=i+size;
    }
  }
}

void DoublyEvenMagicSquare(int **a,int size)
{
  int I[size][size];
  int J[size][size];
  
  int i,j;

  int index=1;
  for (i=0;i<size;i++)
    for (j=0;j<size;j++)
    {
      I[i][j]=((i+1)%4)/2;
      J[j][i]=((i+1)%4)/2;
      a[i][j]=index;
      index++;
    }

  for (i=0;i<size;i++)
    for (j=0;j<size;j++)
    {
      if (I[i][j]==J[i][j])
        a[i][j]=size*size+1-a[i][j];
    }
}

void SinglyEvenMagicSquare(int **a,int size)
{
  int p=size/2;
  
  int **M;
  M=new int *[p];
  for(int i=0;i<p;i++)
    M[i]=new int[p];

  for(int i=0;i<p;i++)
  {
  	for(int k=0;k<p;k++)
  	{
  		M[i][k]=0;
	}
  }
  
  MagicSquareType(M,p);
  
  int i,j,k;

  for (i=0;i<p;i++)
    for (j=0;j<p;j++)
    {
      a[i][j]=M[i][j];
      a[i+p][j]=M[i][j]+3*p*p;
      a[i][j+p]=M[i][j]+2*p*p;
      a[i+p][j+p]=M[i][j]+p*p;
    }

  if (size==2)
    return;  
  
  int *I=new int[p];

  for (i=0;i<p;i++)
    I[i]=i+1;

  k=(size-2)/4;
  
  int *J=new int[((size-6)/4)*2+1];
  int b=0;
  
  for (i=1;i<=k;i++)
  {
  	J[b]=i;
	b++; 
  }
    
  for (i=size-k+2;i<=size;i++)
  {
  	J[b]=i;
	b++; 
  }
 
  int temp;
  for (i=1;i<=p;i++)
    for (j=1;j<=b;j++)
    {
      temp=a[i-1][J[j-1]-1];
      a[i-1][J[j-1]-1]=a[i+p-1][J[j-1]-1];
      a[i+p-1][J[j-1]-1]=temp;
    }
    
  i=k; 
  j=0;
  temp=a[i][j]; 
  a[i][j]=a[i+p][j]; 
  a[i+p][j]=temp;

  j=i;
  temp=a[i+p][j]; 
  a[i+p][j]=a[i][j]; 
  a[i][j]=temp;
}

void PrintMagicSquare(int **a,int size)
{
  int SumRows=0,SumColumns=0,SumRightDiagonal=0,SumLeftDiagonal=0;
  for (int j=0;j<size;j++)
      SumRows=SumRows+a[0][j];
  
  for (int i=0; i<size; i++)
      SumColumns=SumColumns+a[i][0];
  
  for (int j=0;j<size;j++)
      SumRightDiagonal=SumRightDiagonal+a[j][j];
  
  for (int j=0,i=size-1;j<size,i>=0;j++,i--)
      SumLeftDiagonal=SumLeftDiagonal+a[j][i];

  for (int i=0;i<size;i++) 
  {
  	printf("\t");
    for (int j=0;j<size;j++)
      printf(" %4d",a[i][j]);
	
	printf("\n");
  }
  printf("\n\n\n");
  printf("Sum of each ROW       =  %d\n",SumRows);
  printf("Sum of each COLUMN    =  %d\n",SumColumns);
  printf("Sum of RIGHT DIAGONAL =  %d\n",SumRightDiagonal);
  printf("Sum of LEFT DIAGONAL  =  %d",SumLeftDiagonal);
}
