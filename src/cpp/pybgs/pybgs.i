%module pybgs
%{
#define SWIG_FILE_WITH_INIT
#include "pybgs/pybgs.h"
%}

%include "numpy.i"

%init %{
    import_array();
%}

%apply (int DIM1, int DIM2, int DIM3, unsigned char* IN_ARRAY3)
        {(int IN_i, int IN_j, int IN_k, unsigned char* IN)}
%apply (int* DIM1, int* DIM2, int* DIM3, unsigned char** ARGOUTVIEWM_ARRAY3)
        {(int* OUT_i, int* OUT_j, int* OUT_k, unsigned char** OUT)}

%apply (int DIM1, int DIM2, int DIM3, double* IN_ARRAY3)
        {(int IN_i, int IN_j, int IN_k, double* IN)}
%apply (int* DIM1, int* DIM2, int* DIM3, double** ARGOUTVIEWM_ARRAY3)
        {(int* OUT_i, int* OUT_j, int* OUT_k, double** OUT)}

%apply (int DIM1, int DIM2, int DIM3, unsigned short* IN_ARRAY3)
        {(int IN_i, int IN_j, int IN_k, unsigned short* IN)}
%apply (int* DIM1, int* DIM2, int* DIM3, unsigned short** ARGOUTVIEWM_ARRAY3)
        {(int* OUT_i, int* OUT_j, int* OUT_k, unsigned short** OUT)}

%include "std_string.i"
%include "typemaps.i"
%include "std_list.i"

%include "common.i"

%include "pybgs.h"
%template(StringList) std::list<std::string>;

%template(BGSDoubleC3) BGSBase<double, 3, CV_64FC3, CV_64FC1>;
%template(BGSFloatC3) BGSBase<float, 3, CV_32FC3, CV_32FC1>;
%template(BGSUInt16C3) BGSBase<unsigned short, 3, CV_16UC3, CV_16UC1>;
%template(BGSUCharC3) BGSBase<unsigned char, 3, CV_8UC3, CV_8UC1>;