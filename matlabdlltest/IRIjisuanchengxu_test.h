//
// MATLAB Compiler: 6.2 (R2016a)
// Date: Mon Jul 26 21:32:26 2021
// Arguments: "-B" "macro_default" "-W" "cpplib:IRIjisuanchengxu_test" "-T"
// "link:lib" "-d"
// "D:\work\20210624project_roaddetect\info\平整度、车辙、构造深度计算程序\01
// 平整度指数IRI计算程序\IRIjisuanchengxu_test\for_testing" "-v"
// "D:\work\20210624project_roaddetect\info\平整度、车辙、构造深度计算程序\01
// 平整度指数IRI计算程序\IRIjisuanchengxu_test.m" 
//

#ifndef __IRIjisuanchengxu_test_h
#define __IRIjisuanchengxu_test_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_IRIjisuanchengxu_test
#define PUBLIC_IRIjisuanchengxu_test_C_API __global
#else
#define PUBLIC_IRIjisuanchengxu_test_C_API /* No import statement needed. */
#endif

#define LIB_IRIjisuanchengxu_test_C_API PUBLIC_IRIjisuanchengxu_test_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_IRIjisuanchengxu_test
#define PUBLIC_IRIjisuanchengxu_test_C_API __declspec(dllexport)
#else
#define PUBLIC_IRIjisuanchengxu_test_C_API __declspec(dllimport)
#endif

#define LIB_IRIjisuanchengxu_test_C_API PUBLIC_IRIjisuanchengxu_test_C_API


#else

#define LIB_IRIjisuanchengxu_test_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_IRIjisuanchengxu_test_C_API 
#define LIB_IRIjisuanchengxu_test_C_API /* No special import/export declaration */
#endif

extern LIB_IRIjisuanchengxu_test_C_API 
bool MW_CALL_CONV IRIjisuanchengxu_testInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_IRIjisuanchengxu_test_C_API 
bool MW_CALL_CONV IRIjisuanchengxu_testInitialize(void);

extern LIB_IRIjisuanchengxu_test_C_API 
void MW_CALL_CONV IRIjisuanchengxu_testTerminate(void);



extern LIB_IRIjisuanchengxu_test_C_API 
void MW_CALL_CONV IRIjisuanchengxu_testPrintStackTrace(void);

extern LIB_IRIjisuanchengxu_test_C_API 
bool MW_CALL_CONV mlxIRIjisuanchengxu_test(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                           *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_IRIjisuanchengxu_test
#define PUBLIC_IRIjisuanchengxu_test_CPP_API __declspec(dllexport)
#else
#define PUBLIC_IRIjisuanchengxu_test_CPP_API __declspec(dllimport)
#endif

#define LIB_IRIjisuanchengxu_test_CPP_API PUBLIC_IRIjisuanchengxu_test_CPP_API

#else

#if !defined(LIB_IRIjisuanchengxu_test_CPP_API)
#if defined(LIB_IRIjisuanchengxu_test_C_API)
#define LIB_IRIjisuanchengxu_test_CPP_API LIB_IRIjisuanchengxu_test_C_API
#else
#define LIB_IRIjisuanchengxu_test_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_IRIjisuanchengxu_test_CPP_API void MW_CALL_CONV IRIjisuanchengxu_test(int nargout, mwArray& IRI_result);

#endif
#endif
