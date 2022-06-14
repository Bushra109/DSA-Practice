//https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

class NStack
{
    private:
    int *arr;   //the array in which the stack will be implemented
    int *top;   //the top array which will store the top index of a particular stack(m-1) where m is stack number
    int *next;  //the next array of equal size as arr which will store the next empty space (when data              is not inserted at that index)  or the prevoius element of the stack

    int freeSpace; //it will store the free space available

    int n;      //to store total no of stacks to be implemented
    int s;      //to store the size of array in which stack will be implemented
public:
     
    // Initialize your data structure.
    NStack(int N, int S)
    {   
        s=S;
        n=N;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        for(int i=0;i<s;i++){
            next[i]=i+1;    //initially next empty space will be i+1 index
        }
        next[s-1]=-1;      //the last index does not have a next empty space 

        for(int i=0;i<n;i++){
         top[i]=-1;
        }

        freeSpace=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {    
        //check overflow
        if(freeSpace==-1)
        return false;


        //find the freespace where x will be inserted
        int index=freeSpace;

        //update the freeSpace
        freeSpace=next[index]; //next contains the next free space available after index is occupied

        //insert x
        arr[index]=x;

        //update next
        next[index]=top[m-1];  //here next points to the previous element in stack which is currently denoted by top

        //update top
        top[m-1]=index  ;      //top of corresponding stack is now at index

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {   if(top[m-1]==-1)
           return -1;
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freeSpace;
        freeSpace=index;

        return arr[index];

        
    }
};