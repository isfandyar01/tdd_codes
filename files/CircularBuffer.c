//- Copyright (c) 2008-2020 James Grenning --- All rights reserved
//- For exclusive use by participants in Wingman Software training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.wingman-sw.com james@wingman-sw.com

#include "CircularBuffer.h"
#include <memory.h>

struct CircularBuffer
{
    int needed_to_prevent_the_compiler_from_complaining_about_an_empty_struct;
};

struct CircularBuffer * CircularBuffer_Create(void)
{
    struct CircularBuffer * self = (struct CircularBuffer *)calloc(1, sizeof(struct CircularBuffer));
    return self;
}

void CircularBuffer_Destroy(struct CircularBuffer * self)
{
    free(self);
}


bool CircularBuffer_IsEmpty(CircularBuffer *self)
{

    return False;
};
  
