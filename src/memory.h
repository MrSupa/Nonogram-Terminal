#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

typedef struct MemoryNode
{
    void* addr;
    size_t size;
    struct MemoryNode* next;
} MemoryNode;

extern MemoryNode Registry;

#endif //MEMORY_H