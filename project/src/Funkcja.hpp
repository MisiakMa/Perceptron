#ifndef __COMMON_HPP
#define __COMMON_HPP

#include <cstdio>
#include <cctype>
#include <cmath>


#define SCNnum_t "lf"
#define PRInum_t "f"

inline double logsig(double const &a)
{
	return 1. / (1. + exp(-a));
}

inline void ignoreWhities(FILE * const &f)
{
	int c;
	while(isspace(c = fgetc(f)) && c != EOF);
}

#endif
