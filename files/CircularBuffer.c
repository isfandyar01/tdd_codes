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
    int capacity;
    int values[10];
    
};

struct CircularBuffer * CircularBuffer_Create(int capacity)
{
    struct CircularBuffer * self = (struct CircularBuffer *)calloc(1, sizeof(struct CircularBuffer));
    self->capacity=capacity;
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

 self->values[self->input_index]=value;;
 self->input_index++;   
}

int  CircularBuffer_Get(struct CircularBuffer *self)
{
 int value=self->values[self->output_index];
 self->output_index++;
    
 return value;   
    
}    
    
    
int CircularBuffer_Capacity(struct CircularBuffer *self)
{
    return self->capacity;
}    
    
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    