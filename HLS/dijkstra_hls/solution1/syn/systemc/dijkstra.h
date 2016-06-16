// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2014.4
// Copyright (C) 2014 Xilinx Inc. All rights reserved.
// 
// ===========================================================

#ifndef _dijkstra_HH_
#define _dijkstra_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "dijkstra_vector.h"
#include "dijkstra_matrix.h"
#include "dijkstra_result.h"

namespace ap_rtl {

struct dijkstra : public sc_module {
    // Port declarations 28
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<6> > in_data_V_address0;
    sc_out< sc_logic > in_data_V_ce0;
    sc_in< sc_lv<8> > in_data_V_q0;
    sc_out< sc_lv<6> > in_last_V_address0;
    sc_out< sc_logic > in_last_V_ce0;
    sc_out< sc_logic > in_last_V_we0;
    sc_out< sc_lv<1> > in_last_V_d0;
    sc_in< sc_lv<1> > in_last_V_q0;
    sc_out< sc_lv<6> > in_last_V_address1;
    sc_out< sc_logic > in_last_V_ce1;
    sc_out< sc_logic > in_last_V_we1;
    sc_out< sc_lv<1> > in_last_V_d1;
    sc_in< sc_lv<1> > in_last_V_q1;
    sc_in< sc_lv<8> > start_point_V;
    sc_out< sc_lv<3> > out_data_V_address0;
    sc_out< sc_logic > out_data_V_ce0;
    sc_out< sc_logic > out_data_V_we0;
    sc_out< sc_lv<8> > out_data_V_d0;
    sc_out< sc_lv<3> > out_last_V_address0;
    sc_out< sc_logic > out_last_V_ce0;
    sc_out< sc_logic > out_last_V_we0;
    sc_out< sc_lv<1> > out_last_V_d0;


    // Module declarations
    dijkstra(sc_module_name name);
    SC_HAS_PROCESS(dijkstra);

    ~dijkstra();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    dijkstra_vector* vector_U;
    dijkstra_matrix* matrix_U;
    dijkstra_result* result_U;
    sc_signal< sc_lv<26> > ap_CS_fsm;
    sc_signal< sc_logic > ap_sig_cseq_ST_st1_fsm_0;
    sc_signal< bool > ap_sig_bdd_42;
    sc_signal< sc_lv<3> > vector_address0;
    sc_signal< sc_logic > vector_ce0;
    sc_signal< sc_logic > vector_we0;
    sc_signal< sc_lv<1> > vector_d0;
    sc_signal< sc_lv<1> > vector_q0;
    sc_signal< sc_lv<6> > matrix_address0;
    sc_signal< sc_logic > matrix_ce0;
    sc_signal< sc_logic > matrix_we0;
    sc_signal< sc_lv<8> > matrix_d0;
    sc_signal< sc_lv<8> > matrix_q0;
    sc_signal< sc_lv<3> > result_address0;
    sc_signal< sc_logic > result_ce0;
    sc_signal< sc_logic > result_we0;
    sc_signal< sc_lv<4> > result_d0;
    sc_signal< sc_lv<4> > result_q0;
    sc_signal< sc_lv<4> > i_8_fu_466_p2;
    sc_signal< sc_logic > ap_sig_cseq_ST_st2_fsm_1;
    sc_signal< bool > ap_sig_bdd_120;
    sc_signal< sc_lv<4> > i_9_fu_483_p2;
    sc_signal< sc_lv<4> > i_9_reg_871;
    sc_signal< sc_logic > ap_sig_cseq_ST_st3_fsm_2;
    sc_signal< bool > ap_sig_bdd_129;
    sc_signal< sc_lv<6> > tmp_4_fu_493_p3;
    sc_signal< sc_lv<6> > tmp_4_reg_876;
    sc_signal< sc_lv<1> > exitcond2_fu_477_p2;
    sc_signal< sc_lv<8> > matrix_addr9_cast_fu_509_p1;
    sc_signal< sc_lv<8> > matrix_addr9_cast_reg_881;
    sc_signal< sc_lv<4> > e_5_fu_519_p2;
    sc_signal< sc_lv<4> > e_5_reg_889;
    sc_signal< sc_logic > ap_sig_cseq_ST_st4_fsm_3;
    sc_signal< bool > ap_sig_bdd_146;
    sc_signal< sc_lv<1> > exitcond3_fu_513_p2;
    sc_signal< sc_lv<8> > matrix_addr1_fu_543_p2;
    sc_signal< sc_lv<8> > matrix_addr1_reg_899;
    sc_signal< sc_lv<4> > i_14_fu_558_p2;
    sc_signal< sc_lv<4> > i_14_reg_907;
    sc_signal< sc_logic > ap_sig_cseq_ST_st7_fsm_6;
    sc_signal< bool > ap_sig_bdd_162;
    sc_signal< sc_lv<1> > exitcond4_fu_552_p2;
    sc_signal< sc_lv<1> > vector_load_reg_917;
    sc_signal< sc_logic > ap_sig_cseq_ST_st8_fsm_7;
    sc_signal< bool > ap_sig_bdd_175;
    sc_signal< sc_lv<8> > tmp_2_trn_cast_fu_569_p1;
    sc_signal< sc_lv<8> > tmp_2_trn_cast_reg_921;
    sc_signal< sc_lv<4> > e_6_fu_579_p2;
    sc_signal< sc_logic > ap_sig_cseq_ST_st9_fsm_8;
    sc_signal< bool > ap_sig_bdd_189;
    sc_signal< sc_lv<4> > i_10_fu_613_p2;
    sc_signal< sc_lv<4> > i_10_reg_937;
    sc_signal< sc_logic > ap_sig_cseq_ST_st10_fsm_9;
    sc_signal< bool > ap_sig_bdd_201;
    sc_signal< sc_lv<1> > exitcond5_fu_607_p2;
    sc_signal< sc_lv<8> > matrix_addr5_cast_fu_632_p1;
    sc_signal< sc_lv<8> > matrix_addr5_cast_reg_950;
    sc_signal< sc_logic > ap_sig_cseq_ST_st11_fsm_10;
    sc_signal< bool > ap_sig_bdd_215;
    sc_signal< sc_lv<4> > e_7_fu_642_p2;
    sc_signal< sc_lv<4> > e_7_reg_958;
    sc_signal< sc_logic > ap_sig_cseq_ST_st12_fsm_11;
    sc_signal< bool > ap_sig_bdd_225;
    sc_signal< sc_lv<1> > exitcond8_fu_636_p2;
    sc_signal< sc_lv<8> > min_4_min_1_fu_668_p3;
    sc_signal< sc_logic > ap_sig_cseq_ST_st13_fsm_12;
    sc_signal< bool > ap_sig_bdd_239;
    sc_signal< sc_lv<4> > i_11_fu_682_p2;
    sc_signal< sc_lv<4> > i_11_reg_976;
    sc_signal< sc_logic > ap_sig_cseq_ST_st15_fsm_14;
    sc_signal< bool > ap_sig_bdd_248;
    sc_signal< sc_lv<1> > exitcond7_fu_676_p2;
    sc_signal< sc_lv<1> > vector_load_2_reg_986;
    sc_signal< sc_logic > ap_sig_cseq_ST_st16_fsm_15;
    sc_signal< bool > ap_sig_bdd_261;
    sc_signal< sc_lv<8> > matrix_addr3_cast_fu_701_p1;
    sc_signal< sc_lv<8> > matrix_addr3_cast_reg_990;
    sc_signal< sc_lv<4> > e_8_fu_711_p2;
    sc_signal< sc_lv<4> > e_8_reg_998;
    sc_signal< sc_logic > ap_sig_cseq_ST_st17_fsm_16;
    sc_signal< bool > ap_sig_bdd_273;
    sc_signal< sc_lv<6> > matrix_addr_3_reg_1003;
    sc_signal< sc_lv<1> > exitcond10_fu_705_p2;
    sc_signal< sc_lv<4> > i_12_fu_744_p2;
    sc_signal< sc_lv<4> > i_12_reg_1011;
    sc_signal< sc_logic > ap_sig_cseq_ST_st19_fsm_18;
    sc_signal< bool > ap_sig_bdd_291;
    sc_signal< sc_lv<1> > exitcond9_fu_738_p2;
    sc_signal< sc_lv<1> > vector_load_3_reg_1021;
    sc_signal< sc_logic > ap_sig_cseq_ST_st20_fsm_19;
    sc_signal< bool > ap_sig_bdd_304;
    sc_signal< sc_lv<8> > matrix_addr1_cast_fu_763_p1;
    sc_signal< sc_lv<8> > matrix_addr1_cast_reg_1025;
    sc_signal< sc_lv<4> > e_9_fu_773_p2;
    sc_signal< sc_lv<4> > e_9_reg_1033;
    sc_signal< sc_logic > ap_sig_cseq_ST_st21_fsm_20;
    sc_signal< bool > ap_sig_bdd_316;
    sc_signal< sc_lv<1> > exitcond11_fu_767_p2;
    sc_signal< sc_lv<1> > tmp_20_reg_1046;
    sc_signal< sc_logic > ap_sig_cseq_ST_st23_fsm_22;
    sc_signal< bool > ap_sig_bdd_334;
    sc_signal< sc_lv<4> > i_16_fu_818_p2;
    sc_signal< sc_logic > ap_sig_cseq_ST_st24_fsm_23;
    sc_signal< bool > ap_sig_bdd_347;
    sc_signal< sc_lv<4> > i_17_fu_836_p2;
    sc_signal< sc_lv<4> > i_17_reg_1069;
    sc_signal< sc_logic > ap_sig_cseq_ST_st25_fsm_24;
    sc_signal< bool > ap_sig_bdd_359;
    sc_signal< sc_lv<64> > tmp_25_fu_842_p1;
    sc_signal< sc_lv<64> > tmp_25_reg_1074;
    sc_signal< sc_lv<1> > exitcond_fu_830_p2;
    sc_signal< sc_lv<4> > i_reg_268;
    sc_signal< sc_lv<1> > exitcond1_fu_460_p2;
    sc_signal< sc_lv<4> > i_1_reg_279;
    sc_signal< sc_lv<4> > e_reg_290;
    sc_signal< sc_logic > ap_sig_cseq_ST_st5_fsm_4;
    sc_signal< bool > ap_sig_bdd_390;
    sc_signal< sc_lv<4> > i_2_reg_301;
    sc_signal< sc_logic > ap_sig_cseq_ST_st6_fsm_5;
    sc_signal< bool > ap_sig_bdd_399;
    sc_signal< sc_lv<1> > exitcond6_fu_573_p2;
    sc_signal< sc_lv<4> > e_1_reg_313;
    sc_signal< sc_lv<4> > i_3_reg_324;
    sc_signal< sc_logic > ap_sig_cseq_ST_st14_fsm_13;
    sc_signal< bool > ap_sig_bdd_417;
    sc_signal< sc_lv<8> > min_reg_336;
    sc_signal< sc_lv<4> > e_2_reg_348;
    sc_signal< sc_lv<8> > min_1_reg_359;
    sc_signal< sc_lv<8> > min_3_reg_370;
    sc_signal< sc_lv<4> > i_4_reg_383;
    sc_signal< sc_lv<4> > e_3_reg_395;
    sc_signal< sc_logic > ap_sig_cseq_ST_st18_fsm_17;
    sc_signal< bool > ap_sig_bdd_447;
    sc_signal< sc_lv<4> > i_5_reg_406;
    sc_signal< sc_lv<4> > e_4_reg_419;
    sc_signal< sc_logic > ap_sig_cseq_ST_st22_fsm_21;
    sc_signal< bool > ap_sig_bdd_463;
    sc_signal< sc_lv<4> > i_6_reg_431;
    sc_signal< sc_lv<4> > i_7_reg_443;
    sc_signal< sc_logic > ap_sig_cseq_ST_st26_fsm_25;
    sc_signal< bool > ap_sig_bdd_477;
    sc_signal< sc_lv<1> > tmp_22_fu_824_p2;
    sc_signal< sc_lv<64> > tmp_fu_455_p1;
    sc_signal< sc_lv<64> > tmp_1_fu_472_p1;
    sc_signal< sc_lv<64> > tmp_9_fu_534_p1;
    sc_signal< sc_lv<64> > tmp_15_fu_548_p1;
    sc_signal< sc_lv<64> > tmp_2_fu_564_p1;
    sc_signal< sc_lv<64> > tmp_28_fu_602_p1;
    sc_signal< sc_lv<64> > tmp_10_fu_619_p1;
    sc_signal< sc_lv<64> > tmp_30_fu_657_p1;
    sc_signal< sc_lv<64> > tmp_13_fu_688_p1;
    sc_signal< sc_lv<64> > tmp_31_fu_726_p1;
    sc_signal< sc_lv<64> > tmp_17_fu_750_p1;
    sc_signal< sc_lv<64> > tmp_32_fu_788_p1;
    sc_signal< sc_lv<64> > tmp_23_fu_793_p1;
    sc_signal< sc_lv<1> > tmp_24_fu_799_p2;
    sc_signal< sc_lv<64> > tmp_21_fu_813_p1;
    sc_signal< sc_lv<8> > tmp_19_fu_731_p2;
    sc_signal< sc_lv<3> > tmp_5_fu_489_p1;
    sc_signal< sc_lv<7> > tmp_12_fu_501_p3;
    sc_signal< sc_lv<6> > tmp_7_cast_fu_525_p1;
    sc_signal< sc_lv<6> > tmp_8_fu_529_p2;
    sc_signal< sc_lv<8> > tmp_trn_cast_fu_539_p1;
    sc_signal< sc_lv<7> > tmp_27_fu_585_p3;
    sc_signal< sc_lv<8> > matrix_addr7_cast_fu_593_p1;
    sc_signal< sc_lv<8> > matrix_addr8_fu_597_p2;
    sc_signal< sc_lv<7> > tmp_18_fu_624_p3;
    sc_signal< sc_lv<8> > tmp_15_trn_cast_fu_648_p1;
    sc_signal< sc_lv<8> > matrix_addr6_fu_652_p2;
    sc_signal< sc_lv<1> > tmp_14_fu_662_p2;
    sc_signal< sc_lv<7> > tmp_26_fu_693_p3;
    sc_signal< sc_lv<8> > tmp_20_trn_cast_fu_717_p1;
    sc_signal< sc_lv<8> > matrix_addr4_fu_721_p2;
    sc_signal< sc_lv<7> > tmp_29_fu_755_p3;
    sc_signal< sc_lv<8> > tmp_24_trn_cast_fu_779_p1;
    sc_signal< sc_lv<8> > matrix_addr2_fu_783_p2;
    sc_signal< sc_lv<26> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<26> ap_ST_st1_fsm_0;
    static const sc_lv<26> ap_ST_st2_fsm_1;
    static const sc_lv<26> ap_ST_st3_fsm_2;
    static const sc_lv<26> ap_ST_st4_fsm_3;
    static const sc_lv<26> ap_ST_st5_fsm_4;
    static const sc_lv<26> ap_ST_st6_fsm_5;
    static const sc_lv<26> ap_ST_st7_fsm_6;
    static const sc_lv<26> ap_ST_st8_fsm_7;
    static const sc_lv<26> ap_ST_st9_fsm_8;
    static const sc_lv<26> ap_ST_st10_fsm_9;
    static const sc_lv<26> ap_ST_st11_fsm_10;
    static const sc_lv<26> ap_ST_st12_fsm_11;
    static const sc_lv<26> ap_ST_st13_fsm_12;
    static const sc_lv<26> ap_ST_st14_fsm_13;
    static const sc_lv<26> ap_ST_st15_fsm_14;
    static const sc_lv<26> ap_ST_st16_fsm_15;
    static const sc_lv<26> ap_ST_st17_fsm_16;
    static const sc_lv<26> ap_ST_st18_fsm_17;
    static const sc_lv<26> ap_ST_st19_fsm_18;
    static const sc_lv<26> ap_ST_st20_fsm_19;
    static const sc_lv<26> ap_ST_st21_fsm_20;
    static const sc_lv<26> ap_ST_st22_fsm_21;
    static const sc_lv<26> ap_ST_st23_fsm_22;
    static const sc_lv<26> ap_ST_st24_fsm_23;
    static const sc_lv<26> ap_ST_st25_fsm_24;
    static const sc_lv<26> ap_ST_st26_fsm_25;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<32> ap_const_lv32_13;
    static const sc_lv<32> ap_const_lv32_14;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_D;
    static const sc_lv<8> ap_const_lv8_FF;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_15;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<32> ap_const_lv32_19;
    static const sc_lv<4> ap_const_lv4_8;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<4> ap_const_lv4_6;
    static const sc_lv<6> ap_const_lv6_0;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_sig_bdd_120();
    void thread_ap_sig_bdd_129();
    void thread_ap_sig_bdd_146();
    void thread_ap_sig_bdd_162();
    void thread_ap_sig_bdd_175();
    void thread_ap_sig_bdd_189();
    void thread_ap_sig_bdd_201();
    void thread_ap_sig_bdd_215();
    void thread_ap_sig_bdd_225();
    void thread_ap_sig_bdd_239();
    void thread_ap_sig_bdd_248();
    void thread_ap_sig_bdd_261();
    void thread_ap_sig_bdd_273();
    void thread_ap_sig_bdd_291();
    void thread_ap_sig_bdd_304();
    void thread_ap_sig_bdd_316();
    void thread_ap_sig_bdd_334();
    void thread_ap_sig_bdd_347();
    void thread_ap_sig_bdd_359();
    void thread_ap_sig_bdd_390();
    void thread_ap_sig_bdd_399();
    void thread_ap_sig_bdd_417();
    void thread_ap_sig_bdd_42();
    void thread_ap_sig_bdd_447();
    void thread_ap_sig_bdd_463();
    void thread_ap_sig_bdd_477();
    void thread_ap_sig_cseq_ST_st10_fsm_9();
    void thread_ap_sig_cseq_ST_st11_fsm_10();
    void thread_ap_sig_cseq_ST_st12_fsm_11();
    void thread_ap_sig_cseq_ST_st13_fsm_12();
    void thread_ap_sig_cseq_ST_st14_fsm_13();
    void thread_ap_sig_cseq_ST_st15_fsm_14();
    void thread_ap_sig_cseq_ST_st16_fsm_15();
    void thread_ap_sig_cseq_ST_st17_fsm_16();
    void thread_ap_sig_cseq_ST_st18_fsm_17();
    void thread_ap_sig_cseq_ST_st19_fsm_18();
    void thread_ap_sig_cseq_ST_st1_fsm_0();
    void thread_ap_sig_cseq_ST_st20_fsm_19();
    void thread_ap_sig_cseq_ST_st21_fsm_20();
    void thread_ap_sig_cseq_ST_st22_fsm_21();
    void thread_ap_sig_cseq_ST_st23_fsm_22();
    void thread_ap_sig_cseq_ST_st24_fsm_23();
    void thread_ap_sig_cseq_ST_st25_fsm_24();
    void thread_ap_sig_cseq_ST_st26_fsm_25();
    void thread_ap_sig_cseq_ST_st2_fsm_1();
    void thread_ap_sig_cseq_ST_st3_fsm_2();
    void thread_ap_sig_cseq_ST_st4_fsm_3();
    void thread_ap_sig_cseq_ST_st5_fsm_4();
    void thread_ap_sig_cseq_ST_st6_fsm_5();
    void thread_ap_sig_cseq_ST_st7_fsm_6();
    void thread_ap_sig_cseq_ST_st8_fsm_7();
    void thread_ap_sig_cseq_ST_st9_fsm_8();
    void thread_e_5_fu_519_p2();
    void thread_e_6_fu_579_p2();
    void thread_e_7_fu_642_p2();
    void thread_e_8_fu_711_p2();
    void thread_e_9_fu_773_p2();
    void thread_exitcond10_fu_705_p2();
    void thread_exitcond11_fu_767_p2();
    void thread_exitcond1_fu_460_p2();
    void thread_exitcond2_fu_477_p2();
    void thread_exitcond3_fu_513_p2();
    void thread_exitcond4_fu_552_p2();
    void thread_exitcond5_fu_607_p2();
    void thread_exitcond6_fu_573_p2();
    void thread_exitcond7_fu_676_p2();
    void thread_exitcond8_fu_636_p2();
    void thread_exitcond9_fu_738_p2();
    void thread_exitcond_fu_830_p2();
    void thread_i_10_fu_613_p2();
    void thread_i_11_fu_682_p2();
    void thread_i_12_fu_744_p2();
    void thread_i_14_fu_558_p2();
    void thread_i_16_fu_818_p2();
    void thread_i_17_fu_836_p2();
    void thread_i_8_fu_466_p2();
    void thread_i_9_fu_483_p2();
    void thread_in_data_V_address0();
    void thread_in_data_V_ce0();
    void thread_in_last_V_address0();
    void thread_in_last_V_address1();
    void thread_in_last_V_ce0();
    void thread_in_last_V_ce1();
    void thread_in_last_V_d0();
    void thread_in_last_V_d1();
    void thread_in_last_V_we0();
    void thread_in_last_V_we1();
    void thread_matrix_addr1_cast_fu_763_p1();
    void thread_matrix_addr1_fu_543_p2();
    void thread_matrix_addr2_fu_783_p2();
    void thread_matrix_addr3_cast_fu_701_p1();
    void thread_matrix_addr4_fu_721_p2();
    void thread_matrix_addr5_cast_fu_632_p1();
    void thread_matrix_addr6_fu_652_p2();
    void thread_matrix_addr7_cast_fu_593_p1();
    void thread_matrix_addr8_fu_597_p2();
    void thread_matrix_addr9_cast_fu_509_p1();
    void thread_matrix_address0();
    void thread_matrix_ce0();
    void thread_matrix_d0();
    void thread_matrix_we0();
    void thread_min_4_min_1_fu_668_p3();
    void thread_out_data_V_address0();
    void thread_out_data_V_ce0();
    void thread_out_data_V_d0();
    void thread_out_data_V_we0();
    void thread_out_last_V_address0();
    void thread_out_last_V_ce0();
    void thread_out_last_V_d0();
    void thread_out_last_V_we0();
    void thread_result_address0();
    void thread_result_ce0();
    void thread_result_d0();
    void thread_result_we0();
    void thread_tmp_10_fu_619_p1();
    void thread_tmp_12_fu_501_p3();
    void thread_tmp_13_fu_688_p1();
    void thread_tmp_14_fu_662_p2();
    void thread_tmp_15_fu_548_p1();
    void thread_tmp_15_trn_cast_fu_648_p1();
    void thread_tmp_17_fu_750_p1();
    void thread_tmp_18_fu_624_p3();
    void thread_tmp_19_fu_731_p2();
    void thread_tmp_1_fu_472_p1();
    void thread_tmp_20_trn_cast_fu_717_p1();
    void thread_tmp_21_fu_813_p1();
    void thread_tmp_22_fu_824_p2();
    void thread_tmp_23_fu_793_p1();
    void thread_tmp_24_fu_799_p2();
    void thread_tmp_24_trn_cast_fu_779_p1();
    void thread_tmp_25_fu_842_p1();
    void thread_tmp_26_fu_693_p3();
    void thread_tmp_27_fu_585_p3();
    void thread_tmp_28_fu_602_p1();
    void thread_tmp_29_fu_755_p3();
    void thread_tmp_2_fu_564_p1();
    void thread_tmp_2_trn_cast_fu_569_p1();
    void thread_tmp_30_fu_657_p1();
    void thread_tmp_31_fu_726_p1();
    void thread_tmp_32_fu_788_p1();
    void thread_tmp_4_fu_493_p3();
    void thread_tmp_5_fu_489_p1();
    void thread_tmp_7_cast_fu_525_p1();
    void thread_tmp_8_fu_529_p2();
    void thread_tmp_9_fu_534_p1();
    void thread_tmp_fu_455_p1();
    void thread_tmp_trn_cast_fu_539_p1();
    void thread_vector_address0();
    void thread_vector_ce0();
    void thread_vector_d0();
    void thread_vector_we0();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
