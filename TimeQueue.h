#ifndef __TIMEQ_H_
#define __TIMEQ_H_
//You can change/add to these #includes
#include <ctime>
#include <iostream>
#include <vector>

typedef int tq_hook; //Used to point to a location in the heap, fill in the "???"

//Forward declaration of Job class, do not remove this line, do not change.
class Job;

//Promise to declare stream output operator for internal vector heap representation
std::ostream& operator<<(std::ostream& out, const std::vector<Job*>& heap);

class TimeQueue{
private:
    std::vector<Job*> m_heap;

public:
    //template classes
    TimeQueue(){}
    void push(Job* job);
    Job* pop();
    Job*top();
    void remove_from_index(tq_hook time_hook);
    void percolate_down(int index,std::vector<Job*>& m_heap);
    void printHeap(std::ostream&outfile);
//////////FILL THIS IN///////////

};

#endif
