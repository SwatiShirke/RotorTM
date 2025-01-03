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
  #define CASADI_PREFIX(ID) payload_model_cost_ext_cost_fun_jac_hess_ ## ID
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
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)
#define casadi_s6 CASADI_PREFIX(s6)
#define casadi_s7 CASADI_PREFIX(s7)
#define casadi_sign CASADI_PREFIX(sign)
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

casadi_real casadi_sq(casadi_real x) { return x*x;}

casadi_real casadi_fabs(casadi_real x) {
/* Pre-c99 compatibility */
#if __STDC_VERSION__ < 199901L
  return x>0 ? x : -x;
#else
  return fabs(x);
#endif
}

casadi_real casadi_sign(casadi_real x) { return x<0 ? -1 : x>0 ? 1 : x;}

static const casadi_int casadi_s0[17] = {13, 1, 0, 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
static const casadi_int casadi_s1[13] = {9, 1, 0, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8};
static const casadi_int casadi_s2[3] = {0, 0, 0};
static const casadi_int casadi_s3[25] = {21, 1, 0, 21, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
static const casadi_int casadi_s4[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s5[26] = {22, 1, 0, 22, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
static const casadi_int casadi_s6[56] = {22, 22, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16, 20, 24, 28, 29, 30, 31, 31, 31, 31, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 12, 13, 14, 15, 12, 13, 14, 15, 12, 13, 14, 15, 16, 17, 18};
static const casadi_int casadi_s7[25] = {0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* payload_model_cost_ext_cost_fun_jac_hess:(i0[13],i1[9],i2[],i3[21])->(o0,o1[22],o2[22x22,31nz],o3[],o4[0x22]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a4, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a5, a50, a51, a52, a53, a54, a55, a56, a57, a6, a7, a8, a9;
  a0=500.;
  a1=arg[0]? arg[0][0] : 0;
  a2=arg[3]? arg[3][0] : 0;
  a1=(a1-a2);
  a2=casadi_sq(a1);
  a2=(a0*a2);
  a3=arg[0]? arg[0][1] : 0;
  a4=arg[3]? arg[3][1] : 0;
  a3=(a3-a4);
  a4=casadi_sq(a3);
  a4=(a0*a4);
  a2=(a2+a4);
  a4=arg[0]? arg[0][2] : 0;
  a5=arg[3]? arg[3][2] : 0;
  a4=(a4-a5);
  a5=casadi_sq(a4);
  a5=(a0*a5);
  a2=(a2+a5);
  a5=1.0000000000000000e-04;
  a6=2.;
  a7=arg[0]? arg[0][3] : 0;
  a8=arg[0]? arg[0][4] : 0;
  a9=(a7*a8);
  a10=arg[0]? arg[0][5] : 0;
  a11=arg[0]? arg[0][6] : 0;
  a12=(a10*a11);
  a9=(a9+a12);
  a9=(a6*a9);
  a12=1.;
  a13=casadi_sq(a8);
  a14=casadi_sq(a10);
  a13=(a13+a14);
  a13=(a6*a13);
  a13=(a12-a13);
  a14=atan2(a9,a13);
  a15=arg[3]? arg[3][3] : 0;
  a14=(a14-a15);
  a15=casadi_sq(a14);
  a15=(a5*a15);
  a16=(a7*a10);
  a17=(a11*a8);
  a16=(a16-a17);
  a16=(a6*a16);
  a17=casadi_fabs(a16);
  a17=(a12<=a17);
  a18=3.1415926535897931e+00;
  a19=casadi_sign(a16);
  a18=(a18*a19);
  a18=(a18/a6);
  a18=(a17?a18:0);
  a17=(!a17);
  a19=asin(a16);
  a19=(a17?a19:0);
  a18=(a18+a19);
  a19=arg[3]? arg[3][4] : 0;
  a18=(a18-a19);
  a19=casadi_sq(a18);
  a19=(a5*a19);
  a15=(a15+a19);
  a19=100.;
  a20=(a7*a11);
  a21=(a8*a10);
  a20=(a20+a21);
  a20=(a6*a20);
  a21=casadi_sq(a10);
  a22=casadi_sq(a11);
  a21=(a21+a22);
  a21=(a6*a21);
  a21=(a12-a21);
  a22=atan2(a20,a21);
  a23=arg[3]? arg[3][5] : 0;
  a22=(a22-a23);
  a23=casadi_sq(a22);
  a23=(a19*a23);
  a15=(a15+a23);
  a2=(a2+a15);
  a15=10.;
  a23=arg[0]? arg[0][7] : 0;
  a24=arg[3]? arg[3][6] : 0;
  a23=(a23-a24);
  a24=casadi_sq(a23);
  a24=(a15*a24);
  a25=arg[0]? arg[0][8] : 0;
  a26=arg[3]? arg[3][7] : 0;
  a25=(a25-a26);
  a26=casadi_sq(a25);
  a26=(a15*a26);
  a24=(a24+a26);
  a26=arg[0]? arg[0][9] : 0;
  a27=arg[3]? arg[3][8] : 0;
  a26=(a26-a27);
  a27=casadi_sq(a26);
  a27=(a15*a27);
  a24=(a24+a27);
  a2=(a2+a24);
  a24=1.0000000000000000e-02;
  a27=arg[1]? arg[1][0] : 0;
  a28=arg[3]? arg[3][12] : 0;
  a27=(a27-a28);
  a28=casadi_sq(a27);
  a28=(a24*a28);
  a29=arg[1]? arg[1][1] : 0;
  a30=arg[3]? arg[3][13] : 0;
  a29=(a29-a30);
  a30=casadi_sq(a29);
  a30=(a24*a30);
  a28=(a28+a30);
  a30=arg[1]? arg[1][2] : 0;
  a31=arg[3]? arg[3][14] : 0;
  a30=(a30-a31);
  a31=casadi_sq(a30);
  a28=(a28+a31);
  a31=arg[1]? arg[1][3] : 0;
  a32=arg[3]? arg[3][15] : 0;
  a31=(a31-a32);
  a32=casadi_sq(a31);
  a32=(a24*a32);
  a28=(a28+a32);
  a32=arg[1]? arg[1][4] : 0;
  a33=arg[3]? arg[3][16] : 0;
  a32=(a32-a33);
  a33=casadi_sq(a32);
  a33=(a24*a33);
  a28=(a28+a33);
  a33=arg[1]? arg[1][5] : 0;
  a34=arg[3]? arg[3][17] : 0;
  a33=(a33-a34);
  a34=casadi_sq(a33);
  a34=(a24*a34);
  a28=(a28+a34);
  a34=arg[1]? arg[1][6] : 0;
  a35=arg[3]? arg[3][18] : 0;
  a34=(a34-a35);
  a35=casadi_sq(a34);
  a35=(a24*a35);
  a28=(a28+a35);
  a35=arg[1]? arg[1][7] : 0;
  a36=arg[3]? arg[3][19] : 0;
  a35=(a35-a36);
  a36=casadi_sq(a35);
  a36=(a24*a36);
  a28=(a28+a36);
  a36=arg[1]? arg[1][8] : 0;
  a37=arg[3]? arg[3][20] : 0;
  a36=(a36-a37);
  a37=casadi_sq(a36);
  a37=(a24*a37);
  a28=(a28+a37);
  a2=(a2+a28);
  if (res[0]!=0) res[0][0]=a2;
  a27=(a27+a27);
  a27=(a24*a27);
  if (res[1]!=0) res[1][0]=a27;
  a29=(a29+a29);
  a29=(a24*a29);
  if (res[1]!=0) res[1][1]=a29;
  a30=(a30+a30);
  if (res[1]!=0) res[1][2]=a30;
  a31=(a31+a31);
  a31=(a24*a31);
  if (res[1]!=0) res[1][3]=a31;
  a32=(a32+a32);
  a32=(a24*a32);
  if (res[1]!=0) res[1][4]=a32;
  a33=(a33+a33);
  a33=(a24*a33);
  if (res[1]!=0) res[1][5]=a33;
  a34=(a34+a34);
  a34=(a24*a34);
  if (res[1]!=0) res[1][6]=a34;
  a35=(a35+a35);
  a35=(a24*a35);
  if (res[1]!=0) res[1][7]=a35;
  a36=(a36+a36);
  a24=(a24*a36);
  if (res[1]!=0) res[1][8]=a24;
  a1=(a1+a1);
  a1=(a0*a1);
  if (res[1]!=0) res[1][9]=a1;
  a3=(a3+a3);
  a3=(a0*a3);
  if (res[1]!=0) res[1][10]=a3;
  a4=(a4+a4);
  a0=(a0*a4);
  if (res[1]!=0) res[1][11]=a0;
  a0=casadi_sq(a20);
  a4=casadi_sq(a21);
  a0=(a0+a4);
  a4=(a21/a0);
  a22=(a22+a22);
  a22=(a19*a22);
  a3=(a4*a22);
  a3=(a6*a3);
  a1=(a11*a3);
  a18=(a18+a18);
  a18=(a5*a18);
  a24=casadi_sq(a16);
  a24=(a12-a24);
  a24=sqrt(a24);
  a18=(a18/a24);
  a36=(a6*a18);
  a35=(a10*a36);
  a35=(a17?a35:0);
  a1=(a1+a35);
  a35=casadi_sq(a9);
  a34=casadi_sq(a13);
  a35=(a35+a34);
  a34=(a13/a35);
  a14=(a14+a14);
  a14=(a5*a14);
  a33=(a34*a14);
  a33=(a6*a33);
  a32=(a8*a33);
  a1=(a1+a32);
  if (res[1]!=0) res[1][12]=a1;
  a1=(a10*a3);
  a32=(a11*a36);
  a32=(-a32);
  a32=(a17?a32:0);
  a1=(a1+a32);
  a32=(a8+a8);
  a31=(a9/a35);
  a30=(a31*a14);
  a30=(a6*a30);
  a29=(a32*a30);
  a1=(a1+a29);
  a29=(a7*a33);
  a1=(a1+a29);
  if (res[1]!=0) res[1][13]=a1;
  a1=(a10+a10);
  a29=(a20/a0);
  a27=(a29*a22);
  a27=(a6*a27);
  a2=(a1*a27);
  a28=(a8*a3);
  a2=(a2+a28);
  a28=(a7*a36);
  a28=(a17?a28:0);
  a2=(a2+a28);
  a28=(a10+a10);
  a37=(a28*a30);
  a2=(a2+a37);
  a37=(a11*a33);
  a2=(a2+a37);
  if (res[1]!=0) res[1][14]=a2;
  a2=(a11+a11);
  a37=(a2*a27);
  a38=(a7*a3);
  a37=(a37+a38);
  a38=(a8*a36);
  a38=(-a38);
  a38=(a17?a38:0);
  a37=(a37+a38);
  a38=(a10*a33);
  a37=(a37+a38);
  if (res[1]!=0) res[1][15]=a37;
  a23=(a23+a23);
  a23=(a15*a23);
  if (res[1]!=0) res[1][16]=a23;
  a25=(a25+a25);
  a25=(a15*a25);
  if (res[1]!=0) res[1][17]=a25;
  a26=(a26+a26);
  a15=(a15*a26);
  if (res[1]!=0) res[1][18]=a15;
  a15=0.;
  if (res[1]!=0) res[1][19]=a15;
  if (res[1]!=0) res[1][20]=a15;
  if (res[1]!=0) res[1][21]=a15;
  a15=2.0000000000000000e-02;
  if (res[2]!=0) res[2][0]=a15;
  if (res[2]!=0) res[2][1]=a15;
  if (res[2]!=0) res[2][2]=a6;
  if (res[2]!=0) res[2][3]=a15;
  if (res[2]!=0) res[2][4]=a15;
  if (res[2]!=0) res[2][5]=a15;
  if (res[2]!=0) res[2][6]=a15;
  if (res[2]!=0) res[2][7]=a15;
  if (res[2]!=0) res[2][8]=a15;
  a15=1000.;
  if (res[2]!=0) res[2][9]=a15;
  if (res[2]!=0) res[2][10]=a15;
  if (res[2]!=0) res[2][11]=a15;
  a15=casadi_sq(a20);
  a26=casadi_sq(a21);
  a15=(a15+a26);
  a26=(a21/a15);
  a25=(a6*a11);
  a23=(a26*a25);
  a23=(a23+a23);
  a23=(a19*a23);
  a23=(a4*a23);
  a37=(a4/a0);
  a38=(a20+a20);
  a25=(a38*a25);
  a25=(a37*a25);
  a25=(a22*a25);
  a23=(a23-a25);
  a23=(a6*a23);
  a23=(a11*a23);
  a25=(a6*a10);
  a39=casadi_sq(a16);
  a12=(a12-a39);
  a12=sqrt(a12);
  a39=(a25/a12);
  a39=(a39+a39);
  a39=(a5*a39);
  a39=(a39/a24);
  a39=(a17?a39:0);
  a18=(a18/a24);
  a16=(a16+a16);
  a25=(a16*a25);
  a40=(a24+a24);
  a25=(a25/a40);
  a25=(a18*a25);
  a39=(a39+a25);
  a39=(a6*a39);
  a39=(a10*a39);
  a39=(a17?a39:0);
  a23=(a23+a39);
  a39=casadi_sq(a9);
  a25=casadi_sq(a13);
  a39=(a39+a25);
  a25=(a13/a39);
  a41=(a6*a8);
  a42=(a25*a41);
  a42=(a42+a42);
  a42=(a5*a42);
  a42=(a34*a42);
  a43=(a34/a35);
  a44=(a9+a9);
  a41=(a44*a41);
  a41=(a43*a41);
  a41=(a14*a41);
  a42=(a42-a41);
  a42=(a6*a42);
  a42=(a8*a42);
  a23=(a23+a42);
  if (res[2]!=0) res[2][12]=a23;
  a23=(a6*a10);
  a42=(a26*a23);
  a42=(a42+a42);
  a42=(a19*a42);
  a42=(a4*a42);
  a23=(a38*a23);
  a23=(a37*a23);
  a23=(a22*a23);
  a42=(a42-a23);
  a42=(a6*a42);
  a23=(a11*a42);
  a41=(a6*a11);
  a45=(a41/a12);
  a45=(a45+a45);
  a45=(a5*a45);
  a45=(a45/a24);
  a45=(-a45);
  a45=(a17?a45:0);
  a41=(a16*a41);
  a41=(a41/a40);
  a41=(a18*a41);
  a45=(a45-a41);
  a45=(a6*a45);
  a41=(a10*a45);
  a41=(a17?a41:0);
  a23=(a23+a41);
  a41=(a6*a7);
  a46=(a25*a41);
  a9=(a9/a39);
  a39=(a8+a8);
  a39=(a6*a39);
  a47=(a9*a39);
  a46=(a46+a47);
  a46=(a46+a46);
  a46=(a5*a46);
  a47=(a34*a46);
  a48=(a39/a35);
  a49=(a44*a41);
  a13=(a13+a13);
  a39=(a13*a39);
  a49=(a49-a39);
  a39=(a43*a49);
  a48=(a48+a39);
  a48=(a14*a48);
  a47=(a47-a48);
  a47=(a6*a47);
  a48=(a8*a47);
  a48=(a33+a48);
  a23=(a23+a48);
  if (res[2]!=0) res[2][13]=a23;
  a48=(a6*a8);
  a39=(a26*a48);
  a20=(a20/a15);
  a15=(a10+a10);
  a15=(a6*a15);
  a50=(a20*a15);
  a39=(a39+a50);
  a39=(a39+a39);
  a39=(a19*a39);
  a50=(a4*a39);
  a51=(a15/a0);
  a52=(a38*a48);
  a21=(a21+a21);
  a15=(a21*a15);
  a52=(a52-a15);
  a15=(a37*a52);
  a51=(a51+a15);
  a51=(a22*a51);
  a50=(a50-a51);
  a50=(a6*a50);
  a51=(a11*a50);
  a15=(a6*a7);
  a53=(a15/a12);
  a53=(a53+a53);
  a53=(a5*a53);
  a53=(a53/a24);
  a53=(a17?a53:0);
  a15=(a16*a15);
  a15=(a15/a40);
  a15=(a18*a15);
  a53=(a53+a15);
  a53=(a6*a53);
  a15=(a10*a53);
  a15=(a36+a15);
  a15=(a17?a15:0);
  a51=(a51+a15);
  a15=(a6*a11);
  a54=(a25*a15);
  a55=(a10+a10);
  a55=(a6*a55);
  a9=(a9*a55);
  a54=(a54+a9);
  a54=(a54+a54);
  a54=(a5*a54);
  a9=(a34*a54);
  a56=(a55/a35);
  a57=(a44*a15);
  a13=(a13*a55);
  a57=(a57-a13);
  a13=(a43*a57);
  a56=(a56+a13);
  a56=(a14*a56);
  a9=(a9-a56);
  a9=(a6*a9);
  a56=(a8*a9);
  a51=(a51+a56);
  if (res[2]!=0) res[2][14]=a51;
  a56=(a6*a7);
  a26=(a26*a56);
  a13=(a11+a11);
  a13=(a6*a13);
  a20=(a20*a13);
  a26=(a26+a20);
  a26=(a26+a26);
  a19=(a19*a26);
  a4=(a4*a19);
  a26=(a13/a0);
  a38=(a38*a56);
  a21=(a21*a13);
  a38=(a38-a21);
  a37=(a37*a38);
  a26=(a26+a37);
  a26=(a22*a26);
  a4=(a4-a26);
  a4=(a6*a4);
  a26=(a11*a4);
  a26=(a3+a26);
  a37=(a6*a8);
  a12=(a37/a12);
  a12=(a12+a12);
  a12=(a5*a12);
  a12=(a12/a24);
  a12=(-a12);
  a12=(a17?a12:0);
  a16=(a16*a37);
  a16=(a16/a40);
  a18=(a18*a16);
  a12=(a12-a18);
  a12=(a6*a12);
  a18=(a10*a12);
  a18=(a17?a18:0);
  a26=(a26+a18);
  a18=(a6*a10);
  a25=(a25*a18);
  a25=(a25+a25);
  a5=(a5*a25);
  a34=(a34*a5);
  a44=(a44*a18);
  a43=(a43*a44);
  a43=(a14*a43);
  a34=(a34-a43);
  a34=(a6*a34);
  a43=(a8*a34);
  a26=(a26+a43);
  if (res[2]!=0) res[2][15]=a26;
  if (res[2]!=0) res[2][16]=a23;
  a42=(a10*a42);
  a45=(a11*a45);
  a45=(-a45);
  a45=(a17?a45:0);
  a42=(a42+a45);
  a45=(a6*a30);
  a41=(a41/a35);
  a23=(a31/a35);
  a49=(a23*a49);
  a41=(a41-a49);
  a41=(a14*a41);
  a46=(a31*a46);
  a41=(a41+a46);
  a41=(a6*a41);
  a41=(a32*a41);
  a45=(a45+a41);
  a42=(a42+a45);
  a47=(a7*a47);
  a42=(a42+a47);
  if (res[2]!=0) res[2][17]=a42;
  a42=(a10*a50);
  a3=(a3+a42);
  a42=(a11*a53);
  a42=(-a42);
  a42=(a17?a42:0);
  a3=(a3+a42);
  a15=(a15/a35);
  a57=(a23*a57);
  a15=(a15-a57);
  a15=(a14*a15);
  a54=(a31*a54);
  a15=(a15+a54);
  a15=(a6*a15);
  a54=(a32*a15);
  a3=(a3+a54);
  a54=(a7*a9);
  a3=(a3+a54);
  if (res[2]!=0) res[2][18]=a3;
  a54=(a10*a4);
  a57=(a11*a12);
  a36=(a36+a57);
  a36=(-a36);
  a36=(a17?a36:0);
  a54=(a54+a36);
  a18=(a18/a35);
  a23=(a23*a44);
  a18=(a18-a23);
  a14=(a14*a18);
  a31=(a31*a5);
  a14=(a14+a31);
  a14=(a6*a14);
  a32=(a32*a14);
  a54=(a54+a32);
  a32=(a7*a34);
  a54=(a54+a32);
  if (res[2]!=0) res[2][19]=a54;
  if (res[2]!=0) res[2][20]=a51;
  if (res[2]!=0) res[2][21]=a3;
  a3=(a6*a27);
  a48=(a48/a0);
  a51=(a29/a0);
  a52=(a51*a52);
  a48=(a48-a52);
  a48=(a22*a48);
  a39=(a29*a39);
  a48=(a48+a39);
  a48=(a6*a48);
  a48=(a1*a48);
  a3=(a3+a48);
  a50=(a8*a50);
  a3=(a3+a50);
  a53=(a7*a53);
  a53=(a17?a53:0);
  a3=(a3+a53);
  a30=(a6*a30);
  a15=(a28*a15);
  a30=(a30+a15);
  a3=(a3+a30);
  a9=(a11*a9);
  a3=(a3+a9);
  if (res[2]!=0) res[2][22]=a3;
  a56=(a56/a0);
  a51=(a51*a38);
  a56=(a56-a51);
  a22=(a22*a56);
  a29=(a29*a19);
  a22=(a22+a29);
  a22=(a6*a22);
  a1=(a1*a22);
  a29=(a8*a4);
  a1=(a1+a29);
  a29=(a7*a12);
  a29=(a17?a29:0);
  a1=(a1+a29);
  a28=(a28*a14);
  a1=(a1+a28);
  a11=(a11*a34);
  a33=(a33+a11);
  a1=(a1+a33);
  if (res[2]!=0) res[2][23]=a1;
  if (res[2]!=0) res[2][24]=a26;
  if (res[2]!=0) res[2][25]=a54;
  if (res[2]!=0) res[2][26]=a1;
  a6=(a6*a27);
  a2=(a2*a22);
  a6=(a6+a2);
  a7=(a7*a4);
  a6=(a6+a7);
  a8=(a8*a12);
  a8=(-a8);
  a17=(a17?a8:0);
  a6=(a6+a17);
  a10=(a10*a34);
  a6=(a6+a10);
  if (res[2]!=0) res[2][27]=a6;
  a6=20.;
  if (res[2]!=0) res[2][28]=a6;
  if (res[2]!=0) res[2][29]=a6;
  if (res[2]!=0) res[2][30]=a6;
  return 0;
}

CASADI_SYMBOL_EXPORT int payload_model_cost_ext_cost_fun_jac_hess(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int payload_model_cost_ext_cost_fun_jac_hess_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int payload_model_cost_ext_cost_fun_jac_hess_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void payload_model_cost_ext_cost_fun_jac_hess_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int payload_model_cost_ext_cost_fun_jac_hess_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void payload_model_cost_ext_cost_fun_jac_hess_release(int mem) {
}

CASADI_SYMBOL_EXPORT void payload_model_cost_ext_cost_fun_jac_hess_incref(void) {
}

CASADI_SYMBOL_EXPORT void payload_model_cost_ext_cost_fun_jac_hess_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int payload_model_cost_ext_cost_fun_jac_hess_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int payload_model_cost_ext_cost_fun_jac_hess_n_out(void) { return 5;}

CASADI_SYMBOL_EXPORT casadi_real payload_model_cost_ext_cost_fun_jac_hess_default_in(casadi_int i) {
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* payload_model_cost_ext_cost_fun_jac_hess_name_in(casadi_int i) {
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* payload_model_cost_ext_cost_fun_jac_hess_name_out(casadi_int i) {
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    case 2: return "o2";
    case 3: return "o3";
    case 4: return "o4";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* payload_model_cost_ext_cost_fun_jac_hess_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    case 2: return casadi_s2;
    case 3: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* payload_model_cost_ext_cost_fun_jac_hess_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s4;
    case 1: return casadi_s5;
    case 2: return casadi_s6;
    case 3: return casadi_s2;
    case 4: return casadi_s7;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int payload_model_cost_ext_cost_fun_jac_hess_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4;
  if (sz_res) *sz_res = 5;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

CASADI_SYMBOL_EXPORT int payload_model_cost_ext_cost_fun_jac_hess_work_bytes(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4*sizeof(const casadi_real*);
  if (sz_res) *sz_res = 5*sizeof(casadi_real*);
  if (sz_iw) *sz_iw = 0*sizeof(casadi_int);
  if (sz_w) *sz_w = 0*sizeof(casadi_real);
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
