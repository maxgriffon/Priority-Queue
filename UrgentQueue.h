#ifndef __URGENTQ_H_
#define __URGENTQ_H_
//You can change/add to these #includes
#include <ctime>
#include<iostream>
#include <vector>



typedef int uq_hook; //Used to point to a location in the heap, fill in the "???"

//Forward declaration of Job class, do not remove this line, do not change.
class Job;

//Promise to declare stream output operator for internal vector heap representation
std::ostream& operator<<(std::ostream& out, const std::vector<Job*>& heap);

class UrgentQueue{
private:
    std::vector<Job*> m_heap;
public:
    UrgentQueue(){}
    void push(Job* job);
    Job* pop();
    Job* top();
    void remove_from_index(uq_hook urgent_hook);
    void percolate_down(int index,std::vector<Job*>& m_heap);
    void printHeap(std::ostream&outfile);

};

#endif
