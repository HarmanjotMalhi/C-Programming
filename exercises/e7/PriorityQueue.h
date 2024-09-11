
#include <iostream>
#include <string>
#include <array>
template <typename T, int capacity>

class pqueue {

struct item {
T content;
long priority;
};

private:

struct item pq[capacity];
int last;

public:

pqueue()  {
last = -1;
}

void enqueue(const T in,long p){

std::cout<<"hello world"<<std::endl;

item insert;

insert.content = in;

insert.priority = p;

std::cout<<"hello world"<<std::endl;

int i = 0;

if(last != -1){

while(pq[i].priority <= p){
i++;
if(i > last) break;
}

int j = 0;
for(j = last; j >= i; j--){
pq[j+1] = pq[j];
}
 
pq[j+1] = insert;
}

else{
pq[i] = insert;
}

last++;
}

void dequeue(){

last--;
for(int i = 0; i <= last; i++){
pq[i] = pq[i+1];
}
}

bool isEmpty(){

if(pq.empty()) return true;
else return false;
}

T peek(){

return pq[0].content;
}

int count(){
return last;
}

void printq(){ 
 
for(int i = 0; i <= last; i++){
std::cout<<pq[i].content<<std::endl;
}
}

int getLast(){

return last;
}
};
