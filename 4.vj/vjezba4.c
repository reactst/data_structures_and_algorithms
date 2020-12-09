#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#include  "sortiranjamartinic.h"
#include "sortiranjamartinic.c"

void main() {
    srand(time(NULL));
    int n1=1000;
    int n2=1000;
        for (int i=0;i<10;i++){
          int* niz1=generiraj(n1);
          shuffle (niz1,n1);
          int* niz2=generiraj(n2);
          double vrijeme1=measure(quicksort,niz1,n1);
          double vrijeme2=measure(quicksort,niz2,n2);
          printf("%d.Vrijeme sortiranja ne sortiranog niza s odabirom pivota = %f sec \n",i,vrijeme1);
          printf("%d.Vrijeme sortiranja sortiranog niza s odabirom pivota = %f sec \n",i,vrijeme2);
          n1+=1000;
          n2+=1000;
          free(niz1);
          free(niz2);
        }
        
  //     // choose_pivot=true;

        

  //      // choose_pivot=false;

  //       double vrijeme3=measure(quicksort,niz2,n2);
  //       double vrijeme4=measure(quicksort,niz2,n2);
  //       printf("Vrijeme sortiranja ne sortiranog niza bez pivota je = %f sec  \n",vrijeme3);
  //       printf("Vrijeme sortiranja sortiranog niza bez pivota je = %f sec \n",vrijeme4);

        
    
  //  int test,test1;
  //  for(int i=n_min;i<200;i+=5){
  //    int* niz3=generiraj(n1);
  //    int* niz4=duplicate(niz3,n1);

  //   test=measure(quicksort,niz3,i);
  //   free(niz3);
  //   test1=measure(insertionsort,niz4,i);
  //   free(niz4);
    
  //   if(test>test1){
  //       n_min=i;
  //       printf("%d",i);
  //       break;
  //   }
   
  //  }    
   // }
}