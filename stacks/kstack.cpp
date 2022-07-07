#include<iostream>

using namespace std;
template <class X>
class kstack
{
    X * arr;
    int *top;
    int * next;
    int free;
    int size,total_stack;
public:
    kstack(int size,int total_stack) : size(size),total_stack(total_stack),free(0)
    {
        
        arr= new X[size];
        next=new int[size]; // store next free index and previous top position of respective stacks
        top=new  int[total_stack];  // to store index of top elements of respective stacks


        for(int i=0;i<size-1;i++)
        {
            next[i]=i+1;
        }
        next[size-1]=-1;

        for(int i=0;i<total_stack;i++)
        {
            top[i]=-1; // initially allstack is empty ,so top is -1
        }
        
    }
    bool isfull()
    {
        return (free==-1);
    }
    bool isempty(int stack_no)
    {
        if(stack_no >total_stack)
        {
            cout<<"invalid stack number!!!!\n\n\n";
            exit(0);
        }
        return (top[stack_no]==-1);
    }
    
    void push(X item ,int stack_no)
    {
        if(stack_no> total_stack)
        {
            cout<<"invalid stack number !!!\n\n\n";
            exit(0);
        }
        if(isfull())
        {
            cout<<"overflow !!!!!\n\n\n";
            exit(0);
        }

        int index=free; // index is where the element is stored
        free=next[index];
        next[index]=top[stack_no];
        top[stack_no]=index;
        arr[index]=item;

    }
    X pop(int stack_no)
    {
        if(stack_no> total_stack)
        {
            cout<<"invalid stack number !!!\n\n\n";
            exit(0);
        }
        if(isempty(stack_no))
        {
            cout<<"underflow!!!!!\n\n\n";
            exit(0);
        }
        int index=top[stack_no];
        top[stack_no]=next[index];
        next[index]=free;
        free=index;
        return arr[index];
    }



};

int main()
{
    int k=3,n=10;
    kstack < int > stack(n,k);
    stack.push(15,2);
    stack.push(45,2);
    
    stack.push(17,1);
    stack.push(49,1);
    stack.push(39,1);
    
    stack.push(11,0);
    stack.push(9,0);
    stack.push(7,0);
    cout<<"poped element from stack 2 is :"<<stack.pop(2)<<endl;
    cout<<"poped element from stack 1 is :"<<stack.pop(1)<<endl; 
    cout<<"poped element from stack 1 is :"<<stack.pop(0)<<endl; 


    return 0;
}
