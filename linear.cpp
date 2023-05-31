//
//  linear.cpp
//  hw3
//
//  Created by William  Escobar on 5/7/23.
//


//#include <string>
//#include <iostream>
//using namespace std;

bool somePredicate(string s);

    // Return false if the somePredicate function returns false for at
    // least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n)
{
    //base case
    if(n <= 0)
        return false;
    //predicate check on current FIRST element
    if(somePredicate(a[0]))
        return true;
    //recursion call
     return allTrue(a+1, n-1);
}

    // Return the number of elements in the array for which the
    // somePredicate function returns true.
int countTrue(const string a[], int n)
{
    int part1, part2;
    part1 = part2 = 0;

     //base case
    if(n<=0)
        return 0;
    //preicate check on current First element
    if(somePredicate(a[0]))
        part1++;
    //recursion call
    part2 = countTrue(a+1, n-1);
    //sum results of recursion
    return part1 + part2;
}

    // Return the subscript of the first element in the array for which
    // the somePredicate function returns true.  If there is no such
    // element, return -1.
int firstTrue(const string a[], int n)
{
    //base case
    if(n <= 0)
        return -1;
    //predicate check on current LAST element
    if(somePredicate(a[n-1])) //here, we are checking the last element in the array
        return n-1;
    //recursion call
     return firstTrue(a, n-1);//we send in the array but now one element smaller
}

    // Return the subscript of the first string in the array that is >= all
    // strings in the array (i.e., return the smallest subscript m such
    // that a[m] >= a[k] for all k from 0 to n-1).  If the function is told
    // that no strings are to be considered to be in the array, return -1.
int positionOfMax(const string a[], int n)
{
    //base cases-----
    if(n<=0)
        return -1;
    if(n==1)
        return 0;
    //---------------

    int posOfMax = positionOfMax(a, n-1);

    if(a[n-1] > a[posOfMax])
        return n-1;

    return posOfMax;
}

    // If all n2 elements of a2 appear in the n1 element array a1, in
    // the same order (though not necessarily consecutively), then
    // return true; otherwise (i.e., if the array a1 does not include
    // a2 as a not-necessarily-contiguous subsequence), return false.
    // (Of course, if a2 is empty (i.e., n2 is 0), return true.)
    // For example, if a1 is the 7 element array
    //    "john" "sonia" "elena" "ketanji" "sonia" "elena" "samuel"
    // then the function should return true if a2 is
    //    "sonia" "ketanji" "samuel"
    // or
    //    "sonia" "elena" "elena"
    // and it should return false if a2 is
    //    "sonia" "samuel" "ketanji"
    // or
    //    "john" "ketanji" "ketanji"
bool contains(const string a1[], int n1, const string a2[], int n2)
{
    //base cases-------------
    if(n2<=0)
        return true;
    if(n1<=0)
        return false;
    //------------------------

    if (a1[0] == a2[0])
        return contains(a1 + 1, n1 - 1, a2 + 1, n2 - 1); //if both equal advance both

    return contains(a1 + 1, n1 - 1, a2, n2);//if not equal just advance the first array
}
