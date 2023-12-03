/*
Author: Kenneth Guillont
Course: CSCI-136
Instructor: Brandon Foster
Assignment: Task D. Is string alphanumeric?
*/

#include <iostream>
using namespace std;

bool nestedParens(string s)
{
    int n = s.size();

    if (n == 0)
    {
        return true; 
    }
    else
    {
        if (s[0] != '(' || s[n - 1] != ')')
        {
            return false;
        }
        else
        {
            return nestedParens(s.substr(1, n - 2)); 
        }
    }
}


bool isAlphanumeric(string s)
{
    if (s.empty())
    {
        return true;
    }
    else
    {
        char c = s[0];
        if (!isalnum(c))
        {
            return false; 
        }
        else
        {
            return isAlphanumeric(s.substr(1)); 
        }
    }
}

int sumArrayInRange(int *arr, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    else
    {
        return arr[left] + sumArrayInRange(arr, left + 1, right);
    }
}

int sumArray(int *arr, int size)
{
    return sumArrayInRange(arr, 0, size - 1);
}

int sumRange(int left, int right)
{
    if (left > right)
    {return 0; }

    else
        {return left + sumRange(left + 1, right);}
}

void printRange(int left, int right)
{

    if(left <= right)
    {
        cout << left << " ";
        left++; 
        printRange(left, right);
    }
}

int main() 
{

    cout << isAlphanumeric("ABCD") << endl;        // true (1)
    cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
    cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)

    return 0;
}
