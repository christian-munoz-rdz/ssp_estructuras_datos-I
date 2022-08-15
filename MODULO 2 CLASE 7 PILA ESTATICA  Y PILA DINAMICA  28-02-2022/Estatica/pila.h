#include<iostream>
#include<stdlib.h>
#include<windows.h>
#define MAX 10

using namespace std;

class Stack{
private:
    int Data[MAX];
	int Top;

public:
    Stack();
    void Push();
    void Pop();
	bool IsEmpty();
	bool IsFull();
    void ShowTop();
	void SohowStack();
	void GoToxy(int, int);

};

Stack::Stack(){
	Top = -1;
}

void Stack::Push(){
	int x;
	if(!IsFull()){
		cout<<"Ingrese un numero>>> ";
		cin>>x;
		Top ++;
	    Data[Top]=x;
	}	
	else{
		cout<<"La pila esta llena..."<<endl;
		system("pause");
	}
}

void Stack::Pop(){
	if(!IsEmpty()){
		Data[Top] = 0;
		Top--;
	}
	else{
		cout<<"No se puede realizar la operacion..."<<endl;
		system("pause");
	}	
}

bool Stack::IsEmpty(){
	return Top == -1;	
}

bool  Stack::IsFull(){
	return Top == MAX-1;
}

void Stack::ShowTop(){
	if(!IsEmpty()){
		system("cls");
		printf("\t%c%c%c%c%c  \n",201,205,205,205,187);
		printf("Tope--->");
		printf("%c ",186);
		cout<<Data[Top]; 
    	printf(" %c\n",186);
		printf("\t%c%c%c%c%c\n",200,205,205,205,188);
		system("pause");
	}
	else{
		cout<<"No se puede realizar la operacion..."<<endl;
		system("pause");
	}
}

void Stack::SohowStack(){
	int i;
	if(!IsEmpty()){
	   	printf("\n\n\t%c%c%c%c%c  \n",201,205,205,205,187);
	    for(i=Top;i>=0;i--){
            if(i==Top){
                printf("Tope--->");
                printf("%c ",186);
		        cout<<Data[i]; 
                printf(" %c\n",186);
            }
            else{
                printf("\t%c ",186);
                cout<<Data[i]; 
                printf(" %c\n",186);
            }
            if(i==0){
                printf("\t%c%c%c%c%c\n",200,205,205,205,188);	        
            }
            else{
		        printf("\t%c%c%c%c%c\n",204,205,205,205,185);
            }
		}
	}
	else{
		cout<<"La pila esta vacia..."<<endl;
	}
}

void Stack::GoToxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
