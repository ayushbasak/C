#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  time_t t;//for random generation
  srand((unsigned) time(&t));
  //Outer Loop for 100 iterations
  for(int iter2=0;iter2<100;iter2++){

    int c1 =0,c2=0,c3=0;
    //Inner Loop to check best Case
    for(int iter =1;iter<=1000;iter++){

      int A1 = 1,B1=500;
      int A2 = 1,B2=1000;
      int A3 = 250,B3=750;

      int count1=0;
      int count2=0;
      int count3=0;

      for(int i =1;i<=1000;i++){
        int j = rand()%1000; //generate random between 1 and 1000
        
       // Case 1
        if(j < 500){
          count1+=(abs(A1-j));
          A1=j;
          }
        else if(j>50 && j<=1000){
          count1+=(abs(B1-j));
          B1=j;}


       //Case 2
        int k = abs(A2-j),l = abs(B2-j);

        if(k<l){
          A2 = j;
          count2+=k;}
        else if(l<k){
          B2=j;
          count2+=l;}
        else if(l==k){
          if(A2<B2){
            count2+=k;
            A2=j;}
          else if(B2<A2){
            count2+=l;
            B2=j;}}
            

       //Case 3
        if(j < 500){
          count3+=(abs(A3-j));
          A3=j;}
        else if(j>500 && j<=1000){
          count3+=(abs(B3-j));
          B3=j;}


      }
        if(count1<count2 &&count1<count3) 
        ++c1;
        else if(count2<count3 &&count2<count1)
        ++c2;
        else if(count3<count2 &&count3<count1)
        ++c3;

    }
    int cases =0;
    if(c1>c2 && c1>c3)
    cases = 1;
    else if(c2>c1 && c2>c3)
    cases =2;
    else if(c3>c1 && c3>c2)
    cases = 3;

    printf("\nThe best iteration case is %d",cases);

  }
}
