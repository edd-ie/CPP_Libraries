cmake_minimum_required(VERSION 3.28)
project(Learn)

set(CMAKE_CXX_STANDARD 23)

add_executable(Learn main.cpp
        CurrentTime.h
        LoanPayment.h
        LinkedList.h
        BinaryTree.h)
