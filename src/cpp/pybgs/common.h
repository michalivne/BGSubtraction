/*
 * Common functions and classes.
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#include <boost/format.hpp>

#include <string>
#include <map>

#define PRINT(S) {std::cout<<S<<std::endl;}
#define FORMAT_STR(S, ARGS) ((boost::format(S) % ARGS).str())

template < class T >
inline void SWAP(T& a, T&b) { T t = a; a = b; b = t; };


#endif //__COMMON_H__
