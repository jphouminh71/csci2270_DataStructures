#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <string>

// Structure to store the patients information: Name, Injury Severity and Treatment Time
struct PatientNode
{
    std::string name;
    int injurySeverity;
    int treatmentTime;
};

/* class PriorityQueue for storing the patients in a queue.
 * check the homework document on moodle for function descriptions
*/

class PriorityQueue
{
    public:
        PriorityQueue(int _queueSize);    // done
        ~PriorityQueue();   // this isnt right but its cmopiling
        void enqueue (std::string _name, int _injurySeverity, int _treatmentTime);
        std::string peekName();     // done
        int peekInjurySeverity();   // done
        int peekTreatmentTime();    // done
        void dequeue();
        bool isFull();    // done
        bool isEmpty();   // done 

    private:
        /* member functions */
        void repairUpward(int nodeIndex);
        void repairDownward(int nodeIndex);

        /* Instance variables */
        PatientNode* priorityQueue; //points to the array used to implement priority queue
        int currentQueueSize;
        int maxQueueSize;
};
#endif
