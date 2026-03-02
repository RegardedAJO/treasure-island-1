//CS 215U 19Z1 19Z2
//Spring 2026
//online

//Assorted sorter




#ifndef ASSORTEDSORTER_H
#define ASSORTEDSORTER_H

class AssortedSorter
{   
    private:                                        // declare the class variables used to copy the array from main
    static const int maxSize = 20001;
    int ArrayUsedForCopy[maxSize];
    int sizeOfArrayFilled;
    
    void copyArray(int [], int [], int);        // declares the copy array that will copy the array from main into a copy that will be sorted

    public:
    AssortedSorter(int [], int);            // class constructor that will take the array and its size from main 
    void bubbleSort(int [], int, long int&, long int&);         // the following lines declare the sort functions
    void selectionSort(int [], int, long int&, long int&);
    void shellSort(int [], int, int [], int, long int&, long int&);
    void quickSort(int [], int, long int&, long int&);
    int partition(int [], int, int, long int&, long int&);
    

};

#endif
