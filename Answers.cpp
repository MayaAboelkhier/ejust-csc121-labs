#include <ostream>
#include <iostream>
#include "mem.hpp"


// Return the allocated segment. If no place found, return nullptr
Segment* allocate(Segment** head, unsigned int pid, unsigned int size) {
	int remain_size, start, whole_mem = 50;

    Segment* head2 = *head;
    while (head2 ->next != nullptr)
        head2 = head2 ->next;

    if (head2 ->prev == nullptr) {
        head2 ->start = 0;
        if ((int)size > whole_mem)
            return nullptr;

}
    else {
        if (size > head2 ->size)
            return nullptr;
    }
    head2 ->pid = pid;
    head2 ->size = size;

    Segment* New_tem = new Segment;
    head2 ->next = New_tem;
    New_tem->next = nullptr;
    New_tem->prev = head2;

    start = head2 ->start + size;
    remain_size = whole_mem - start;

    New_tem->pid = -1;
    New_tem->start = start;
    New_tem->size = remain_size;

    return *head;
}

// Free all segments allocated to process
void deallocate(Segment* head, unsigned int pid) {
    Segment* de = head;
    while (head->next != nullptr) {
        if (head ->pid == (int)pid)
            head ->pid = -1;
        head = head ->next;

    }
    while (de ->next != nullptr) {
        while (de ->pid == de ->next->pid) {
            de ->size += de ->next->size;
            de ->next = de ->next->next;
        }
                    de = de ->next;

    }

}


// For debugging/testing
// You can use this to print a list as follow: dump(std::cout, list_head)
//
// DO NOT EDIT
void dump(std::ostream& o, Segment* head) {
	while (head != nullptr) {
		o << "(" << (( head->pid == -1 )? "H":"P") << ", " << head->start << ", " << head->size << ") " << "--> ";
		head = head->next;
	}
	o << "NULL";
}

#ifndef GRADING // Don't delete

int main() {
	// You don't need to write anything here, but you can use it to try out your program

	return 0;
}

#endif
// Don't delete