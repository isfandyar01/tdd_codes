//- Copyright (c) 2008-2020 James Grenning --- All rights reserved
//- For exclusive use by participants in Wingman Software training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.wingman-sw.com james@wingman-sw.com

#ifndef CIRCULAR_BUFFER_INCLUDED
#define CIRCULAR_BUFFER_INCLUDED
#include <stdbool.h>

struct CircularBuffer;

struct CircularBuffer * CircularBuffer_Create(size_t capacity, int default_value);
void CircularBuffer_Destroy(struct CircularBuffer *);
bool CircularBuffer_IsEmpty(struct CircularBuffer *);
bool  CircularBuffer_IsFull(struct CircularBuffer *);
void  CircularBuffer_Put(struct CircularBuffer *, int);
int  CircularBuffer_Get(struct CircularBuffer *);
#endif
