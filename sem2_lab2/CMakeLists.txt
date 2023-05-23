cmake_minimum_required(VERSION 3.23)

project(sem2_lab2)

set(CMAKE_CXX_STANDARD 17)

set(MAINSOURCE
    main.cpp
    )

set(INCLUDE "")

set(MAINHEADERS
    ${INCLUDE}sequence.h
    ${INCLUDE}array_sequence.h
    ${INCLUDE}list_sequence.h
    ${INCLUDE}array.h
    ${INCLUDE}list.h
    ${INCLUDE}queue.h
    )

add_executable(${PROJECT_NAME} ${MAINSOURCE} ${MAINHEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})

set(TEST "test")

set(TESTSOURCE
    seq_test.cpp)

add_executable(${TEST} ${TESTSOURCE} ${MAINHEADERS})
target_link_directories(${TEST} PRIVATE ${INCLUDE})

set(QUEUE "queue")

add_executable(${QUEUE} main_queue.cpp ${MAINHEADERS})
target_link_directories(${TEST} PRIVATE ${INCLUDE})

#add_executable(main main.cpp array_sequence.h list_sequence.h)
#add_executable(test seq_test.cpp array_sequence.h list_sequence.h)
#add_executable(queue main_queue.cpp queue.h list.h list_sequence.h)