
/* WARNING: Unknown calling convention: __rustcall */
/* <rust_tuesday::BruteForce as rust_tuesday::PairSearch>::find */

void __rustcall
<rust_tuesday::BruteForce_as_rust_tuesday::PairSearch>::find
          (undefined8 *param_1,undefined8 param_2,long param_3,ulong param_4,int param_5)

{
  ulong uVar2;
  undefined1 auVar3 [16];
  ulong local_f0;
  ulong local_e8;
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined8 local_50;
  long local_48;
  ulong local_40;
  int local_34;
  ulong local_30;
  ulong local_28;
  int local_1c;
  int local_18;
  int local_14;
  ulong uVar1;

  local_50 = param_2;
  local_48 = param_3;
  local_40 = param_4;
  local_34 = param_5;
  local_90 = <I_as_core::iter::traits::collect::IntoIterator>::into_iter(0);
  auVar3._8_8_ = local_60._8_8_;
  auVar3._0_8_ = local_60._0_8_;
  do {
    local_60 = auVar3;
    auVar3 = core::iter::range::
             <impl_core::iter::traits::iterator::Iterator_for_core::ops::range::Range<A>>::next
                       (local_90);
    uVar1 = auVar3._8_8_;
    if ((auVar3._0_8_ & 1) == 0) {
      *param_1 = 0;
      return;
    }
    local_30 = uVar1;
    local_80 = auVar3;
    auVar3 = <I_as_core::iter::traits::collect::IntoIterator>::into_iter(0);
    local_70 = auVar3;
    auVar3 = local_60;
    while( true ) {
      local_60 = auVar3;
      auVar3 = core::iter::range::
               <impl_core::iter::traits::iterator::Iterator_for_core::ops::range::Range<A>>::next
                         (local_70);
      uVar2 = auVar3._8_8_;
      if ((auVar3._0_8_ & 1) == 0) break;
      local_28 = uVar2;
      local_60 = auVar3;
      if (param_4 <= uVar2) {
                    /* WARNING: Subroutine does not return */
        core::panicking::panic_bounds_check(uVar2,param_4,&PTR_s_src_lib_rs_100058370);
      }
      local_14 = *(int *)(param_3 + uVar2 * 4);
      if (param_4 <= uVar1) {
                    /* WARNING: Subroutine does not return */
        core::panicking::panic_bounds_check(uVar1,param_4,&PTR_s_src_lib_rs_100058388);
      }
      local_18 = *(int *)(param_3 + uVar1 * 4);
      if (SCARRY8((long)local_14,(long)local_18)) {
        core::panicking::panic_const::panic_const_add_overflow(&PTR_s_src_lib_rs_1000583a0);
        goto LAB_100005d64;
      }
      local_f0 = uVar1;
      local_e8 = uVar2;
      local_1c = param_5;
      if ((long)local_14 + (long)local_18 == (long)param_5) {
LAB_100005d64:
        param_1[1] = local_e8;
        param_1[2] = local_f0;
        *param_1 = 1;
        return;
      }
    }
  } while( true );
}
