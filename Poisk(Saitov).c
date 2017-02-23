#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* f(int *a,int n, int *m, int k){
      int *p=NULL,x=2,i,j;
      p=(int*) malloc (x*sizeof(int));
         for (i=0;i<*m;i++){
    for(j=0;j<n;j++)
        if (*(a+i*n+j)== k){
            p[x-2]=i+1;
            p[x-1]=j+1;
            x=x+2;
            p=(int*) realloc (p,(x+2)*sizeof(int));
        }
  }
  *m=(x-2)/2;
  return p;
  }


int* arr (int m, int n){
    int *a;
  int i, j;
   srand(time(NULL));
  a = (int*) malloc(n*m*sizeof(int));
  for(i=0; i<m; i++)
   {
    for(j=0; j<n; j++)
     {
 *(a+i*n+j)=rand()%10;;
     }
   }
  for(i=0; i<m; i++)
  {
    for(j=0; j<n; j++)
      {
       printf("%5d ", *(a+i*n+j));
      }
    printf("\n");
  }
return a;
}

int main(void){
int *a,*p,i, j, m, n, k,c;
printf("1.Odnomerni\n2.Dvumerni\n");
scanf("%d", &c);
switch (c){
        case 2:  printf("Vvedite kol-vo strok: ");
            scanf("%d", &m);
            printf("\nVvedite kol-vo stolbcov: ");
            scanf("%d", &n);
            break;

        case 1:m=1;
            printf("Vvedite kol-vo elementov: ");
            scanf("%d", &n);
            break;
        default:
            printf( "Error.\n" );
            exit(1);
}
a=arr(m,n);
printf("Poisk elementa: ");
scanf("%d",&k);
p=f(a,n,&m,k);
printf("\n Koordinati elementa %d: \n", k);
  for(i=0; i<m; i++)
  {
    for(j=0; j<2; j++)
      {
       printf("%5d ", *(p+i*2+j));
      }
    printf("\n");
  }
  return 0;
}


