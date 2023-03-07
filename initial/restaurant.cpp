#include "main.h"


//Start queue







///////////////////////////////End queue//////////////////////////////////////

string slipt(string& myText){
    string delimiter=" ";
    size_t pos = myText.find(delimiter);
    string token = myText.substr(0, pos);
    myText.erase(0, pos + delimiter.length());
    return token;
}

void insertNoFollowID(table* tb, string name, int age){
    int i=0;
    while(tb->name != "" && i<MAXSIZE){
            tb=tb->next;
            i++;
    }
    if(i<15){
            tb->name=name;
            tb->age=age;
    }
    else{

    }
}

void REG(restaurant* R, string data){
    string data_first = "";
    data_first=slipt(data);
    table* rep=R->recentTable->next;
    if(data_first[0] < '0' || data_first[0] > '9'){
        insertNoFollowID(rep,data_first,stoi(data));
    }
    else{
        int id = stoi(data_first);
        string name= slipt(data);
        int age=stoi(data);
        while(rep->ID!=id){
            rep=rep->next;
        }
        if(rep->name==""){
            rep->name=name;
            rep->age=age;
        }
        else{
            insertNoFollowID(rep->next,data_first,stoi(data));
        }
    }
}





void simulate(string filename, restaurant* r)
{
    string myText;
    ifstream MyReadFile(filename);
    restaurant* assignment = new restaurant();
    
    while (getline (MyReadFile, myText)) {
        string token = slipt(myText);
        if(token=="REG"){
            REG(r,myText);
        }
        else if(token=="REGM"){
            
        }
        else if(token=="CLE"){
            
        }
        else if(token=="PS"){
            
        }
        else if(token=="PQ"){
           
        }
        else if(token=="SQ"){
           
        }
        
    }
}

