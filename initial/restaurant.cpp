#include "main.h"

//Start stack


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
            cout << "Queue is empty." << endl;
            return;
        }
        table* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    void max_sort() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        table* trans=front->next;
        table* sort=front;
        while(trans!=NULL){
            table* repSort=sort;
            while (repSort->age!=trans->age && repSort->name!=trans->name)
            {
                if(repSort->age<trans->age){
                    int temp=repSort->age;
                    string tempName=repSort->name;
                    repSort->age=trans->age;
                    trans->age=temp;
                    repSort->name=trans->name;
                    trans->name=tempName;
                }
                repSort=repSort->next;
            }
            trans=trans->next;   
        }
        delete trans;
        while (sort->next!=NULL)
        {
            sort=sort->next;
        }
        rear = sort; 
        sort=sort->next;
        delete sort;
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





void simulate(string filename, restaurant* r)
{
    bool ismerge=false;
    Queue* Waitline;
    string myText;
    ifstream MyReadFile(filename);
    restaurant* assignment = new restaurant();
    
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
           
        }
        else if(token=="SQ"){
           
        }
        else if(token == "PT"){
            
        }
        
    }
}

