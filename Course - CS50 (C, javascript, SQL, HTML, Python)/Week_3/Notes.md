## Linear Search

**Works**

Itterate accross array from left to right, searching for specific element

**Uses**

Cane be used to find an element in an array.


**Pseudocode**

    Repeat, starting at first element
        If the first element is what we are looking    for - Stop
        Othervise - move on to next element


**Worst case**

We have to look trough the entire array. 
 - Poor On

**Best case**

Find it immediatly - Good omega


## Binary search

In binary search you reduce target area 50% each time. This requires a sorted array.

**Pseducode**

    Repeat until array is empty
        Calculate middle
        If middle is target - stop
        Otherevise, change to the right or left and repeat whole loop.

