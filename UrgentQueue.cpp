#include<iostream>
#include <vector>

#include "UrgentQueue.h"
#include "Job.h"

//push adds them to the back and then percolates up
void UrgentQueue::push(Job* job){
    //check if heap is empty
    if(m_heap.size()==0){
        m_heap.push_back(job);
        m_heap[0]->urgent_hook=0;
        m_heap[0]->priority_ptr=this;
        return;
    }
    //adds the value and intializes everything
    m_heap.push_back(job);
    int i=(m_heap.size()-1);
    //sets the hook and the pointer
    m_heap[i]->urgent_hook=i;
    m_heap[i]->priority_ptr=this;
    //percolates up and replaces everything that needs to be replaced
    while(i>=0){
        //goes to parent and checks which is bigger if it is smaller replaces
        if((m_heap[i]->getPriority())>(m_heap[(i-1)/2]->getPriority())){
            Job* temp=m_heap[i];
            m_heap[i]=m_heap[(i-1)/2];
            //swaps the values and then swaps the hooks
            m_heap[i]->urgent_hook=i;
            m_heap[(i-1)/2]=temp;
            //increments i
            i = (i-1)/2;
            m_heap[i]->urgent_hook=i;

        }
        //if it is in the right place
        else{
            break;
        }
    }
}

//removes from queue
void UrgentQueue::remove_from_index(uq_hook urgent_hook){
    //checks if it is empty
    if(m_heap.empty()){
        return;
    }
    Job* temp=m_heap[urgent_hook];
    m_heap[urgent_hook]=m_heap[m_heap.size()-1];
    m_heap[m_heap.size()-1]=temp;
    //swaps eveything and pops the back
    m_heap.pop_back();
    //calls percolate_down
    percolate_down(urgent_hook,m_heap);
}

//moves the root to the right place
void UrgentQueue::percolate_down(int index,std::vector<Job*>& m_heap) {
    int c_index=0;
    //will keep going as long as it has children
    while((2*index+1)<m_heap.size()){
        //checks which child is less than or greater than
        if(2*index+2<m_heap.size() && m_heap[2*index+2]->getPriority()
                >m_heap[2*index+1]->getPriority()){
            c_index=2*index+2;
        }
        else {
            c_index=2*index+1;
        }
        Job* child=m_heap[c_index];
        //compares the child and the parent
        if(child->getPriority()>m_heap[index]->getPriority()){
            //switches everything and the hooks
            Job* temp=m_heap[index];
            m_heap[index]=child;
            m_heap[index]->urgent_hook=index;
            m_heap[c_index]=temp;
            m_heap[c_index]->urgent_hook=c_index;
            index=c_index;
        }   else {
                break;
        }
     }
 }

 //takes out the first value and returns it by putting it to the back and then
 //poping it
Job* UrgentQueue::pop(){
    //checks if m_heap is empty
    if (m_heap.empty()){
        return NULL;
    }
    //switches everything and pops it
    Job* temp=m_heap[0];
    m_heap[0]=m_heap[m_heap.size()-1];
    m_heap[m_heap.size()-1]=temp;
    m_heap.pop_back();
    percolate_down(0,m_heap);
    return temp;
}

//returns the top
Job* UrgentQueue::top(){
    if (m_heap.empty()){
        return NULL;
    }
    return m_heap[0];
}

//prints the job
void UrgentQueue::printHeap(std::ostream & outfile){
    //prints it by using the operator
    outfile<< "UQ "<<m_heap.size()<<" jobs:"<<std::endl;
    for(int i=0;i<m_heap.size();i++){
        outfile<<"\t"<<m_heap[i];
    }

}
