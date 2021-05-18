#include <iostream>
#include <cmath>
#include "queue.h"
#include <cstdlib>

using namespace std;

int main()
{

    int NUMBER_OF_REQUESTS=1000;
    int ACCOUNT=1;
    unsigned int SEED=188;
    srand(SEED);

    double begin_time, end_time , begin_service, end_service;
    cin>>begin_time>>end_time>>begin_service>>end_service;

    queue *head=NULL;

    int request_wait=0;
    int work_time=0;
    int out=0;
    int input=0; // KOLICHESTVO VOSHEDSHICH ZAYAVOK
    queue* cur_service=NULL;
    double cur_time=0; //TEKUSHEE VREMYA
    double time=-1;//VREMYA POSTUPLENIYA SLEDUYUSHEI ZAYAVKI
    double time_service;

    while (out<NUMBER_OF_REQUESTS){
    if (time<0){

         time = (end_time-begin_time)*rand()/RAND_MAX+begin_time+end_time*input;
        time_service = (end_service-begin_service)*rand()/RAND_MAX+begin_service;
        input++;
        //cout<<len(head)<<" ";
    }
    if (cur_service){
        //cout<<cur_service->input<<"\n";
        if (cur_service->input+cur_service->left_service+cur_service->service*(cur_service->loop)+cur_service->wait_time>time /*&& input<NUMBER_OF_REQUESTS*/){
        increment(head,time-cur_time);

        push(head,time,time_service,input);;
        cur_service->left_service-=(time-cur_time);
        work_time+=time-cur_time;
        cur_time=time;
        time=-1;
        }

    else{
        work_time+=cur_service->left_service;
        increment(head,cur_service->left_service);
        cur_time += cur_service->left_service;
        cur_service->loop++;
        cur_service->left_service=cur_service->service;
        if (cur_service->loop==4){
            out++;
            request_wait+=cur_service->wait_timep;
            delete(cur_service);
            if (out%100==0 && out!=NUMBER_OF_REQUESTS){
                cout<<input<<" "<<len(head);
                cout<<"\n";
            }

        }else{
        add_to_tail(head,cur_service);

        }

        cur_service=pop(head);

    }}
    else{
        if (head){

            cur_service=pop(head);

        }else{
        //if (input<NUMBER_OF_REQUESTS){
        push(head,time,time_service,input);
        cur_time=time;

        time=-1;

        //}
        /*else{
            break;
        }*/

        }

    }
    //print(head);
    //cout<<"\n";


    }
    cout<<input<<" ";
    cout<<cur_time<<" ";
    cout<<work_time<<" ";

    return 0;
}
