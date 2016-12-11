/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lab_2_sfun.h"
#include "c2_lab_2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lab_2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[30] = { "l", "angle", "tetta", "di",
  "ai", "alpha", "i", "c_t", "s_t", "d", "a", "c_a", "s_a", "Rtz", "Tz", "Tx",
  "Rtx", "A", "x", "y", "z", "nargin", "nargout", "t1", "t2", "t3", "t4", "t5",
  "t6", "H" };

/* Function Declarations */
static void initialize_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void initialize_params_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void enable_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void disable_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_lab_2(SFc2_lab_2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_lab_2(SFc2_lab_2InstanceStruct
  *chartInstance);
static void set_sim_state_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void sf_gateway_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void c2_chartstep_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void initSimStructsc2_lab_2(SFc2_lab_2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance, const
  mxArray *c2_H, const char_T *c2_identifier, real_T c2_y[16]);
static void c2_b_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static void c2_eml_scalar_eg(SFc2_lab_2InstanceStruct *chartInstance);
static void c2_eml_xgemm(SFc2_lab_2InstanceStruct *chartInstance, real_T c2_A[16],
  real_T c2_B[16], real_T c2_C[16], real_T c2_b_C[16]);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_lab_2, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_eml_xgemm(SFc2_lab_2InstanceStruct *chartInstance, real_T c2_A
  [16], real_T c2_B[16], real_T c2_C[16]);
static void init_dsm_address_info(SFc2_lab_2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_lab_2 = 0U;
}

static void initialize_params_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_lab_2(SFc2_lab_2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_lab_2(SFc2_lab_2InstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[16];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_H)[16];
  c2_H = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  for (c2_i0 = 0; c2_i0 < 16; c2_i0++) {
    c2_u[c2_i0] = (*c2_H)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_lab_2;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[16];
  int32_T c2_i1;
  real_T (*c2_H)[16];
  c2_H = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "H",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 16; c2_i1++) {
    (*c2_H)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_lab_2 = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_lab_2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_lab_2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T *c2_t1;
  real_T *c2_t2;
  real_T *c2_t3;
  real_T *c2_t4;
  real_T *c2_t5;
  real_T *c2_t6;
  real_T (*c2_H)[16];
  c2_t6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_t5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_t4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_t3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_t2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_H = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_lab_2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lab_2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i2 = 0; c2_i2 < 16; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_H)[c2_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_t1, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_t2, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_t3, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_t4, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_t5, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_t6, 6U);
}

static void c2_chartstep_c2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_t1;
  real_T c2_t2;
  real_T c2_t3;
  real_T c2_t4;
  real_T c2_t5;
  real_T c2_t6;
  uint32_T c2_debug_family_var_map[30];
  real_T c2_l;
  real_T c2_angle;
  real_T c2_tetta[6];
  real_T c2_di[6];
  real_T c2_ai[6];
  real_T c2_alpha[6];
  real_T c2_i;
  real_T c2_c_t;
  real_T c2_s_t;
  real_T c2_d;
  real_T c2_a;
  real_T c2_c_a;
  real_T c2_s_a;
  real_T c2_Rtz[16];
  real_T c2_Tz[16];
  real_T c2_Tx[16];
  real_T c2_Rtx[16];
  real_T c2_A[16];
  real_T c2_x;
  real_T c2_y;
  real_T c2_z;
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 1.0;
  real_T c2_H[16];
  int32_T c2_i3;
  static real_T c2_dv1[6] = { 10.0, 0.0, 0.0, 20.0, 0.0, 20.0 };

  int32_T c2_i4;
  static real_T c2_dv2[6] = { 0.0, 10.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c2_i5;
  static real_T c2_dv3[6] = { 1.5707963267948966, 0.0, -1.5707963267948966,
    1.5707963267948966, -1.5707963267948966, 0.0 };

  int32_T c2_i6;
  static real_T c2_dv4[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c2_b_i;
  real_T c2_b_A;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_c_A;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_c_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  int32_T c2_i7;
  int32_T c2_i8;
  static real_T c2_dv5[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c2_i9;
  int32_T c2_i10;
  static real_T c2_dv6[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c2_i11;
  int32_T c2_i12;
  static real_T c2_dv7[4] = { 1.0, 0.0, 0.0, 0.0 };

  int32_T c2_i13;
  int32_T c2_i14;
  static real_T c2_dv8[4] = { 0.0, 1.0, 0.0, 0.0 };

  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  real_T c2_b_a[16];
  int32_T c2_i28;
  real_T c2_b[16];
  int32_T c2_i29;
  real_T c2_d_y[16];
  int32_T c2_i30;
  real_T c2_d_a[16];
  int32_T c2_i31;
  real_T c2_b_b[16];
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  real_T c2_e_y[16];
  int32_T c2_i35;
  real_T c2_c_b[16];
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  real_T c2_dv9[16];
  int32_T c2_i40;
  real_T c2_dv10[16];
  int32_T c2_i41;
  real_T c2_dv11[16];
  int32_T c2_i42;
  real_T c2_dv12[16];
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  real_T c2_dv13[16];
  int32_T c2_i48;
  real_T c2_dv14[16];
  int32_T c2_i49;
  real_T c2_dv15[16];
  int32_T c2_i50;
  real_T c2_dv16[16];
  int32_T c2_i51;
  real_T *c2_b_t6;
  real_T *c2_b_t5;
  real_T *c2_b_t4;
  real_T *c2_b_t3;
  real_T *c2_b_t2;
  real_T *c2_b_t1;
  real_T (*c2_b_H)[16];
  c2_b_t6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_t5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_t4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_t3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_t2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_H = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_t1;
  c2_b_hoistedGlobal = *c2_b_t2;
  c2_c_hoistedGlobal = *c2_b_t3;
  c2_d_hoistedGlobal = *c2_b_t4;
  c2_e_hoistedGlobal = *c2_b_t5;
  c2_f_hoistedGlobal = *c2_b_t6;
  c2_t1 = c2_hoistedGlobal;
  c2_t2 = c2_b_hoistedGlobal;
  c2_t3 = c2_c_hoistedGlobal;
  c2_t4 = c2_d_hoistedGlobal;
  c2_t5 = c2_e_hoistedGlobal;
  c2_t6 = c2_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_l, 0U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_angle, 1U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tetta, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_di, 3U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_ai, 4U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_alpha, 5U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_t, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_s_t, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_a, 10U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_a, 11U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_s_a, 12U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Rtz, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Tz, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Tx, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Rtx, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_A, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_x, 18U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_y, 19U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_z, 20U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 21U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 22U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_t1, 23U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_t2, 24U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_t3, 25U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_t4, 26U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_t5, 27U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_t6, 28U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_H, 29U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_l = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_angle = 1.5707963267948966;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_tetta[0] = c2_t1;
  c2_tetta[1] = c2_t2;
  c2_tetta[2] = c2_t3;
  c2_tetta[3] = c2_t4;
  c2_tetta[4] = c2_t5;
  c2_tetta[5] = c2_t6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i3 = 0; c2_i3 < 6; c2_i3++) {
    c2_di[c2_i3] = c2_dv1[c2_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    c2_ai[c2_i4] = c2_dv2[c2_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    c2_alpha[c2_i5] = c2_dv3[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i6 = 0; c2_i6 < 16; c2_i6++) {
    c2_H[c2_i6] = c2_dv4[c2_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_i = 1.0;
  c2_b_i = 0;
  while (c2_b_i < 6) {
    c2_i = 1.0 + (real_T)c2_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
    c2_b_A = c2_tetta[_SFD_EML_ARRAY_BOUNDS_CHECK("tetta", (int32_T)
      _SFD_INTEGER_CHECK("i", c2_i), 1, 6, 1, 0) - 1] * 3.1415926535897931;
    c2_b_x = c2_b_A;
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_b_y = c2_d_x / 180.0;
    c2_e_x = c2_b_y;
    c2_c_t = c2_e_x;
    c2_f_x = c2_c_t;
    c2_c_t = c2_f_x;
    c2_c_t = muDoubleScalarCos(c2_c_t);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
    c2_c_A = c2_tetta[_SFD_EML_ARRAY_BOUNDS_CHECK("tetta", (int32_T)
      _SFD_INTEGER_CHECK("i", c2_i), 1, 6, 1, 0) - 1] * 3.1415926535897931;
    c2_g_x = c2_c_A;
    c2_h_x = c2_g_x;
    c2_i_x = c2_h_x;
    c2_c_y = c2_i_x / 180.0;
    c2_j_x = c2_c_y;
    c2_s_t = c2_j_x;
    c2_k_x = c2_s_t;
    c2_s_t = c2_k_x;
    c2_s_t = muDoubleScalarSin(c2_s_t);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
    c2_d = c2_di[_SFD_EML_ARRAY_BOUNDS_CHECK("di", (int32_T)_SFD_INTEGER_CHECK(
      "i", c2_i), 1, 6, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    c2_a = c2_ai[_SFD_EML_ARRAY_BOUNDS_CHECK("ai", (int32_T)_SFD_INTEGER_CHECK(
      "i", c2_i), 1, 6, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    c2_l_x = c2_alpha[_SFD_EML_ARRAY_BOUNDS_CHECK("alpha", (int32_T)
      _SFD_INTEGER_CHECK("i", c2_i), 1, 6, 1, 0) - 1];
    c2_c_a = c2_l_x;
    c2_m_x = c2_c_a;
    c2_c_a = c2_m_x;
    c2_c_a = muDoubleScalarCos(c2_c_a);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    c2_n_x = c2_alpha[_SFD_EML_ARRAY_BOUNDS_CHECK("alpha", (int32_T)
      _SFD_INTEGER_CHECK("i", c2_i), 1, 6, 1, 0) - 1];
    c2_s_a = c2_n_x;
    c2_o_x = c2_s_a;
    c2_s_a = c2_o_x;
    c2_s_a = muDoubleScalarSin(c2_s_a);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
    c2_Rtz[0] = c2_c_t;
    c2_Rtz[4] = -c2_s_t;
    c2_Rtz[8] = 0.0;
    c2_Rtz[12] = 0.0;
    c2_Rtz[1] = c2_s_t;
    c2_Rtz[5] = c2_c_t;
    c2_Rtz[9] = 0.0;
    c2_Rtz[13] = 0.0;
    c2_i7 = 0;
    for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
      c2_Rtz[c2_i7 + 2] = c2_dv5[c2_i8];
      c2_i7 += 4;
    }

    c2_i9 = 0;
    for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
      c2_Rtz[c2_i9 + 3] = c2_dv6[c2_i10];
      c2_i9 += 4;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
    c2_i11 = 0;
    for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
      c2_Tz[c2_i11] = c2_dv7[c2_i12];
      c2_i11 += 4;
    }

    c2_i13 = 0;
    for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
      c2_Tz[c2_i13 + 1] = c2_dv8[c2_i14];
      c2_i13 += 4;
    }

    c2_Tz[2] = 0.0;
    c2_Tz[6] = 0.0;
    c2_Tz[10] = 1.0;
    c2_Tz[14] = c2_d;
    c2_i15 = 0;
    for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
      c2_Tz[c2_i15 + 3] = c2_dv6[c2_i16];
      c2_i15 += 4;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
    c2_Tx[0] = 1.0;
    c2_Tx[4] = 0.0;
    c2_Tx[8] = 0.0;
    c2_Tx[12] = c2_a;
    c2_i17 = 0;
    for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
      c2_Tx[c2_i17 + 1] = c2_dv8[c2_i18];
      c2_i17 += 4;
    }

    c2_i19 = 0;
    for (c2_i20 = 0; c2_i20 < 4; c2_i20++) {
      c2_Tx[c2_i19 + 2] = c2_dv5[c2_i20];
      c2_i19 += 4;
    }

    c2_i21 = 0;
    for (c2_i22 = 0; c2_i22 < 4; c2_i22++) {
      c2_Tx[c2_i21 + 3] = c2_dv6[c2_i22];
      c2_i21 += 4;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
    c2_i23 = 0;
    for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
      c2_Rtx[c2_i23] = c2_dv7[c2_i24];
      c2_i23 += 4;
    }

    c2_Rtx[1] = 0.0;
    c2_Rtx[5] = c2_c_a;
    c2_Rtx[9] = -c2_s_a;
    c2_Rtx[13] = 0.0;
    c2_Rtx[2] = 0.0;
    c2_Rtx[6] = c2_s_a;
    c2_Rtx[10] = c2_c_a;
    c2_Rtx[14] = 0.0;
    c2_i25 = 0;
    for (c2_i26 = 0; c2_i26 < 4; c2_i26++) {
      c2_Rtx[c2_i25 + 3] = c2_dv6[c2_i26];
      c2_i25 += 4;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
    for (c2_i27 = 0; c2_i27 < 16; c2_i27++) {
      c2_b_a[c2_i27] = c2_Rtz[c2_i27];
    }

    for (c2_i28 = 0; c2_i28 < 16; c2_i28++) {
      c2_b[c2_i28] = c2_Tz[c2_i28];
    }

    c2_eml_scalar_eg(chartInstance);
    c2_eml_scalar_eg(chartInstance);
    for (c2_i29 = 0; c2_i29 < 16; c2_i29++) {
      c2_d_y[c2_i29] = 0.0;
    }

    for (c2_i30 = 0; c2_i30 < 16; c2_i30++) {
      c2_d_a[c2_i30] = c2_b_a[c2_i30];
    }

    for (c2_i31 = 0; c2_i31 < 16; c2_i31++) {
      c2_b_b[c2_i31] = c2_b[c2_i31];
    }

    c2_b_eml_xgemm(chartInstance, c2_d_a, c2_b_b, c2_d_y);
    for (c2_i32 = 0; c2_i32 < 16; c2_i32++) {
      c2_b[c2_i32] = c2_Tx[c2_i32];
    }

    c2_eml_scalar_eg(chartInstance);
    c2_eml_scalar_eg(chartInstance);
    for (c2_i33 = 0; c2_i33 < 16; c2_i33++) {
      c2_b_a[c2_i33] = 0.0;
    }

    for (c2_i34 = 0; c2_i34 < 16; c2_i34++) {
      c2_e_y[c2_i34] = c2_d_y[c2_i34];
    }

    for (c2_i35 = 0; c2_i35 < 16; c2_i35++) {
      c2_c_b[c2_i35] = c2_b[c2_i35];
    }

    c2_b_eml_xgemm(chartInstance, c2_e_y, c2_c_b, c2_b_a);
    for (c2_i36 = 0; c2_i36 < 16; c2_i36++) {
      c2_b[c2_i36] = c2_Rtx[c2_i36];
    }

    c2_eml_scalar_eg(chartInstance);
    c2_eml_scalar_eg(chartInstance);
    for (c2_i37 = 0; c2_i37 < 16; c2_i37++) {
      c2_A[c2_i37] = 0.0;
    }

    for (c2_i38 = 0; c2_i38 < 16; c2_i38++) {
      c2_A[c2_i38] = 0.0;
    }

    for (c2_i39 = 0; c2_i39 < 16; c2_i39++) {
      c2_dv9[c2_i39] = c2_b_a[c2_i39];
    }

    for (c2_i40 = 0; c2_i40 < 16; c2_i40++) {
      c2_dv10[c2_i40] = c2_b[c2_i40];
    }

    for (c2_i41 = 0; c2_i41 < 16; c2_i41++) {
      c2_dv11[c2_i41] = c2_dv9[c2_i41];
    }

    for (c2_i42 = 0; c2_i42 < 16; c2_i42++) {
      c2_dv12[c2_i42] = c2_dv10[c2_i42];
    }

    c2_b_eml_xgemm(chartInstance, c2_dv11, c2_dv12, c2_A);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
    for (c2_i43 = 0; c2_i43 < 16; c2_i43++) {
      c2_b_a[c2_i43] = c2_H[c2_i43];
    }

    for (c2_i44 = 0; c2_i44 < 16; c2_i44++) {
      c2_b[c2_i44] = c2_A[c2_i44];
    }

    c2_eml_scalar_eg(chartInstance);
    c2_eml_scalar_eg(chartInstance);
    for (c2_i45 = 0; c2_i45 < 16; c2_i45++) {
      c2_H[c2_i45] = 0.0;
    }

    for (c2_i46 = 0; c2_i46 < 16; c2_i46++) {
      c2_H[c2_i46] = 0.0;
    }

    for (c2_i47 = 0; c2_i47 < 16; c2_i47++) {
      c2_dv13[c2_i47] = c2_b_a[c2_i47];
    }

    for (c2_i48 = 0; c2_i48 < 16; c2_i48++) {
      c2_dv14[c2_i48] = c2_b[c2_i48];
    }

    for (c2_i49 = 0; c2_i49 < 16; c2_i49++) {
      c2_dv15[c2_i49] = c2_dv13[c2_i49];
    }

    for (c2_i50 = 0; c2_i50 < 16; c2_i50++) {
      c2_dv16[c2_i50] = c2_dv14[c2_i50];
    }

    c2_b_eml_xgemm(chartInstance, c2_dv15, c2_dv16, c2_H);
    c2_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
  c2_x = c2_H[12];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
  c2_y = c2_H[13];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  c2_z = c2_H[14];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -57);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i51 = 0; c2_i51 < 16; c2_i51++) {
    (*c2_b_H)[c2_i51] = c2_H[c2_i51];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_lab_2(SFc2_lab_2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  real_T c2_b_inData[16];
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i52 = 0;
  for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
    for (c2_i54 = 0; c2_i54 < 4; c2_i54++) {
      c2_b_inData[c2_i54 + c2_i52] = (*(real_T (*)[16])c2_inData)[c2_i54 +
        c2_i52];
    }

    c2_i52 += 4;
  }

  c2_i55 = 0;
  for (c2_i56 = 0; c2_i56 < 4; c2_i56++) {
    for (c2_i57 = 0; c2_i57 < 4; c2_i57++) {
      c2_u[c2_i57 + c2_i55] = c2_b_inData[c2_i57 + c2_i55];
    }

    c2_i55 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance, const
  mxArray *c2_H, const char_T *c2_identifier, real_T c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_H), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_H);
}

static void c2_b_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16])
{
  real_T c2_dv17[16];
  int32_T c2_i58;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv17, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i58 = 0; c2_i58 < 16; c2_i58++) {
    c2_y[c2_i58] = c2_dv17[c2_i58];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_H;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_H = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_H), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_H);
  c2_i59 = 0;
  for (c2_i60 = 0; c2_i60 < 4; c2_i60++) {
    for (c2_i61 = 0; c2_i61 < 4; c2_i61++) {
      (*(real_T (*)[16])c2_outData)[c2_i61 + c2_i59] = c2_y[c2_i61 + c2_i59];
    }

    c2_i59 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i62;
  real_T c2_b_inData[6];
  int32_T c2_i63;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i62 = 0; c2_i62 < 6; c2_i62++) {
    c2_b_inData[c2_i62] = (*(real_T (*)[6])c2_inData)[c2_i62];
  }

  for (c2_i63 = 0; c2_i63 < 6; c2_i63++) {
    c2_u[c2_i63] = c2_b_inData[c2_i63];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv18[6];
  int32_T c2_i64;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv18, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c2_i64 = 0; c2_i64 < 6; c2_i64++) {
    c2_y[c2_i64] = c2_dv18[c2_i64];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_alpha;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i65;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_alpha = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_alpha), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_alpha);
  for (c2_i65 = 0; c2_i65 < 6; c2_i65++) {
    (*(real_T (*)[6])c2_outData)[c2_i65] = c2_y[c2_i65];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_lab_2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 24, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  const mxArray *c2_rhs16 = NULL;
  const mxArray *c2_lhs16 = NULL;
  const mxArray *c2_rhs17 = NULL;
  const mxArray *c2_lhs17 = NULL;
  const mxArray *c2_rhs18 = NULL;
  const mxArray *c2_lhs18 = NULL;
  const mxArray *c2_rhs19 = NULL;
  const mxArray *c2_lhs19 = NULL;
  const mxArray *c2_rhs20 = NULL;
  const mxArray *c2_lhs20 = NULL;
  const mxArray *c2_rhs21 = NULL;
  const mxArray *c2_lhs21 = NULL;
  const mxArray *c2_rhs22 = NULL;
  const mxArray *c2_lhs22 = NULL;
  const mxArray *c2_rhs23 = NULL;
  const mxArray *c2_lhs23 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("cos"), "name", "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343837572U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825922U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sin"), "name", "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343837586U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825936U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1383880894U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987890U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c2_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c2_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c2_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c2_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c2_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c2_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c2_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c2_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs23), "lhs", "lhs",
                  23);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
  sf_mex_destroy(&c2_rhs16);
  sf_mex_destroy(&c2_lhs16);
  sf_mex_destroy(&c2_rhs17);
  sf_mex_destroy(&c2_lhs17);
  sf_mex_destroy(&c2_rhs18);
  sf_mex_destroy(&c2_lhs18);
  sf_mex_destroy(&c2_rhs19);
  sf_mex_destroy(&c2_lhs19);
  sf_mex_destroy(&c2_rhs20);
  sf_mex_destroy(&c2_lhs20);
  sf_mex_destroy(&c2_rhs21);
  sf_mex_destroy(&c2_lhs21);
  sf_mex_destroy(&c2_rhs22);
  sf_mex_destroy(&c2_lhs22);
  sf_mex_destroy(&c2_rhs23);
  sf_mex_destroy(&c2_lhs23);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static void c2_eml_scalar_eg(SFc2_lab_2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_xgemm(SFc2_lab_2InstanceStruct *chartInstance, real_T c2_A[16],
  real_T c2_B[16], real_T c2_C[16], real_T c2_b_C[16])
{
  int32_T c2_i66;
  int32_T c2_i67;
  real_T c2_b_A[16];
  int32_T c2_i68;
  real_T c2_b_B[16];
  for (c2_i66 = 0; c2_i66 < 16; c2_i66++) {
    c2_b_C[c2_i66] = c2_C[c2_i66];
  }

  for (c2_i67 = 0; c2_i67 < 16; c2_i67++) {
    c2_b_A[c2_i67] = c2_A[c2_i67];
  }

  for (c2_i68 = 0; c2_i68 < 16; c2_i68++) {
    c2_b_B[c2_i68] = c2_B[c2_i68];
  }

  c2_b_eml_xgemm(chartInstance, c2_b_A, c2_b_B, c2_b_C);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i69;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i69, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i69;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_lab_2InstanceStruct *chartInstance;
  chartInstance = (SFc2_lab_2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_lab_2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_is_active_c2_lab_2),
    &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_lab_2);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_lab_2InstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_eml_xgemm(SFc2_lab_2InstanceStruct *chartInstance, real_T c2_A
  [16], real_T c2_B[16], real_T c2_C[16])
{
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  (void)chartInstance;
  for (c2_i70 = 0; c2_i70 < 4; c2_i70++) {
    c2_i71 = 0;
    for (c2_i72 = 0; c2_i72 < 4; c2_i72++) {
      c2_C[c2_i71 + c2_i70] = 0.0;
      c2_i73 = 0;
      for (c2_i74 = 0; c2_i74 < 4; c2_i74++) {
        c2_C[c2_i71 + c2_i70] += c2_A[c2_i73 + c2_i70] * c2_B[c2_i74 + c2_i71];
        c2_i73 += 4;
      }

      c2_i71 += 4;
    }
  }
}

static void init_dsm_address_info(SFc2_lab_2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_lab_2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3795619123U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1642466623U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1767194689U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(440912386U);
}

mxArray *sf_c2_lab_2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("O3GAOQ99TZO8W3ppIjUdqB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_lab_2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_lab_2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_lab_2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[14],T\"H\",},{M[8],M[0],T\"is_active_c2_lab_2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_lab_2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_lab_2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_lab_2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lab_2MachineNumber_,
           2,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_lab_2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_lab_2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _lab_2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"H");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"t2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"t4");
          _SFD_SET_DATA_PROPS(5,1,1,0,"t5");
          _SFD_SET_DATA_PROPS(6,1,1,0,"t6");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1070);
        _SFD_CV_INIT_EML_FOR(0,1,0,316,328,1013);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_t1;
          real_T *c2_t2;
          real_T *c2_t3;
          real_T *c2_t4;
          real_T *c2_t5;
          real_T *c2_t6;
          real_T (*c2_H)[16];
          c2_t6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_t5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_t4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_t3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_t2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_H = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_H);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_t1);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_t2);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_t3);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_t4);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_t5);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_t6);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _lab_2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "atJp8BrS65U3XhV6AOrd0C";
}

static void sf_opaque_initialize_c2_lab_2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_lab_2InstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_lab_2((SFc2_lab_2InstanceStruct*) chartInstanceVar);
  initialize_c2_lab_2((SFc2_lab_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_lab_2(void *chartInstanceVar)
{
  enable_c2_lab_2((SFc2_lab_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_lab_2(void *chartInstanceVar)
{
  disable_c2_lab_2((SFc2_lab_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_lab_2(void *chartInstanceVar)
{
  sf_gateway_c2_lab_2((SFc2_lab_2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_lab_2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_lab_2((SFc2_lab_2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lab_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_lab_2(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_lab_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_lab_2((SFc2_lab_2InstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_lab_2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_lab_2(S);
}

static void sf_opaque_set_sim_state_c2_lab_2(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_lab_2(S, st);
}

static void sf_opaque_terminate_c2_lab_2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_lab_2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lab_2_optimization_info();
    }

    finalize_c2_lab_2((SFc2_lab_2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_lab_2((SFc2_lab_2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_lab_2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c2_lab_2((SFc2_lab_2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_lab_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lab_2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(514907255U));
  ssSetChecksum1(S,(438255185U));
  ssSetChecksum2(S,(3475208544U));
  ssSetChecksum3(S,(3361605427U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_lab_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_lab_2(SimStruct *S)
{
  SFc2_lab_2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_lab_2InstanceStruct *)utMalloc(sizeof
    (SFc2_lab_2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_lab_2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_lab_2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_lab_2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_lab_2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_lab_2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_lab_2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_lab_2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_lab_2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_lab_2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_lab_2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_lab_2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_lab_2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_lab_2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_lab_2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_lab_2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_lab_2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_lab_2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
