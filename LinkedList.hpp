#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int count;
        void swap(int index1, int index2);
        void newSwap(int index1, int index2);

    public:
        LinkedList();
        void addEnd(Card* c);
        void display();
        int getCount();
        void insertionSortOnDefense();
        void mergeSort(int begin, int end);
        void merge(int begin1, int end1, int begin2, int end2);
        void displayMergeSort(int begin, int end);
        Node* get(int index);
};