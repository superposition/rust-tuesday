
/* WARNING: Unknown calling convention: __rustcall */
/* <rust_tuesday::HashLookup as rust_tuesday::PairSearch>::find */

void __rustcall
<rust_tuesday::HashLookup_as_rust_tuesday::PairSearch>::find
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,int param_5)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  undefined1 auVar5 [16];
  undefined1 auStack_130 [48];
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined1 auStack_e8 [24];
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined1 local_b0 [16];
  long local_a0;
  undefined8 *local_98;
  undefined1 auStack_90 [24];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  int local_5c;
  undefined8 local_48;
  int local_3c;
  undefined8 local_38;
  int local_2c;
  int local_28;
  int local_24;

  local_78 = param_2;
  local_70 = param_3;
  local_68 = param_4;
  local_5c = param_5;
  std::collections::hash::map::HashMap<K,V>::new(auStack_130);
  auVar5 = core::slice::<impl[T]>::iter(param_3,param_4);
  core::iter::traits::iterator::Iterator::enumerate(auStack_e8,auVar5._0_8_,auVar5._8_8_);
  <I_as_core::iter::traits::collect::IntoIterator>::into_iter(&local_100,auStack_e8);
  uStack_c8 = uStack_f8;
  local_d0 = local_100;
  local_c0 = local_f0;
  while( true ) {
    auVar5 = <core::iter::adapters::enumerate::Enumerate<I>as_core::iter::traits::iterator::Iterator>
             ::next(&local_d0);
    uVar3 = auVar5._0_8_;
    local_b0 = auVar5;
    if (auVar5._8_8_ == (int *)0x0) {
      *param_1 = 0;
      core::ptr::drop_in_place<std::collections::hash::map::HashMap<i64,usize>>(auStack_130);
      return;
    }
    iVar1 = *auVar5._8_8_;
    lVar4 = (long)iVar1;
    local_48 = uVar3;
    local_3c = iVar1;
    local_28 = iVar1;
    local_24 = param_5;
    if (SBORROW8((long)param_5,lVar4)) break;
    local_a0 = param_5 - lVar4;
    local_98 = (undefined8 *)std::collections::hash::map::HashMap<K,V,S>::get(auStack_130,&local_a0)
    ;
    if (local_98 != (undefined8 *)0x0) {
      local_38 = *local_98;
      param_1[1] = local_38;
      param_1[2] = uVar3;
      *param_1 = 1;
      core::ptr::drop_in_place<std::collections::hash::map::HashMap<i64,usize>>(auStack_130);
      return;
    }
    local_2c = iVar1;
    std::collections::hash::map::HashMap<K,V,S>::entry(auStack_90,auStack_130,lVar4);
    std::collections::hash::map::Entry<K,V>::or_insert(auStack_90,uVar3);
  }
  core::panicking::panic_const::panic_const_sub_overflow(&PTR_s_src_lib_rs_1000583b8);
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x100005f34);
  (*pcVar2)();
}
