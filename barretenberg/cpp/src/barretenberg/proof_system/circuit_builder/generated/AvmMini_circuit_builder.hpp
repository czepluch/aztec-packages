

// AUTOGENERATED FILE
#pragma once

#include "barretenberg/common/constexpr_utils.hpp"
#include "barretenberg/common/throw_or_abort.hpp"
#include "barretenberg/ecc/curves/bn254/fr.hpp"
#include "barretenberg/honk/proof_system/logderivative_library.hpp"
#include "barretenberg/proof_system/circuit_builder/circuit_builder_base.hpp"
#include "barretenberg/relations/generic_permutation/generic_permutation_relation.hpp"

#include "barretenberg/flavor/generated/AvmMini_flavor.hpp"
#include "barretenberg/relations/generated/AvmMini/alu_chip.hpp"
#include "barretenberg/relations/generated/AvmMini/avm_mini.hpp"
#include "barretenberg/relations/generated/AvmMini/mem_trace.hpp"

using namespace barretenberg;

namespace proof_system {

template <typename FF> struct AvmMiniFullRow {
    FF avmMini_clk{};
    FF avmMini_first{};
    FF memTrace_m_clk{};
    FF memTrace_m_sub_clk{};
    FF memTrace_m_addr{};
    FF memTrace_m_tag{};
    FF memTrace_m_val{};
    FF memTrace_m_lastAccess{};
    FF memTrace_m_last{};
    FF memTrace_m_rw{};
    FF memTrace_m_in_tag{};
    FF memTrace_m_tag_err{};
    FF memTrace_m_one_min_inv{};
    FF aluChip_alu_clk{};
    FF aluChip_alu_ia{};
    FF aluChip_alu_ib{};
    FF aluChip_alu_ic{};
    FF aluChip_alu_op_add{};
    FF aluChip_alu_op_sub{};
    FF aluChip_alu_op_mul{};
    FF aluChip_alu_op_div{};
    FF aluChip_alu_u8{};
    FF aluChip_alu_u16{};
    FF aluChip_alu_u32{};
    FF aluChip_alu_u64{};
    FF aluChip_alu_u128{};
    FF aluChip_alu_s1{};
    FF aluChip_alu_s2{};
    FF aluChip_alu_s3{};
    FF aluChip_alu_s4{};
    FF aluChip_alu_s5{};
    FF aluChip_alu_s6{};
    FF aluChip_alu_s7{};
    FF aluChip_alu_s8{};
    FF aluChip_alu_s9{};
    FF aluChip_alu_s10{};
    FF aluChip_alu_s11{};
    FF aluChip_alu_s12{};
    FF aluChip_alu_s13{};
    FF aluChip_alu_s14{};
    FF aluChip_alu_s15{};
    FF aluChip_alu_s16{};
    FF aluChip_alu_cf{};
    FF avmMini_pc{};
    FF avmMini_internal_return_ptr{};
    FF avmMini_sel_internal_call{};
    FF avmMini_sel_internal_return{};
    FF avmMini_sel_halt{};
    FF avmMini_sel_op_add{};
    FF avmMini_sel_op_sub{};
    FF avmMini_sel_op_mul{};
    FF avmMini_sel_op_div{};
    FF avmMini_in_tag{};
    FF avmMini_op_err{};
    FF avmMini_tag_err{};
    FF avmMini_inv{};
    FF avmMini_ia{};
    FF avmMini_ib{};
    FF avmMini_ic{};
    FF avmMini_mem_op_a{};
    FF avmMini_mem_op_b{};
    FF avmMini_mem_op_c{};
    FF avmMini_rwa{};
    FF avmMini_rwb{};
    FF avmMini_rwc{};
    FF avmMini_mem_idx_a{};
    FF avmMini_mem_idx_b{};
    FF avmMini_mem_idx_c{};
    FF avmMini_last{};
    FF avmMini_internal_return_ptr_shift{};
    FF avmMini_pc_shift{};
    FF memTrace_m_addr_shift{};
    FF memTrace_m_tag_shift{};
    FF memTrace_m_rw_shift{};
    FF memTrace_m_val_shift{};
};

class AvmMiniCircuitBuilder {
  public:
    using Flavor = proof_system::honk::flavor::AvmMiniFlavor;
    using FF = Flavor::FF;
    using Row = AvmMiniFullRow<FF>;

    // TODO: template
    using Polynomial = Flavor::Polynomial;
    using ProverPolynomials = Flavor::ProverPolynomials;

    static constexpr size_t num_fixed_columns = 75;
    static constexpr size_t num_polys = 69;
    std::vector<Row> rows;

    void set_trace(std::vector<Row>&& trace) { rows = std::move(trace); }

    ProverPolynomials compute_polynomials()
    {
        const auto num_rows = get_circuit_subgroup_size();
        ProverPolynomials polys;

        // Allocate mem for each column
        for (auto& poly : polys.get_all()) {
            poly = Polynomial(num_rows);
        }

        for (size_t i = 0; i < rows.size(); i++) {
            polys.avmMini_clk[i] = rows[i].avmMini_clk;
            polys.avmMini_first[i] = rows[i].avmMini_first;
            polys.memTrace_m_clk[i] = rows[i].memTrace_m_clk;
            polys.memTrace_m_sub_clk[i] = rows[i].memTrace_m_sub_clk;
            polys.memTrace_m_addr[i] = rows[i].memTrace_m_addr;
            polys.memTrace_m_tag[i] = rows[i].memTrace_m_tag;
            polys.memTrace_m_val[i] = rows[i].memTrace_m_val;
            polys.memTrace_m_lastAccess[i] = rows[i].memTrace_m_lastAccess;
            polys.memTrace_m_last[i] = rows[i].memTrace_m_last;
            polys.memTrace_m_rw[i] = rows[i].memTrace_m_rw;
            polys.memTrace_m_in_tag[i] = rows[i].memTrace_m_in_tag;
            polys.memTrace_m_tag_err[i] = rows[i].memTrace_m_tag_err;
            polys.memTrace_m_one_min_inv[i] = rows[i].memTrace_m_one_min_inv;
            polys.aluChip_alu_clk[i] = rows[i].aluChip_alu_clk;
            polys.aluChip_alu_ia[i] = rows[i].aluChip_alu_ia;
            polys.aluChip_alu_ib[i] = rows[i].aluChip_alu_ib;
            polys.aluChip_alu_ic[i] = rows[i].aluChip_alu_ic;
            polys.aluChip_alu_op_add[i] = rows[i].aluChip_alu_op_add;
            polys.aluChip_alu_op_sub[i] = rows[i].aluChip_alu_op_sub;
            polys.aluChip_alu_op_mul[i] = rows[i].aluChip_alu_op_mul;
            polys.aluChip_alu_op_div[i] = rows[i].aluChip_alu_op_div;
            polys.aluChip_alu_u8[i] = rows[i].aluChip_alu_u8;
            polys.aluChip_alu_u16[i] = rows[i].aluChip_alu_u16;
            polys.aluChip_alu_u32[i] = rows[i].aluChip_alu_u32;
            polys.aluChip_alu_u64[i] = rows[i].aluChip_alu_u64;
            polys.aluChip_alu_u128[i] = rows[i].aluChip_alu_u128;
            polys.aluChip_alu_s1[i] = rows[i].aluChip_alu_s1;
            polys.aluChip_alu_s2[i] = rows[i].aluChip_alu_s2;
            polys.aluChip_alu_s3[i] = rows[i].aluChip_alu_s3;
            polys.aluChip_alu_s4[i] = rows[i].aluChip_alu_s4;
            polys.aluChip_alu_s5[i] = rows[i].aluChip_alu_s5;
            polys.aluChip_alu_s6[i] = rows[i].aluChip_alu_s6;
            polys.aluChip_alu_s7[i] = rows[i].aluChip_alu_s7;
            polys.aluChip_alu_s8[i] = rows[i].aluChip_alu_s8;
            polys.aluChip_alu_s9[i] = rows[i].aluChip_alu_s9;
            polys.aluChip_alu_s10[i] = rows[i].aluChip_alu_s10;
            polys.aluChip_alu_s11[i] = rows[i].aluChip_alu_s11;
            polys.aluChip_alu_s12[i] = rows[i].aluChip_alu_s12;
            polys.aluChip_alu_s13[i] = rows[i].aluChip_alu_s13;
            polys.aluChip_alu_s14[i] = rows[i].aluChip_alu_s14;
            polys.aluChip_alu_s15[i] = rows[i].aluChip_alu_s15;
            polys.aluChip_alu_s16[i] = rows[i].aluChip_alu_s16;
            polys.aluChip_alu_cf[i] = rows[i].aluChip_alu_cf;
            polys.avmMini_pc[i] = rows[i].avmMini_pc;
            polys.avmMini_internal_return_ptr[i] = rows[i].avmMini_internal_return_ptr;
            polys.avmMini_sel_internal_call[i] = rows[i].avmMini_sel_internal_call;
            polys.avmMini_sel_internal_return[i] = rows[i].avmMini_sel_internal_return;
            polys.avmMini_sel_halt[i] = rows[i].avmMini_sel_halt;
            polys.avmMini_sel_op_add[i] = rows[i].avmMini_sel_op_add;
            polys.avmMini_sel_op_sub[i] = rows[i].avmMini_sel_op_sub;
            polys.avmMini_sel_op_mul[i] = rows[i].avmMini_sel_op_mul;
            polys.avmMini_sel_op_div[i] = rows[i].avmMini_sel_op_div;
            polys.avmMini_in_tag[i] = rows[i].avmMini_in_tag;
            polys.avmMini_op_err[i] = rows[i].avmMini_op_err;
            polys.avmMini_tag_err[i] = rows[i].avmMini_tag_err;
            polys.avmMini_inv[i] = rows[i].avmMini_inv;
            polys.avmMini_ia[i] = rows[i].avmMini_ia;
            polys.avmMini_ib[i] = rows[i].avmMini_ib;
            polys.avmMini_ic[i] = rows[i].avmMini_ic;
            polys.avmMini_mem_op_a[i] = rows[i].avmMini_mem_op_a;
            polys.avmMini_mem_op_b[i] = rows[i].avmMini_mem_op_b;
            polys.avmMini_mem_op_c[i] = rows[i].avmMini_mem_op_c;
            polys.avmMini_rwa[i] = rows[i].avmMini_rwa;
            polys.avmMini_rwb[i] = rows[i].avmMini_rwb;
            polys.avmMini_rwc[i] = rows[i].avmMini_rwc;
            polys.avmMini_mem_idx_a[i] = rows[i].avmMini_mem_idx_a;
            polys.avmMini_mem_idx_b[i] = rows[i].avmMini_mem_idx_b;
            polys.avmMini_mem_idx_c[i] = rows[i].avmMini_mem_idx_c;
            polys.avmMini_last[i] = rows[i].avmMini_last;
        }

        polys.avmMini_internal_return_ptr_shift = Polynomial(polys.avmMini_internal_return_ptr.shifted());
        polys.avmMini_pc_shift = Polynomial(polys.avmMini_pc.shifted());
        polys.memTrace_m_addr_shift = Polynomial(polys.memTrace_m_addr.shifted());
        polys.memTrace_m_tag_shift = Polynomial(polys.memTrace_m_tag.shifted());
        polys.memTrace_m_rw_shift = Polynomial(polys.memTrace_m_rw.shifted());
        polys.memTrace_m_val_shift = Polynomial(polys.memTrace_m_val.shifted());

        return polys;
    }

    [[maybe_unused]] bool check_circuit()
    {

        auto polys = compute_polynomials();
        const size_t num_rows = polys.get_polynomial_size();

        const auto evaluate_relation = [&]<typename Relation>(const std::string& relation_name,
                                                              std::string (*debug_label)(int)) {
            typename Relation::SumcheckArrayOfValuesOverSubrelations result;
            for (auto& r : result) {
                r = 0;
            }
            constexpr size_t NUM_SUBRELATIONS = result.size();

            for (size_t i = 0; i < num_rows; ++i) {
                Relation::accumulate(result, polys.get_row(i), {}, 1);

                bool x = true;
                for (size_t j = 0; j < NUM_SUBRELATIONS; ++j) {
                    if (result[j] != 0) {
                        std::string row_name = debug_label(static_cast<int>(j));
                        throw_or_abort(
                            format("Relation ", relation_name, ", subrelation index ", row_name, " failed at row ", i));
                        x = false;
                    }
                }
                if (!x) {
                    return false;
                }
            }
            return true;
        };

        if (!evaluate_relation.template operator()<AvmMini_vm::alu_chip<FF>>("alu_chip",
                                                                             AvmMini_vm::get_relation_label_alu_chip)) {
            return false;
        }
        if (!evaluate_relation.template operator()<AvmMini_vm::avm_mini<FF>>("avm_mini",
                                                                             AvmMini_vm::get_relation_label_avm_mini)) {
            return false;
        }
        if (!evaluate_relation.template operator()<AvmMini_vm::mem_trace<FF>>(
                "mem_trace", AvmMini_vm::get_relation_label_mem_trace)) {
            return false;
        }

        return true;
    }

    [[nodiscard]] size_t get_num_gates() const { return rows.size(); }

    [[nodiscard]] size_t get_circuit_subgroup_size() const
    {
        const size_t num_rows = get_num_gates();
        const auto num_rows_log2 = static_cast<size_t>(numeric::get_msb64(num_rows));
        size_t num_rows_pow2 = 1UL << (num_rows_log2 + (1UL << num_rows_log2 == num_rows ? 0 : 1));
        return num_rows_pow2;
    }
};
} // namespace proof_system
