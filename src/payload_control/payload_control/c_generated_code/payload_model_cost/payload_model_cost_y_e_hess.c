/* This file was automatically generated by CasADi 3.6.7.
 *  It consists of: 
 *   1) content generated by CasADi runtime: not copyrighted
 *   2) template code copied from CasADi source: permissively licensed (MIT-0)
 *   3) user code: owned by the user
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) payload_model_cost_y_e_hess_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fabs CASADI_PREFIX(fabs)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_fabs(casadi_real x) {
/* Pre-c99 compatibility */
#if __STDC_VERSION__ < 199901L
  return x>0 ? x : -x;
#else
  return fabs(x);
#endif
}

casadi_real casadi_sq(casadi_real x) { return x*x;}

static const casadi_int casadi_s0[17] = {13, 1, 0, 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
static const casadi_int casadi_s1[3] = {0, 0, 0};
static const casadi_int casadi_s2[16] = {12, 1, 0, 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
static const casadi_int casadi_s3[32] = {13, 13, 0, 0, 0, 0, 4, 8, 12, 16, 16, 16, 16, 16, 16, 16, 3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6};

/* payload_model_cost_y_e_hess:(i0[13],i1[],i2[],i3[12],i4[],i5[])->(o0[13x13,16nz]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a4, a5, a6, a7, a8, a9;
  a0=1.;
  a1=2.;
  a2=arg[0]? arg[0][3] : 0;
  a3=arg[0]? arg[0][5] : 0;
  a4=(a2*a3);
  a5=arg[0]? arg[0][6] : 0;
  a6=arg[0]? arg[0][4] : 0;
  a7=(a5*a6);
  a4=(a4-a7);
  a4=(a1*a4);
  a7=casadi_fabs(a4);
  a7=(a0<=a7);
  a7=(!a7);
  a8=arg[3]? arg[3][4] : 0;
  a9=casadi_sq(a4);
  a9=(a0-a9);
  a9=sqrt(a9);
  a8=(a8/a9);
  a10=(a8/a9);
  a4=(a4+a4);
  a11=(a1*a3);
  a11=(a4*a11);
  a9=(a9+a9);
  a11=(a11/a9);
  a11=(a10*a11);
  a11=(a1*a11);
  a11=(a3*a11);
  a11=(a7?a11:0);
  a12=arg[3]? arg[3][5] : 0;
  a13=casadi_sq(a3);
  a14=casadi_sq(a5);
  a13=(a13+a14);
  a13=(a1*a13);
  a13=(a0-a13);
  a14=(a2*a5);
  a15=(a6*a3);
  a14=(a14+a15);
  a14=(a1*a14);
  a15=casadi_sq(a14);
  a16=casadi_sq(a13);
  a15=(a15+a16);
  a16=(a13/a15);
  a17=(a16/a15);
  a18=(a14+a14);
  a19=(a1*a5);
  a19=(a18*a19);
  a19=(a17*a19);
  a19=(a12*a19);
  a19=(a1*a19);
  a19=(a5*a19);
  a11=(a11-a19);
  a19=arg[3]? arg[3][3] : 0;
  a20=casadi_sq(a6);
  a21=casadi_sq(a3);
  a20=(a20+a21);
  a20=(a1*a20);
  a0=(a0-a20);
  a20=(a2*a6);
  a21=(a3*a5);
  a20=(a20+a21);
  a20=(a1*a20);
  a21=casadi_sq(a20);
  a22=casadi_sq(a0);
  a21=(a21+a22);
  a22=(a0/a21);
  a23=(a22/a21);
  a24=(a20+a20);
  a25=(a1*a6);
  a25=(a24*a25);
  a25=(a23*a25);
  a25=(a19*a25);
  a25=(a1*a25);
  a25=(a6*a25);
  a11=(a11-a25);
  if (res[0]!=0) res[0][0]=a11;
  a11=(a1*a5);
  a11=(a4*a11);
  a11=(a11/a9);
  a11=(a10*a11);
  a11=(a1*a11);
  a25=(a3*a11);
  a25=(-a25);
  a25=(a7?a25:0);
  a26=(a1*a3);
  a26=(a18*a26);
  a26=(a17*a26);
  a26=(a12*a26);
  a26=(a1*a26);
  a27=(a5*a26);
  a25=(a25-a27);
  a22=(a22*a19);
  a22=(a1*a22);
  a27=(a6+a6);
  a27=(a1*a27);
  a28=(a27/a21);
  a29=(a1*a2);
  a30=(a24*a29);
  a0=(a0+a0);
  a27=(a0*a27);
  a30=(a30-a27);
  a27=(a23*a30);
  a28=(a28+a27);
  a28=(a19*a28);
  a28=(a1*a28);
  a27=(a6*a28);
  a27=(a22-a27);
  a25=(a25+a27);
  if (res[0]!=0) res[0][1]=a25;
  a8=(a1*a8);
  a27=(a1*a2);
  a27=(a4*a27);
  a27=(a27/a9);
  a27=(a10*a27);
  a27=(a1*a27);
  a31=(a3*a27);
  a31=(a8+a31);
  a31=(a7?a31:0);
  a32=(a3+a3);
  a32=(a1*a32);
  a33=(a32/a15);
  a34=(a1*a6);
  a35=(a18*a34);
  a13=(a13+a13);
  a32=(a13*a32);
  a35=(a35-a32);
  a32=(a17*a35);
  a33=(a33+a32);
  a33=(a12*a33);
  a33=(a1*a33);
  a32=(a5*a33);
  a31=(a31-a32);
  a32=(a3+a3);
  a32=(a1*a32);
  a36=(a32/a21);
  a37=(a1*a5);
  a38=(a24*a37);
  a0=(a0*a32);
  a38=(a38-a0);
  a0=(a23*a38);
  a36=(a36+a0);
  a36=(a19*a36);
  a36=(a1*a36);
  a0=(a6*a36);
  a31=(a31-a0);
  if (res[0]!=0) res[0][2]=a31;
  a16=(a16*a12);
  a16=(a1*a16);
  a0=(a5+a5);
  a0=(a1*a0);
  a32=(a0/a15);
  a39=(a1*a2);
  a18=(a18*a39);
  a13=(a13*a0);
  a18=(a18-a13);
  a17=(a17*a18);
  a32=(a32+a17);
  a32=(a12*a32);
  a32=(a1*a32);
  a17=(a5*a32);
  a17=(a16-a17);
  a13=(a1*a6);
  a4=(a4*a13);
  a4=(a4/a9);
  a10=(a10*a4);
  a10=(a1*a10);
  a4=(a3*a10);
  a4=(-a4);
  a4=(a7?a4:0);
  a17=(a17+a4);
  a4=(a1*a3);
  a24=(a24*a4);
  a23=(a23*a24);
  a23=(a19*a23);
  a23=(a1*a23);
  a9=(a6*a23);
  a17=(a17-a9);
  if (res[0]!=0) res[0][3]=a17;
  if (res[0]!=0) res[0][4]=a25;
  a11=(a5*a11);
  a11=(a7?a11:0);
  a26=(a3*a26);
  a11=(a11-a26);
  a20=(a20/a21);
  a26=(a20*a19);
  a26=(a1*a26);
  a25=(a1*a26);
  a9=(a6+a6);
  a29=(a29/a21);
  a20=(a20/a21);
  a30=(a20*a30);
  a29=(a29-a30);
  a29=(a19*a29);
  a29=(a1*a29);
  a29=(a9*a29);
  a25=(a25+a29);
  a11=(a11+a25);
  a28=(a2*a28);
  a11=(a11-a28);
  if (res[0]!=0) res[0][5]=a11;
  a11=(a3*a33);
  a16=(a16-a11);
  a11=(a5*a27);
  a11=(-a11);
  a11=(a7?a11:0);
  a16=(a16+a11);
  a37=(a37/a21);
  a38=(a20*a38);
  a37=(a37-a38);
  a37=(a19*a37);
  a37=(a1*a37);
  a38=(a9*a37);
  a16=(a16+a38);
  a38=(a2*a36);
  a16=(a16-a38);
  if (res[0]!=0) res[0][6]=a16;
  a38=(a5*a10);
  a8=(a8-a38);
  a8=(-a8);
  a8=(a7?a8:0);
  a38=(a3*a32);
  a8=(a8-a38);
  a4=(a4/a21);
  a20=(a20*a24);
  a4=(a4-a20);
  a19=(a19*a4);
  a19=(a1*a19);
  a9=(a9*a19);
  a8=(a8+a9);
  a9=(a2*a23);
  a8=(a8-a9);
  if (res[0]!=0) res[0][7]=a8;
  if (res[0]!=0) res[0][8]=a31;
  if (res[0]!=0) res[0][9]=a16;
  a14=(a14/a15);
  a16=(a14*a12);
  a16=(a1*a16);
  a31=(a1*a16);
  a9=(a3+a3);
  a34=(a34/a15);
  a14=(a14/a15);
  a35=(a14*a35);
  a34=(a34-a35);
  a34=(a12*a34);
  a34=(a1*a34);
  a34=(a9*a34);
  a31=(a31+a34);
  a33=(a6*a33);
  a31=(a31-a33);
  a27=(a2*a27);
  a27=(a7?a27:0);
  a31=(a31+a27);
  a26=(a1*a26);
  a27=(a3+a3);
  a37=(a27*a37);
  a26=(a26+a37);
  a31=(a31+a26);
  a36=(a5*a36);
  a31=(a31-a36);
  if (res[0]!=0) res[0][10]=a31;
  a39=(a39/a15);
  a14=(a14*a18);
  a39=(a39-a14);
  a12=(a12*a39);
  a12=(a1*a12);
  a9=(a9*a12);
  a39=(a6*a32);
  a9=(a9-a39);
  a39=(a2*a10);
  a39=(-a39);
  a39=(a7?a39:0);
  a9=(a9+a39);
  a27=(a27*a19);
  a9=(a9+a27);
  a27=(a5*a23);
  a22=(a22-a27);
  a9=(a9+a22);
  if (res[0]!=0) res[0][11]=a9;
  if (res[0]!=0) res[0][12]=a17;
  if (res[0]!=0) res[0][13]=a8;
  if (res[0]!=0) res[0][14]=a9;
  a1=(a1*a16);
  a5=(a5+a5);
  a5=(a5*a12);
  a1=(a1+a5);
  a2=(a2*a32);
  a1=(a1-a2);
  a6=(a6*a10);
  a7=(a7?a6:0);
  a1=(a1+a7);
  a3=(a3*a23);
  a1=(a1-a3);
  if (res[0]!=0) res[0][15]=a1;
  return 0;
}

CASADI_SYMBOL_EXPORT int payload_model_cost_y_e_hess(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int payload_model_cost_y_e_hess_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int payload_model_cost_y_e_hess_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void payload_model_cost_y_e_hess_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int payload_model_cost_y_e_hess_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void payload_model_cost_y_e_hess_release(int mem) {
}

CASADI_SYMBOL_EXPORT void payload_model_cost_y_e_hess_incref(void) {
}

CASADI_SYMBOL_EXPORT void payload_model_cost_y_e_hess_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int payload_model_cost_y_e_hess_n_in(void) { return 6;}

CASADI_SYMBOL_EXPORT casadi_int payload_model_cost_y_e_hess_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real payload_model_cost_y_e_hess_default_in(casadi_int i) {
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* payload_model_cost_y_e_hess_name_in(casadi_int i) {
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    case 4: return "i4";
    case 5: return "i5";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* payload_model_cost_y_e_hess_name_out(casadi_int i) {
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* payload_model_cost_y_e_hess_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    case 2: return casadi_s1;
    case 3: return casadi_s2;
    case 4: return casadi_s1;
    case 5: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* payload_model_cost_y_e_hess_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int payload_model_cost_y_e_hess_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 6;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

CASADI_SYMBOL_EXPORT int payload_model_cost_y_e_hess_work_bytes(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 6*sizeof(const casadi_real*);
  if (sz_res) *sz_res = 1*sizeof(casadi_real*);
  if (sz_iw) *sz_iw = 0*sizeof(casadi_int);
  if (sz_w) *sz_w = 0*sizeof(casadi_real);
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif