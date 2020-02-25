#pragma once

#include <memory>
#include <iostream>
#include <array>
#include "Graphics.hpp"

// TEMPLATE :>)

//unique_ptr is a smart pointer that owns and manages another object 
    //through a pointer and disposes of that object when 
    //the unique_ptr goes out of scope.
    //So it blocks not being used, deleted them. 
template <typename T> 
using UPtr = std::unique_ptr<T>; 

template <typename T, int numRows, int numColumns> 
using Array2D = std::array<std::array<T,numColumns>,numRows>; 

template <typename T, typename... Args>
UPtr<T> makeUPtr(Args&&... args);

// This is reall helpfull to debug and see what is wrong 
// I need to thanks StackOVerflow for teaching me this LOL

#ifdef DEBUG
    #define DBGMSG(msg) \
        std::cout << "DBG: " << __FILE__ << "(" << __LINE__ << ") " \
        << msg << std::endl
#else
    #define DBGMSG(msg)
#endif

#include "Templates.inl"
