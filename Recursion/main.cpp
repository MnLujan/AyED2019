#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

void impre(int v[],int n);
int suma(int v[], int);
int mayor(int v[], int);
int fibonacci(int);

int main()
{   int v[6]={17,15,-8,30,5,-2};

    cout<<"impre vector: ";impre(v,5);cout<<endl;
    cout<<"Suma de V:"<<suma(v,5)<<endl;
    cout<<"El mayor es:"<<mayor(v,5)<<endl;
    cout<<"Fibonacci de 8: "<<fibonacci(8)<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}



void impre(int v[],int n)
{   if(n==0)cout<<v[n]<<", ";
    else{
        //cout<<"estoy yendo"<<endl;
        //cout<<v[n]<<endl;
        impre(v,n-1);
        //cout<<"estoy retornando"<<endl;
        cout<<v[n]<<", ";
    }
}

int suma(int v[], int n){

    if(n==0){
        return v[n];
    }
    else{
        return v[n]+suma(v,n-1);
    }
}

int mayor(int v[],int n){
    int m = 0;
    if(n==0) return v[n];
    m=mayor(v,n-1);

    if(v[n]>m){
        return v[n];
    }else{
        return m;
    }
    //return v[n]>m ? v[n]:m;
}

int fibonacci(int n) {
    if (n == 1 || n == 2) { return 1; }
    else { return (fibonacci(n - 1) + fibonacci(n - 2)); }
}