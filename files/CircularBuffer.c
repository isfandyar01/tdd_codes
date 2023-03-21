//- Copyright (c) 2008-2020 James Grenning --- All rights reserved
//- For exclusive use by participants in Wingman Software training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.wingman-sw.com james@wingman-sw.com

#include "CircularBuffer.h"
#include <memory.h>

struct CircularBuffer
{
    int input_index;
    int output_index;
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


bool CircularBuffer_IsEmpty(struct CircularBuffer *self)
{

    return self->input_index==self->output_index;
};
  
bool  CircularBuffer_IsFull(struct CircularBuffer *)
{
    return false;
};


void  CircularBuffer_Put(struct CircularBuffer *self, int value)
{
 self->input_index++;
 self->input_index=value;   
}

int  CircularBuffer_Get(struct CircularBuffer *self)
{
 int value=self->output_index;
 self->output_index++;
    
 return value;   
    
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    