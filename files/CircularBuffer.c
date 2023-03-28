//- Copyright (c) 2008-2020 James Grenning --- All rights reserved
//- For exclusive use by participants in Wingman Software training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.wingman-sw.com james@wingman-sw.com

#include "CircularBuffer.h"
#include <memory.h>

struct CircularBuffer
{
    size_t input_index;
    size_t output_index;
    size_t capacity;
    int count;
    int default_values;
    int * values;
    
};


static size_t nextIndex(struct CircularBuffer * self, size_t index)
{
    index++;
    if (index >= self->capacity+1)
        index = 0;
    return index;
}

struct CircularBuffer * CircularBuffer_Create(int capacity,int default_value)
{
    struct CircularBuffer * self = (struct CircularBuffer *)calloc(1, sizeof(struct CircularBuffer));
    self->values = malloc((capacity+1) * sizeof(int));
    self->capacity = capacity;
    self->default_values=default_value;
    return self;
}

void CircularBuffer_Destroy(struct CircularBuffer * self)
{  
    free(self->values);
    free(self);
    
}


bool CircularBuffer_IsEmpty(struct CircularBuffer *self)
{
    
    return self->input_index==self->output_index;
};
  
bool  CircularBuffer_IsFull(struct CircularBuffer * self)
{   
    
    return nextIndex(self,self->input_index)==self->output_index;
    //return self->count==self->capacity;
    
};


bool CircularBuffer_Put(struct CircularBuffer *self, int value)
{
 if (CircularBuffer_IsFull(self))
 {
     return false ;
 }
 self->values[self->input_index]=value;
 self->count++;
 self->input_index++;
 self->input_index=nextIndex(self,self->input_index);   
 return true ;  
}

int  CircularBuffer_Get(struct CircularBuffer *self)
{
    
 if(CircularBuffer_IsEmpty(self))
 {
  return self->default_values;    
 }
 int value=self->values[self->output_index];
 self->output_index++;
 self->count--; 
 self->input_output=nextIndex(self,self->output_index); 
 return value;   
    
}    
    
    
int CircularBuffer_Capacity(struct CircularBuffer *self)
{
    return self->capacity;
}    
    
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    