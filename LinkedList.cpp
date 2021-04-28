#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}

Node* LinkedList::get(int index)
{
    Node* node2Return = this->head;
    for(int i = 0; i < index; i++)
    {
        node2Return = node2Return->getNextNode();
    }
    return node2Return;
}

void LinkedList::newSwap(int index1, int index2)
{
    int smaller = index1;
    int larger = index2;
    if(larger < smaller)
    {
        smaller = index2;
        larger = index1;
    }
    Node* smallerNode = this->get(smaller);
    Node* largerNode = this->get(larger);

    
}




void LinkedList::swap(int index1, int index2)
{
    int smaller = index1;
    int larger = index2;
    if(larger < smaller)
    {
        smaller = index2;
        larger = index1;
    }
    Node* smallerNode = this->get(smaller);
    Node* largerNode = this->get(larger);

    if(smaller != 0 && larger != this->count - 1)
    {
        smallerNode->getPrevNode()->setNextNode(largerNode);
        smallerNode->setNextNode(largerNode->getNextNode());
        largerNode->setNextNode(smallerNode);
        smallerNode->getNextNode()->setPrevNode(smallerNode);
        largerNode->setPrevNode(smallerNode->getPrevNode());
        smallerNode->setPrevNode(largerNode);
    }

    else if(smaller == 0 || larger == this->count-1)
    {
        if(smaller == 0 && larger == this->count-1)
        {
            this->head = largerNode;
            largerNode->setPrevNode(smallerNode->getPrevNode());
            smallerNode->setNextNode(largerNode->getNextNode());
            largerNode->setNextNode(smallerNode);
            smallerNode->setPrevNode(largerNode);
            this->tail = smallerNode;
        }

        if(smaller == 0)
        {
            this->head = largerNode;
            largerNode->setPrevNode(smallerNode->getPrevNode());
            smallerNode->setNextNode(largerNode->getNextNode());
            largerNode->setNextNode(smallerNode);
            smallerNode->setPrevNode(largerNode);
            smallerNode->getNextNode()->setPrevNode(smallerNode);
        }

        if(larger == this->count-1)
        {
            smallerNode->getPrevNode()->setNextNode(largerNode);
            largerNode->setPrevNode(smallerNode->getPrevNode());
            smallerNode->setNextNode(largerNode->getNextNode());
            largerNode->setNextNode(smallerNode);
            smallerNode->setPrevNode(largerNode);
            this->tail = smallerNode;
        }
    }    
}

void LinkedList::insertionSortOnDefense()
{
    int theFollower;
    for(int currStart = 1; currStart < this->count; currStart++)
    {
        theFollower = currStart;
        while(theFollower > 0 && this->get(theFollower)->getPayload()->getDefense() <
                this->get(theFollower-1)->getPayload()->getDefense())
        {
            //I need to swap
            this->swap(theFollower, theFollower-1);
            theFollower--;
        }
    }
}

void LinkedList::addEnd(Card* c)
{
    Node* n = new Node(c);
    if(this->count == 0)
    {
        this->head = n;
        this->tail = n;
    }
    else
    {
        n->setPrevNode(this->tail);
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::getCount()
{
    return this->count;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        currNode->getPayload()->display();
        currNode = currNode->getNextNode();
    }
}

void LinkedList::mergeSort(int begin, int end)
{
    if(begin != end)
    {
        int begin1 = begin;
        int end1 = (begin + end) / 2;
        int begin2 = end1 + 1;
        int end2 = end;

        mergeSort(begin1, end1);
        mergeSort(begin2, end2);
        merge(begin1, end1, begin2, end2);
    }
}

void LinkedList:: merge(int begin1, int end1, int begin2, int end2)
{
    int size = end2 - begin1 + 1;
    Card* temp[size];
    int pos1 = begin1;
    int pos2 = begin2;
    for(int i = 0; i < size; i++)

    {

        //how do we ask if pos1 points to a legal place on the left half of the list?

        if(pos1 <= end1 && pos2 <= end2)
        {
            if(this->get(pos1)->getPayload()->getDefense() < this->get(pos2)->getPayload()->getDefense())
            {
                temp[i] = this->get(pos1)->getPayload();
                pos1++;
            }
            else
            {
                temp[i] = this->get(pos2)->getPayload();
                pos2++;
            }
        }
        else if(pos1 <= end1)
        {
            temp[i] = this->get(pos1)->getPayload();
            pos1++;
        }
        else
        {
            temp[i] = this->get(pos2)->getPayload();
            pos2++;
        }
    }
    int tempPos = 0;
    for(int i = begin1; i <= end2; i++)
    {
        this->get(i)->setPayLoad(temp[tempPos]);
        tempPos++;
    }
}

void LinkedList::displayMergeSort(int begin, int end)
{
    Node* currNode = this->get(begin);
    for(int i = begin; i <= end; i++)
    {
        currNode->getPayload()->display();
        currNode = currNode->getNextNode();
    }
}





// //the goal is to ensure that the array from begin1 to end2 is in order

// void merge(int* ar, int begin1, int end1, int begin2, int end2)

// {

//     int size = end2 - begin1 + 1;

//     int temp[size];

//     int pos1 = begin1;

//     int pos2 = begin2;

//     for(int i = 0; i < size; i++)

//     {

//         //how do we ask if pos1 points to a legal place on the left half of the list?

//         if(pos1 <= end1 && pos2 <= end2)

//         {

//             if(ar[pos1] < ar[pos2])

//             {

//                 temp[i] = ar[pos1];

//                 pos1++;

//             }

//             else

//             {

//                 temp[i] = ar[pos2];

//                 pos2++;

//             }

//         }

//         else if(pos1 <= end1)

//         {

//             temp[i] = ar[pos1];

//             pos1++;

//         }

//         else

//         {

//             temp[i] = ar[pos2];

//             pos2++;

//         }

//     }

    

//     //temp is filled up with our values in the correct order

//     //we need to now transfer those value back over to ar overwriting

//     //the old contents of ar with the contents of temp between begin1 and end2

//     int tempPos = 0;

//     for(int i = begin1; i <= end2; i++)

//     {

//         ar[i] = temp[tempPos];

//         tempPos++;

//     }

//     //now ar is overwritten between begin1 and end2 with the values in order

//     //and this call to merge and mergesort can end;

// }

// //the job of this function is to sort the list from begin to end

// void mergeSort(int* ar, int begin, int end)

// {

//     //displayArray(ar, begin, end);

    

//     //we only need to do anything in here, if the list is bigger than a 1 list

//     if(begin != end)

//     {

//         //we DO NOT HAVE A 1 LIST!!!!!

//         //so we need to divide our list in half and call mergesort on each half

//         int begin1 = begin;

//         int end1 = (begin + end) / 2;

//         int begin2 = end1 + 1;

//         int end2 = end;

//         mergeSort(ar, begin1, end1);

//         mergeSort(ar, begin2, end2);

        

//         //now the left half is sorted and the right half is sorted

//         //we need to merge them together into a single sorted portion

//         //of our list from begin to end 

//         merge(ar, begin1, end1, begin2, end2);

//     }

    

// }

// int main()

// {

//     srand (time(NULL));

//     int ar[ARRAYSIZE];

//     /*

//     for(int i = 0; i < ARRAYSIZE; i++)

//     {

//         ar[i] = rand() % 101;

//     }

//     */

//     //4 2 1 6 0 3

//     ar[0] = 4;

//     ar[1] = 2;

//     ar[2] = 1;

//     ar[3] = 6;

//     ar[4] = 0;

//     ar[5] = 3;

//     displayArray(ar, 0, ARRAYSIZE-1);

//     mergeSort(ar, 0, ARRAYSIZE-1);

//     displayArray(ar, 0, ARRAYSIZE-1);

//     return 0;

// }