/* 
 * Implement:
 *      Linear search
 *      Binary search
 * */

#ifndef ARRAYOPS_H
#define ARRAYOPS_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

const int TOP_EDGE = 99;
const int BOTTOM_EDGE = 1;

void PrintArray(const int* const Array, int Size);
void PrintReversedArray(const int* const Array, int Size);
void RandomFill(int* Array, int Size);
void Swap(int* T1, int* T2);
void BubbleSort(int* Array, int Size);
void InsertationSort(int* Array, int Size);
int FindMaximal(int* const Array, int LeftPos, int RightPos);

void PrintArray(const int* const Array, int Size)
{
    assert(Array != NULL);
    assert(Size >= 0);
    for(int i = 0; i < Size; i++)
    {
        cout << "Array[" << i << "] = " << *(Array + i) << endl;
    }
}

void PrintReversedArray(const int* const Array, int Size)
{
    assert(Array != NULL);
    assert(Size >= 0);
    /*
     * We mast to check for Size > 0, because if size have Size=0 
     * length, i = Size - 1 = -1, so ARRAY CAN'T HAVE -1 INDEX.
     * */
    if(Size >= 1)
    {
        for(int i = Size - 1; i >= 0; i--)
        {
            cout << "Array[" << i << "] = " << *(Array + i) << endl;
        }
    }
    else
    {
        cout << "Array[" << 0 << "] = " << *(Array) << endl;
    }
}

void RandomFill(int* const Array, int Size)
{
    assert(Array != NULL);
    assert(Size >= 0);
    for(int i = 0; i < Size; i++)
    {
        *(Array + i) = rand()%TOP_EDGE + BOTTOM_EDGE;
    }
}

void Swap(int* T1, int* T2)
{
    assert(T1 != NULL);
    assert(T2 != NULL);

    int Temp = *(T1);
    *(T1) = *(T2);
    *(T2) = Temp;
}

void BubbleSort(int* const Array, int Size)
{
    /*
     *  Size must be greater than 0, because, if array have
     *  only ONE element, that means that it ALREADY SORTED!
     * */
    assert(Array != NULL);
    assert(Size > 0);
    for(int i = Size; i > 0; i--)
    {
        for(int j = 0; j < Size - 1; j++)
        {
            if(*(Array + j) > *(Array + j + 1))
            {
                /* Swap elements  */
                Swap((Array + j), (Array + j + 1));
            }
        }
    }
}

void InsertationSort(int* Array, int Size)
{
    assert(Array != NULL);
    assert(Size > 0);
    for(int i = 1; i < Size; i++)
    {
        int j = i;
        while(j > 0 && *(Array + j - 1) > *(Array + j))
        {
            Swap((Array + j - 1), (Array + j));
            --j;
        }
    }
}

int FindMaximal(int* Array, int LeftPos, int RightPos)
{
    assert(Array != NULL);
    assert(LeftPos >= 0);       // Array can't have negative index
    assert(RightPos >= 0);      // Array can't have negative index

    if(LeftPos == RightPos)
    {
        return *(Array + LeftPos);
    }

    int Middle = (LeftPos + RightPos)/2;
    int First = FindMaximal(Array, LeftPos, Middle);
    int Second = FindMaximal(Array, Middle + 1, RightPos);

    if(First > Second)
    {
        return First;
    }
    else
    {
        return Second;
    }
}
#endif 
