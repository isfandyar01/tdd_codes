//- Copyright (c) 2008-2020 James Grenning --- All rights reserved
//- For exclusive use by participants in Wingman Software training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.wingman-sw.com james@wingman-sw.com

#include "CppUTest/TestHarness.h"

extern "C"
{
#include "CircularBuffer.h"
}

TEST_GROUP(CircularBuffer)
{
    CircularBuffer * buffer;

    void setup()
    {
        buffer = CircularBuffer_Create(2,0);
    }

    void teardown()
    {
        CircularBuffer_Destroy(buffer);
    }
};

TEST(CircularBuffer, create_destroy)
{

}

/*
 * TDD Exercise
 *
 *   - Move the #if down the page one test at a time.
 *   - Read the discussion comments before each test case
 *   - Incrementally develop the circular buffer
 *   - Refer to the sketches in the exercise instructions
 *     for interesting CircularBuffer states.
 *   - Delete all previous comments as you
 *     finish each test.
 *
*/

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

//#ifdef Move_this_line_down_one_test_to_simulate_james_writing_the_test
/*
 * Discussion with James about next test:
 * How do we choose the first test? Let's test initialization.
 * What should the state of the CircularBuffer be after creation?
 * It should be empty.  Let's write a test that defines
 * that interface an assures buffers start out empty.
 */

TEST(CircularBuffer, is_empty_after_creation)
{
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Discussion with James about next test:
 * While the buffer is empty, it can't also be full.
 * Let's write that test.
 */

TEST(CircularBuffer, is_not_full_after_creation)
{
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Retrospective:
 * To get the prior two tests passing
 * all you need are the function declaration in
 * the header with hard-coded return results in
 * the implementation.  Please delete any other code you
 * don't need yet.
 */

/*
 * Discussion with James about next test:
 * If we put a value into the buffer, it should no
 * longer be empty. Let's define the Put interface
 * and write a test for the empty to not empty boundary
 * condition.
 */
TEST(CircularBuffer, is_not_empty_after_put)
{
    CircularBuffer_Put(buffer, 10046);
    CHECK_FALSE(CircularBuffer_IsEmpty(buffer));
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Discussion with James about next test:
 * While we are at it, let's transition back to empty
 * after putting in one value.  We're testing another
 * boundary condition and defining another interface.
 */

TEST(CircularBuffer, is_empty_after_put_then_get)
{
    CircularBuffer_Put(buffer, 42);
    CircularBuffer_Get(buffer);
    CHECK(CircularBuffer_IsEmpty(buffer));
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Retrospective:
 * To get the prior two tests passing
 * all you needed was to add an input-index
 * and an output-index to the structure, incrementing them
 * in Put and Get and using them to decide if the queue
 * is empty.  You don't need to store anything yet.
 */

/*
 * Discussion with James about next test:
 * Now, lets write a test that checks that a single
 * number put in the queue can be removed.
 */

TEST(CircularBuffer, put_get_one_value)
{
    CircularBuffer_Put(buffer, 4567);
    LONGS_EQUAL(4567, CircularBuffer_Get(buffer));
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Retrospective:
 * With the previous tests passing you should not need to store
 * anything.  You can hard code the return value for Get()
 *
 * If you have more, delete it now!  It is not tested code, you
 * are supposed to be doing TDD!
 */

/*
 * Discussion with James about next test:
 * With this test it will be more trouble to fake several values
 * than to introduce an array to hold the values.  Make the
 * array a fixed size for now. We can make it selectable
 * in a few tests.
 */

TEST(CircularBuffer, put_get_is_fifo)
{
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    LONGS_EQUAL(1, CircularBuffer_Get(buffer));
    LONGS_EQUAL(2, CircularBuffer_Get(buffer));
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Retrospective:
 * The previous test has driven you to have a simple internal
 * array in the structure with fixed size, an input-index and
 * an output-index.
 *
 * There should be no circular buffer logic yet!  And no dynamic
 * allocation.
 *
 */

/*
 * Discussion with James about next test:
 * We know a hard-coded buffer length is not going to work
 * in production.  The user of the buffer should provide the
 * capacity when the buffer is created.
 *
 * We'll have to pass the capacity to the CircularBuffer
 * during Create. Before we do that, let's create a Capacity
 * function, so we can query the capacity.
 *
 * This brings us one step closer to dynamically sizing the values array.
 */

TEST(CircularBuffer, report_capacity)
{
    LONGS_EQUAL(2, CircularBuffer_Capacity(buffer));
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Now let's change the call to CircularBuffer_Create
 * to accept the capacity.  Once this test passes you are ready to
 * dynamically allocate the values array.
 *
 * Don't forget to update CircularBuffer_Create() in setup()!
 */

TEST(CircularBuffer, create_sets_capacity)
{
    CircularBuffer * buffer = CircularBuffer_Create(2,0);
    LONGS_EQUAL(2, CircularBuffer_Capacity(buffer));
    CircularBuffer_Destroy(buffer);
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */
/*
 ***** NOTICE *****
 * Before you move on, you should modify your implementation
 * to dynamically allocate the values array.
 *
 * (There is no test to make you add dynamic allocation)
 *
 * The tests provide a safety net to support converting
 * your fixed size array to a pointer to allocated memory.
 *
 * YOU SHOULD NOW CONVERT YOUR CircularBuffer TO USE
 * ALLOCATED MEMORY!
 *
 * If you are not sure what to do:
 *    Here is an example of memory allocation
 *        char * bunch_of_chars = (char *)malloc(42);
 *
 *    Here is an example of allocate array usage
 *        char c = bunch_of_chars[12];
 *
 *    Here is an example of releasing allocated memory
 *        free(bunch_of_chars);
 *
 * Check the dynamic allocation hints in the exercise
 * instructions.
 *
 * Make sure you later watch the video of James completing
 * the CircularBuffer to see how CppUTest helps you find
 * allocated memory abuses.
 */

/*********************************************************
 *
 * DO NOT CONTINUE UNTIL YOU CONVERT YOUR CircularBuffer
 * TO USE DYNAMIC ALLCATION
 *
 *********************************************************/

/*
 * Discussion with James about next test:
 * Now let's fill the queue all the way and add the
 * IsFull implementation.
 *
 * 1) Write the test and watch it fail.
 * 2) Then consider the implementation.  You might want
 *    to draw the diagram for the full scenario.
 * 3) Before you implement IsFull, Consider the full scenarion
 *    and your implementation.
 *
 *    What is the relationship between the input index and 
 *    the output imndex for the full case?  How does that differ
 *    from the empty case.
 *
 *    Once you have your hypothesis, look at the exercise hints
 *    found in the exericse instructions.
 */

TEST(CircularBuffer, is_full_when_filled_to_capacity)
{   CircularBuffer * buffer = CircularBuffer_Create(5,0);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Put(buffer, 3);
    CircularBuffer_Put(buffer, 4);
    CircularBuffer_Put(buffer, 5);
 
    CHECK_TRUE(CircularBuffer_IsFull(buffer));
    CircularBuffer_Destroy(buffer);
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/* Retrospective:
 *
 * If you have wrap around logic already, you have untested
 * code. Please delete the untested code. How many times do I 
 * have to tell you?! :-) It's hard to stop writing code
 * you are sure you will need. If you avoid writing more than
 * is needed, you have a better chance of writing all the 
 * tests that you need.
 */

/*
 * Discussion with James about next test:
 * Now let's transition from full by getting one thing
 * out.
 */

TEST(CircularBuffer, is_not_full_after_get_from_full_buffer)
{
    CircularBuffer * buffer = CircularBuffer_Create(5,0);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Put(buffer, 3);
    CircularBuffer_Put(buffer, 4);
    CircularBuffer_Put(buffer, 5);
    CircularBuffer_Get(buffer);
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
    CircularBuffer_Destroy(buffer);
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 *  If you are using a loop to fill the buffer, you are
 *  overdue for refactoring your tests.
 *
 *  Refactor the loop into a fillTheBuffer helper
 *  function, add it as a helper function to the TEST_GROUP.
 *  Get rid of all the duplication.
 *
 *  Alternatively to the helper, can you make the loop unnecessary?
 *
 *  Of course you can.  Try using a small CircularBuffer and
 *  eliminate the loop. -- Straight line logic, is easier to fit
 *  between the ears than conditional logic and a for loop.
 */

/*
 * If you choose to refactor out the duplication: Add a TEST_GROUP
 * helper function.  TEST_GROUP functions are available to all TESTs
 * in the group.
 *
 * fillTheQueue's signature looks like this:
 *     void fillTheQueue(int seedValue, int numberOfElements)
 *
 *  An even better idea: can you make the loop unnecessary?
 */

/*
 *  BTW: At this point in the exercise you should not have
 *  any production code that is worried about doing a Get
 *  from an empty buffer, or putting to a full buffer.
 *  You will worry about that in the next test.
 *  TDD, remember?
 *
 */

/*
 * Discussion with James about next test:
 * Let's fill it and empty it.
 */

TEST(CircularBuffer, fill_to_capacity_then_empty)
{   CircularBuffer * buffer = CircularBuffer_Create(3,0);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Put(buffer, 3);

    CircularBuffer_Get(buffer);
    CircularBuffer_Get(buffer);
    CircularBuffer_Get(buffer); 
 
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Retrospective:
 * With the fill_to_capacity_then_empty test there is still
 * no need for the wrap around logic.  Delete it.
 */

/*
 * Retrospective:
 * Did that test pass without changes to the production code?
 * That is not a big surprise, it happens.
 */

/*
 * Discussion with James about next test:
 * Finally, we have to do the wrap around test.
 *
 * Let's fill the buffer, then take something out
 * and then add a obviously different value.  Then
 * we'll make sure all values are retrieved in FIFO.
 */

TEST(CircularBuffer, force_a_buffer_wraparound)
{
    CircularBuffer * buffer = CircularBuffer_Create(3,0);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Put(buffer, 3);
     CircularBuffer_Get(buffer);
     CircularBuffer_Get(buffer);
    CircularBuffer_Get(buffer);
    CircularBuffer_Put(buffer, 5);
    LONGS_EQUAL(5, CircularBuffer_Get(buffer));
    CHECK(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
    
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Retrospective:
 * Did Wrap around test pass without change? Did you allocate
 * your internal integer array just the right size, or leave it
 * statically defined and make it really big?
 * You can write code that passes tests and is wrong, but
 * that's not the goal.  The goal is correct working code.
 */

/*
 * Retrospective:
 * You should not have any production code that is worried about
 * a Getting from an empty buffer, or Putting to a full buffer.
 */

/*
 * Discussion with James about next test:
 * Hmmm, where are the indexes wrapping to a full scenario?
 * Will empty and full look the same (if you are using just
 * the indexes for deterining empty and full)
 */
TEST(CircularBuffer, is_not_empty_when_filled_to_capacity)
{ 
    CircularBuffer * buffer = CircularBuffer_Create(3,0);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Put(buffer, 3); 
    CHECK_FALSE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}

/*
 * Discussion with James about next test:
 * What should we do when putting to a full queue?
 * Maybe we should return FALSE.
 * Also, it should not damage the queue contents
 * or change its state.
 */

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

TEST(CircularBuffer, put_to_full_fails)
{
 CircularBuffer * buffer = CircularBuffer_Create(3,0);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Put(buffer, 3);
    CircularBuffer_Put(buffer, 4);
    CircularBuffer_Put(buffer, 8);
    CircularBuffer_Destroy(buffer);
}
#ifdef Move_this_line_down_one_test_to_simulate_james_writing_the_test
/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */


/*
 * Discussion with James about next test:
 * What should happen when putting to a full queue?
 * It should not damage the queue contents or state.
 */

TEST(CircularBuffer, put_to_full_does_not_damage_contents)
{
    //Write the test
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

/*
 * Retrospective:
 * I'm not totally happy with put to full. Maybe we need to
 * talk to the other users of this.  Maybe we should keep the
 * latest value and toss the earlier one.  It might be nice
 * to see an error on the console or in a log. Maybe we'll do 
 * something about that later.
 */

/*
 * Retrospective:
 * Do you have duplicate index wrapping code in your production
 * code?  You should refactor it into a helper function.
 */

/*
 * Discussion with James about next test:
 * What should happen when we get from an empty queue?
 * We have to return something.  Are all values valid? We could
 * have an invalid value. Maybe we should return the last value
 * again?  Should you add an pointer to an error to populate?
 *
 * After deliberation, we decided to add a default value to
 * Create, so the user of the CircularBuffer could control
 * their own default return result.
 *
 * How do you want to provide the default value?
 * Putting it into Create seems like a good choice.
 */
TEST(CircularBuffer, get_from_empty_returns_default_value)
{
}

/* PLEASE DELETE PREVIOUS COMMENTS AS YOU GET TESTS TO PASS */

#endif

/* Congratulations!
 *
 * Look for test refactoring opportunities.
 *
 * Did you get rid of all those unneeded comments?
 *
 * Do it again next week except without my tests
 * to guide you
 */

