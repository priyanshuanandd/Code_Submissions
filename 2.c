/*
 * AstroTinker Bot (AB): Task 1B Path Planner
 *
 * This program computes the valid path from the start point to the end point.
 * Make sure you don't change anything outside the "Add your code here" section.
 * Updated memory addresses for Task 2B
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef _linux_ // for host pc

#include <stdio.h>

void _put_byte(char c) { putchar(c); }

void _put_str(char *str)
{
    while (*str)
    {
        _put_byte(*str++);
    }
}

void print_output(uint8_t num)
{
    if (num == 0)
    {
        putchar('0'); // if the number is 0, directly print '0'
        _put_byte('\n');
        return;
    }

    if (num < 0)
    {
        putchar('-'); // print the negative sign for negative numbers
        num = -num;   // make the number positive for easier processing
    }

    // convert the integer to a string
    char buffer[20]; // assuming a 32-bit integer, the maximum number of digits is 10 (plus sign and null terminator)
    uint8_t index = 0;

    while (num > 0)
    {
        buffer[index++] = '0' + num % 10; // convert the last digit to its character representation
        num /= 10;                        // move to the next digit
    }

    // print the characters in reverse order (from right to left)
    while (index > 0)
    {
        putchar(buffer[--index]);
    }
    _put_byte('\n');
}

void _put_value(uint8_t val) { print_output(val); }

#else // for the test device

void _put_value(uint8_t val) {}
void _put_str(char *str) {}

#endif
// bool adjmatrix[30][30];

void newgraph(bool visited[], bool *top)
{

    for (int i = 0; i < 30; i++)
    {
        visited[i] = false;
        for (int j = 0; j < 30; j++)
        {
            *((top + i) + j) = false;
        }
    }
}

void edge(bool *top, int u, int v)
{
    *((top + ) + v) = true;
    *((top + v) + u) = true;
}

bool recursivepath(int str, int end, bool visited[], bool *top, uint8_t test[], uint8_t testindex)
{
    visited[str] = true;
    if (str == end)
    {
        test[testindex] = str;
        return true;
    }
    for (int i = 0; i < 30; i++)
    {
        if (((top + str) + i) && !visited[i])
        {
            test[testindex] = str;
            if (recursivepath(i, end, visited, top, test, testindex + 1))
            {
                return true;
            }
        }
    }
    visited[str] = false;
    return false;
}

/*
Functions Usage

instead of using printf() function for debugging,
use the below function calls to print a number, string or a newline

for newline: _put_byte('\n');
for string:  _put_str("your string here");
for number:  _put_value(your_number_here);

Examples:
        _put_value(START_POINT);
        _put_value(END_POINT);
        _put_str("Hello World!");
        _put_byte('\n');

*/

// main function
int main(int argc, char const *argv[])
{
    bool *head;
#ifdef _linux_

    const uint8_t START_POINT = atoi(argv[1]);
    const uint8_t END_POINT = atoi(argv[2]);
    uint8_t NODE_POINT = 0;
    uint8_t CPU_DONE = 0;
    bool *head;
#else
// Address value of variables are updated for RISC-V Implementation
#define START_POINT (*(volatile uint8_t *)0x02000000)
#define END_POINT (*(volatile uint8_t *)0x02000004)
#define NODE_POINT (*(volatile uint8_t *)0x02000008)
#define CPU_DONE (*(volatile uint8_t *)0x0200000c)
    // #define head                (* (volatile bool *) 0x01000000)
#endif

    // array to store the planned path
    uint8_t path_planned[32];

    // index to keep track of the path_planned array
    uint8_t idx = 0;
    bool visited[30];
    bool adjmatrix[30][30];
    head = &adjmatrix[30][30];
    // ############# Add your code here #############
    newgraph(visited, &adjmatrix[0][0]);
    edge(head, 0, 1);
    edge(head, 1, 2);
    edge(head, 1, 29);
    edge(head, 2, 3);
    edge(head, 2, 8);
    edge(head, 3, 4);
    edge(head, 4, 5);
    edge(head, 4, 6);
    edge(head, 6, 7);
    edge(head, 7, 8);
    edge(head, 8, 9);
    edge(head, 8, 12);
    edge(head, 9, 10);
    edge(head, 9, 11);
    edge(head, 12, 13);
    edge(head, 13, 14);
    edge(head, 14, 15);
    edge(head, 14, 16);
    edge(head, 16, 17);
    edge(head, 16, 18);
    edge(head, 18, 19);
    edge(head, 19, 20);
    edge(head, 20, 21);
    edge(head, 20, 24);
    edge(head, 20, 29);
    edge(head, 21, 22);
    edge(head, 21, 23);
    edge(head, 24, 25);
    edge(head, 25, 26);
    edge(head, 26, 27);
    edge(head, 26, 28);
    edge(head, 28, 29);

    if (recursivepath(START_POINT, END_POINT, visited, head, path_planned, idx))
    {
        while (path_planned[idx] != END_POINT)
        {
            idx++;
        }
        idx++;
    }
#ifdef _linux_ // for host pc

    _put_str("######### Planned Path #########\n");
    for (int i = 0; i < idx; ++i)
    {

        _put_value(path_planned[i]);
    }
    _put_str("################################\n");

#endif

    // ##############################################

    // the node values are written into data memory sequentially.
    for (int i = 0; i < idx; ++i)
    {
        NODE_POINT = path_planned[i];
    }
    // Path Planning Computation Done Flag
    CPU_DONE = 1;

    return 0;
}