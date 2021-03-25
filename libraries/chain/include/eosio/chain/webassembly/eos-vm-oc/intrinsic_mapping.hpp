#pragma once

#include <array>
#include <limits>
#include <string_view>

namespace eosio { namespace chain { namespace eosvmoc {
//NEVER reorder or remove indexes; the PIC uses the indexes in this table as an offset in to a jump
// table. Adding on the bottom is fine and requires no other updates elsewhere
namespace detail {
   template <typename... Args>
   inline constexpr auto generate_table( Args&&... args ) {
      return std::array<std::string_view, sizeof...(Args)> { args... };
   }
} // ns eosio::chain::eosvmoc::detail

inline constexpr auto get_intrinsic_table() {
   return detail::generate_table(
      "eosvmoc_internal.unreachable",
      "eosvmoc_internal.grow_memory",
      "eosvmoc_internal.div0_or_overflow",
      "eosvmoc_internal.indirect_call_mismatch",
      "eosvmoc_internal.indirect_call_oob",
      "eosvmoc_internal.depth_assert",
      "eosio_injection.call_depth_assert",  //these two are never used by EOS VM OC but all intrinsics
      "eosio_injection.checktime",          //must be mapped
      "env.__ashlti3",
      "env.__ashrti3",
      "env.__lshlti3",
      "env.__lshrti3",
      "env.__divti3",
      "env.__udivti3",
      "env.__modti3",
      "env.__umodti3",
      "env.__multi3",
      "env.__addtf3",
      "env.__subtf3",
      "env.__multf3",
      "env.__divtf3",
      "env.__eqtf2",
      "env.__netf2",
      "env.__getf2",
      "env.__gttf2",
      "env.__lttf2",
      "env.__letf2",
      "env.__cmptf2",
      "env.__unordtf2",
      "env.__negtf2",
      "env.__floatsitf",
      "env.__floatunsitf",
      "env.__floatditf",
      "env.__floatunditf",
      "env.__floattidf",
      "env.__floatuntidf",
      "env.__floatsidf",
      "env.__extendsftf2",
      "env.__extenddftf2",
      "env.__fixtfti",
      "env.__fixtfdi",
      "env.__fixtfsi",
      "env.__fixunstfti",
      "env.__fixunstfdi",
      "env.__fixunstfsi",
      "env.__fixsfti",
      "env.__fixdfti",
      "env.__fixunssfti",
      "env.__fixunsdfti",
      "env.__trunctfdf2",
      "env.__trunctfsf2",
      "env.is_feature_active",
      "env.activate_feature",
      "env.get_resource_limits",
      "env.set_resource_limits",
      "env.set_proposed_producers",
      "env.set_proposed_producers_ex",
      "env.get_blockchain_parameters_packed",
      "env.set_blockchain_parameters_packed",
      "env.is_privileged",
      "env.set_privileged",
      "env.preactivate_feature",
      "env.get_active_producers",
      "env.db_store_i64",
      "env.db_update_i64",
      "env.db_remove_i64",
      "env.db_get_i64",
      "env.db_next_i64",
      "env.db_previous_i64",
      "env.db_find_i64",
      "env.db_lowerbound_i64",
      "env.db_upperbound_i64",
      "env.db_end_i64",
      "env.db_idx64_store",
      "env.db_idx64_remove",
      "env.db_idx64_update",
      "env.db_idx64_find_primary",
      "env.db_idx64_find_secondary",
      "env.db_idx64_lowerbound",
      "env.db_idx64_upperbound",
      "env.db_idx64_end",
      "env.db_idx64_next",
      "env.db_idx64_previous",
      "env.db_idx128_store",
      "env.db_idx128_remove",
      "env.db_idx128_update",
      "env.db_idx128_find_primary",
      "env.db_idx128_find_secondary",
      "env.db_idx128_lowerbound",
      "env.db_idx128_upperbound",
      "env.db_idx128_end",
      "env.db_idx128_next",
      "env.db_idx128_previous",
      "env.db_idx_double_store",
      "env.db_idx_double_remove",
      "env.db_idx_double_update",
      "env.db_idx_double_find_primary",
      "env.db_idx_double_find_secondary",
      "env.db_idx_double_lowerbound",
      "env.db_idx_double_upperbound",
      "env.db_idx_double_end",
      "env.db_idx_double_next",
      "env.db_idx_double_previous",
      "env.db_idx_long_double_store",
      "env.db_idx_long_double_remove",
      "env.db_idx_long_double_update",
      "env.db_idx_long_double_find_primary",
      "env.db_idx_long_double_find_secondary",
      "env.db_idx_long_double_lowerbound",
      "env.db_idx_long_double_upperbound",
      "env.db_idx_long_double_end",
      "env.db_idx_long_double_next",
      "env.db_idx_long_double_previous",
      "env.db_idx256_store",
      "env.db_idx256_remove",
      "env.db_idx256_update",
      "env.db_idx256_find_primary",
      "env.db_idx256_find_secondary",
      "env.db_idx256_lowerbound",
      "env.db_idx256_upperbound",
      "env.db_idx256_end",
      "env.db_idx256_next",
      "env.db_idx256_previous",
      "env.assert_recover_key",
      "env.recover_key",
      "env.assert_sha256",
      "env.assert_sha1",
      "env.assert_sha512",
      "env.assert_ripemd160",
      "env.sha1",
      "env.sha256",
      "env.sha512",
      "env.ripemd160",
      "env.check_transaction_authorization",
      "env.check_permission_authorization",
      "env.get_permission_last_used",
      "env.get_account_creation_time",
      "env.current_time",
      "env.publication_time",
      "env.is_feature_activated",
      "env.get_sender",
      "env.abort",
      "env.eosio_assert",
      "env.eosio_assert_message",
      "env.eosio_assert_code",
      "env.eosio_exit",
      "env.read_action_data",
      "env.action_data_size",
      "env.current_receiver",
      "env.require_recipient",
      "env.require_auth",
      "env.require_auth2",
      "env.has_auth",
      "env.is_account",
      "env.prints",
      "env.prints_l",
      "env.printi",
      "env.printui",
      "env.printi128",
      "env.printui128",
      "env.printsf",
      "env.printdf",
      "env.printqf",
      "env.printn",
      "env.printhex",
      "env.read_transaction",
      "env.transaction_size",
      "env.expiration",
      "env.tapos_block_prefix",
      "env.tapos_block_num",
      "env.get_action",
      "env.send_inline",
      "env.send_context_free_inline",
      "env.send_deferred",
      "env.cancel_deferred",
      "env.get_context_free_data",
      "env.memcpy",
      "env.memmove",
      "env.memcmp",
      "env.memset",
      "eosio_injection._eosio_f32_add",
      "eosio_injection._eosio_f32_sub",
      "eosio_injection._eosio_f32_mul",
      "eosio_injection._eosio_f32_div",
      "eosio_injection._eosio_f32_min",
      "eosio_injection._eosio_f32_max",
      "eosio_injection._eosio_f32_copysign",
      "eosio_injection._eosio_f32_abs",
      "eosio_injection._eosio_f32_neg",
      "eosio_injection._eosio_f32_sqrt",
      "eosio_injection._eosio_f32_ceil",
      "eosio_injection._eosio_f32_floor",
      "eosio_injection._eosio_f32_trunc",
      "eosio_injection._eosio_f32_nearest",
      "eosio_injection._eosio_f32_eq",
      "eosio_injection._eosio_f32_ne",
      "eosio_injection._eosio_f32_lt",
      "eosio_injection._eosio_f32_le",
      "eosio_injection._eosio_f32_gt",
      "eosio_injection._eosio_f32_ge",
      "eosio_injection._eosio_f64_add",
      "eosio_injection._eosio_f64_sub",
      "eosio_injection._eosio_f64_mul",
      "eosio_injection._eosio_f64_div",
      "eosio_injection._eosio_f64_min",
      "eosio_injection._eosio_f64_max",
      "eosio_injection._eosio_f64_copysign",
      "eosio_injection._eosio_f64_abs",
      "eosio_injection._eosio_f64_neg",
      "eosio_injection._eosio_f64_sqrt",
      "eosio_injection._eosio_f64_ceil",
      "eosio_injection._eosio_f64_floor",
      "eosio_injection._eosio_f64_trunc",
      "eosio_injection._eosio_f64_nearest",
      "eosio_injection._eosio_f64_eq",
      "eosio_injection._eosio_f64_ne",
      "eosio_injection._eosio_f64_lt",
      "eosio_injection._eosio_f64_le",
      "eosio_injection._eosio_f64_gt",
      "eosio_injection._eosio_f64_ge",
      "eosio_injection._eosio_f32_promote",
      "eosio_injection._eosio_f64_demote",
      "eosio_injection._eosio_f32_trunc_i32s",
      "eosio_injection._eosio_f64_trunc_i32s",
      "eosio_injection._eosio_f32_trunc_i32u",
      "eosio_injection._eosio_f64_trunc_i32u",
      "eosio_injection._eosio_f32_trunc_i64s",
      "eosio_injection._eosio_f64_trunc_i64s",
      "eosio_injection._eosio_f32_trunc_i64u",
      "eosio_injection._eosio_f64_trunc_i64u",
      "eosio_injection._eosio_i32_to_f32",
      "eosio_injection._eosio_i64_to_f32",
      "eosio_injection._eosio_ui32_to_f32",
      "eosio_injection._eosio_ui64_to_f32",
      "eosio_injection._eosio_i32_to_f64",
      "eosio_injection._eosio_i64_to_f64",
      "eosio_injection._eosio_ui32_to_f64",
      "eosio_injection._eosio_ui64_to_f64",
      "env.set_action_return_value",
      "env.kv_erase",
      "env.kv_set",
      "env.kv_get",
      "env.kv_get_data",
      "env.kv_it_create",
      "env.kv_it_destroy",
      "env.kv_it_status",
      "env.kv_it_compare",
      "env.kv_it_key_compare",
      "env.kv_it_move_to_end",
      "env.kv_it_next",
      "env.kv_it_prev",
      "env.kv_it_lower_bound",
      "env.kv_it_key",
      "env.kv_it_value",
      "env.get_resource_limit",
      "env.set_resource_limit",
      "env.get_kv_parameters_packed",
      "env.set_kv_parameters_packed",
      "env.get_wasm_parameters_packed",
      "env.set_wasm_parameters_packed",
      "env.get_parameters_packed",
      "env.set_parameters_packed",
      "env.propose_security_group_participants_add",
      "env.propose_security_group_participants_remove",
      "env.in_active_security_group",
      "env.get_active_security_group",
      "env.register_transaction_hook",
      "env.set_transaction_resource_payer"
   );
}
inline constexpr std::size_t find_intrinsic_index(std::string_view hf) {
   constexpr auto hosts = get_intrinsic_table();
   for (  std::size_t i = 0; i < hosts.size(); ++i )
      if ( hosts[i] == hf )
         return i;
   return std::numeric_limits<std::size_t>::max();
}

inline constexpr std::size_t intrinsic_table_size() {
    return std::tuple_size<decltype(get_intrinsic_table())>::value;
}
}}}
