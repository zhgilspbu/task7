#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>


using namespace std;
struct queue{


int id;         // NOMER ZAYAVKI
double input;   // VREMYA POSTUPLENIYA V OCHERED'
int loop;       //KRUG OBRABOTKI
double service; //VREMYA OBSLUZHIVANIYA
double wait_time; //VREMYA OZHIDANIYA V OCHEREDI
double left_service; // OSTAVSHEESYA VREMYA OBRABOTKI

queue* next;
queue* prev;
};



void push(queue*& head, double input,double service, int id){
queue* element=new(queue);
element->id=id;
element->input=input;
element->service=service;
element->loop=0;
element->wait_time=0;
element->left_service=service;
element->prev=NULL;
queue* ptr=head;
if (head){
    while (ptr->prev){
        ptr=ptr->prev;
    }
    ptr->prev=element;
    element->next=ptr;
}
else{
    head=element;
    element->next=NULL;
}

}



queue* pop(queue*& head){
if ( head){
queue* ptr=head;
head=head->prev;
return ptr;}
else {
    return NULL;
}
}

void add_to_tail(queue*& head, queue* element){
queue* ptr=head;

if (head){
    while (ptr->prev){
        ptr=ptr->prev;
    }
    ptr->prev=element;
    element->next=ptr;
    element->prev=NULL;
}else{

head=element;
head->prev=NULL;
head->next=NULL;

}
}


void increment(queue* head,double incr){

while (head){
    head->wait_time+=incr;
    head=head->prev;
}
}


int len(queue* head){
int ans=0;
while (head){
    ans++;
    head=head->prev;
}

return ans;
}

int sum_of_wait(queue* head){

}

void print (queue* head){

while (head){
    cout<<head->id<<" ";
    head=head->prev;
}



}







#endif // QUEUE_H_INCLUDED

