#include "main.h"

//Start stack
class Stack{
public:
    table* top;
    Stack* next;
public:
    Stack() {
        top = NULL;
    }
    void pushForMerge(table* value) {
        table* newNode = new table(value->ID,value->name,value->age,value->next);
        newNode->next = top;
        top = newNode;
    }
    void push(table* value) {
        table* newNode = new table(value->ID,value->name,value->age,0);
        newNode->next = top;
        top = newNode;
    }
};

///////////////////////////////End stack////////////////////////////////////

//Start queue
class Queue {
public:
    table* front;
    table* rear;
    int size;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int ID, string name, int age) {
        table* newNode = new table(ID, name, age, 0);
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        table* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    void max_sort(int num) {
        if (isEmpty()) {
            cout<<"Empty"<<endl;
            return;
        }
        table* sort = front;
        if(num>0 && num<=size){
            while (sort->next!=NULL && num>0)
            {
                table* trans=sort->next;
                while (trans!=NULL)
                {
                    if(trans->age>sort->age){
                        int tempAge=sort->age;
                        string tempName=sort->name;
                        sort->age=trans->age;
                        sort->name=trans->name;
                        trans->age=tempAge;
                        trans->name=tempName;
                    }
                    trans=trans->next;
                }
                sort=sort->next;
                num--;
            }
            while (sort->next!=NULL)
            {
                sort=sort->next;
            }
            rear=sort;
            return;
            
        }
        while (sort->next!=NULL)
        {
            table* trans=sort->next;
            while (trans!=NULL)
            {
                if(trans->age>sort->age){
                    int tempAge=sort->age;
                    string tempName=sort->name;
                    sort->age=trans->age;
                    sort->name=trans->name;
                    trans->age=tempAge;
                    trans->name=tempName;
                }
                trans=trans->next;
            }
            sort=sort->next;
        }
        rear=sort;
    }
    void display(int num) {
        if (isEmpty()) {
            cout << "Empty" << endl;
            return;
        }
        if(num==-1){
            table* curr = front;
            while (curr != NULL) {
                cout << curr->name << endl;
                curr = curr->next;
            }
            return;
        }
        if(num <= size && num>0){
            table* curr = front;
            while (num>0) {
                cout << curr->name << endl;
                curr = curr->next;
                num--;
            }
            return;
        }
        if(num>size&&num<MAXSIZE){
            table* curr = front;
            while (curr != NULL) {
                cout << curr->name << endl;
                curr = curr->next;
            }
            return;
        }
        
    }
};

///////////////////////////////End queue//////////////////////////////////////

string slipt(string& myText){
    string delimiter=" ";
    size_t pos = myText.find(delimiter);
    string token = myText.substr(0, pos);
    myText.erase(0, pos + delimiter.length());
    return token;
}

void insertNoFollowID(table* tb, string name, int age, Queue* waitline){
    if(age<16) return;
    int i=0;
    tb=tb->next;
    while(tb->name != "" && i<MAXSIZE){
            tb=tb->next;
            i++;
    }
    if(i<15){
            tb->name=name;
            tb->age=age;
    }
    else{
        waitline->enqueue(0,name,age);
    }
}

void REG(restaurant* R, string data,Queue* waitline){
    string data_first = "";
    data_first=slipt(data);
    table* rep=R->recentTable;
    if(data_first[0] < '0' || data_first[0] > '9'){
        string name= data_first;
        int age=stoi(data);
        if(age<16) return;
        insertNoFollowID(rep,name,age,waitline);
    }
    else{
        int id = stoi(data_first);
        string name= slipt(data);
        int age=stoi(data);
        if(age<16) return;
        while(rep->ID!=id){
            rep=rep->next;
        }
        if(rep->name==""){
            rep->name=name;
            rep->age=age;
        }
        else{
            insertNoFollowID(rep,data_first,stoi(data),waitline);
        }
    }
}
void REGM(){

}

void PQ(Queue* waitline, int num){
    waitline->display(num);
}

void SQ(Queue* waitline, int num){
    waitline->max_sort(num);
}

void simulate(string filename, restaurant* r)
{
    bool ismerge=false;
    Queue* Waitline;
    string myText;
    ifstream MyReadFile(filename);
    restaurant* assignment = new restaurant();

    Stack* clientComing;

    table* closestTick; // đánh dấu bàn có hoạt động gần nhất

    Stack* checkTable = new Stack();
    table* temp=r->recentTable->next;
    for (int i = 1; i <= MAXSIZE; i++)
    {
        checkTable->pushForMerge(temp);
        temp = temp->next;
    }

    while (getline (MyReadFile, myText)) {
        string token = slipt(myText);
        if(token=="REG"){
            REG(r,myText,Waitline);
        }
        else if(token=="REGM" && ismerge==false){
            
        }
        else if(token=="CLE"){
            
        }
        else if(token=="PS"){
            
        }
        else if(token=="PQ"){
            if(myText=="PQ"){
                PQ(Waitline,-1);
            }
            else {
                int NUM=stoi(myText);
                PQ(Waitline,NUM);
            }
        }
        else if(token=="SQ"){
           SQ(Waitline,stoi(myText));
        }
        else if(token == "PT"){
            
        }
        
    }
}

