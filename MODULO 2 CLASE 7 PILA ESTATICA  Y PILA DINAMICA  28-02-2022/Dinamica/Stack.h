#include <stdlib.h>
#include <windows.h>
#include "Node.h"

using namespace std;

class Stack{
private:
    int Count;
    Node* Top;

public:
    Stack();
    void Push();
    void Pop();
	bool IsEmpty();
    void ShowTop();
	void SohowStack();
	void GoToxy(int, int);

};

Stack::Stack(){
    Count = 0;
    Top = NULL;
}

void Stack::Push(){
	string x;
	cout<<"Ingrese un numero>>> ";
	cin>>x;
    if(!isdigit(x[0])){
        cout<<"Error! Ingrese un numero!..."<<endl;
        system("pause");
    }
    else{
        if(stoi(x)>9||stoi(x)<0){
            cout<<"Si ingresa ese numero la pila se va a ver fea :P"<<endl;
            system("pause");
        }
        else{
            Node* NuevoNodo = new Node(stoi(x));
            NuevoNodo->Next = Top;
            Top = NuevoNodo;
            Count++;
        }
    }
}

void Stack::Pop(){
	if(!IsEmpty()){
		Node* Nodo = Top;
        Top = Top->Next;
        delete Nodo;
		Count--;
	}
	else{
		cout<<"No se puede realizar la operacion..."<<endl;
		system("pause");
	}	
}

bool Stack::IsEmpty()
{
    return Count <= 0;
}

void Stack::ShowTop(){
	if(!IsEmpty()){
		system("cls");
		printf("\t%c%c%c%c%c  \n",201,205,205,205,187);
		printf("Tope--->");
		printf("%c ",186);
		cout<<Top->Value; 
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
	if(!IsEmpty()){
        Node* Aux = Top;
	   	printf("\n\n\t%c%c%c%c%c  \n",201,205,205,205,187);
	    while(Aux!=NULL){
            if(Aux==Top){
                printf("Tope--->");
                printf("%c ",186);
		        cout<<Aux->Value; 
                printf(" %c\n",186);
            }
            else{
                printf("\t%c ",186);
                cout<<Aux->Value; 
                printf(" %c\n",186);
            }
            if(Aux->Next==NULL){
                printf("\t%c%c%c%c%c\n",200,205,205,205,188);	        
            }
            else{
		        printf("\t%c%c%c%c%c\n",204,205,205,205,185);
            }
            Aux = Aux->Next;
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