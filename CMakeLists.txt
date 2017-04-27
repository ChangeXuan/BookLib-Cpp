cmake_minimum_required(VERSION 3.7)
project(BookLib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Book.h TechnicalBook.h GeneralKnowledgeBook.h AllBooks.h operationBook.h)
add_executable(BookLib ${SOURCE_FILES})