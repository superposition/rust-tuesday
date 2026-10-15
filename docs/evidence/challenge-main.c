
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_100000e20(void)

{
  undefined *****pppppuVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined *****pppppuVar4;
  code *pcVar5;
  undefined ****ppppuVar6;
  ulong uVar7;
  code *pcVar8;
  undefined ******ppppppuVar9;
  undefined *****pppppuVar10;
  ulong uVar11;
  code *pcVar12;
  undefined *****pppppuVar13;
  bool bVar14;
  undefined *****pppppuVar15;
  undefined1 auVar16 [12];
  undefined *****local_140;
  code *pcStack_138;
  undefined ******local_130;
  undefined *****local_128;
  undefined ****local_120;
  undefined4 *****pppppuStack_118;
  undefined4 local_110;
  undefined4 *****local_100;
  code *pcStack_f8;
  undefined4 *****local_f0;
  code *local_e8;
  long local_e0;
  undefined ****local_d8;
  undefined *****local_d0;
  code *local_c8;
  undefined4 *****pppppuStack_c0;
  undefined *****local_b8;
  undefined ****local_b0;
  undefined *****local_a8;
  undefined *****local_a0;
  code *pcStack_98;
  undefined ******local_90;
  code *local_88;
  long local_80;
  undefined4 *****pppppuStack_78;

  std::env::args(&local_100);
  local_e0 = 0;
  <std::env::Args_as_core::iter::traits::iterator::Iterator>::next(&local_140,&local_100);
  if (local_140 == (undefined *****)0x8000000000000000) {
LAB_100000e94:
    __rustc[de2ca18b4c54d5b8]::__rust_no_alloc_shim_is_unstable_v2();
    pcVar5 = (code *)__rustc[de2ca18b4c54d5b8]::__rust_alloc(0x37,1);
    if (pcVar5 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      alloc::raw_vec::handle_error(1,0x37,&PTR_s__LOCAL_HOME__rustup_too_100048070);
    }
    *(undefined8 *)(pcVar5 + 8) = 0x646e69662d726961;
    *(undefined8 *)pcVar5 = 0x70203a6567617375;
    *(undefined8 *)(pcVar5 + 0x18) = 0x7465677261743c20;
    *(undefined8 *)(pcVar5 + 0x10) = 0x3e627c613c207265;
    *(undefined8 *)(pcVar5 + 0x28) = 0x693a737265626d75;
    *(undefined8 *)(pcVar5 + 0x20) = 0x6e5b203e3233693a;
    uVar11 = (ulong)pcVar5 >> 0x20;
    *(char (*) [8])(pcVar5 + 0x2f) = (char  [8])0x5d2e2e2e20323369;
    ppppppuVar9 = (undefined ******)0x37;
    pppppuVar13 = (undefined *****)0x37;
  }
  else {
    if (local_140 != (undefined *****)0x0) {
      __rustc[de2ca18b4c54d5b8]::__rust_dealloc(pcStack_138,local_140,1);
    }
    <std::env::Args_as_core::iter::traits::iterator::Iterator>::next(&local_a0,&local_100);
    pcVar8 = pcStack_98;
    pppppuVar4 = local_a0;
    if (local_a0 == (undefined *****)0x8000000000000000) goto LAB_100000e94;
    if ((local_90 == (undefined ******)0x1) && ((byte)*pcStack_98 - 0x61 < 2)) {
      if (local_e0 == 0) {
        <std::env::Args_as_core::iter::traits::iterator::Iterator>::next(&local_140,&local_100);
      }
      else {
        local_e0 = 0;
        FUN_100000bd0(&local_140,&local_100);
      }
      pcVar3 = pcStack_138;
      pppppuVar1 = local_140;
      if (local_140 == (undefined *****)0x8000000000000000) goto LAB_100000f84;
      FUN_100000c74(&local_140,pcStack_138,local_130);
      uVar2 = pcStack_138._0_4_;
      pcVar5 = (code *)((ulong)pcStack_138 & 0xffffffff);
      bVar14 = local_140 != (undefined *****)0x8000000000000000;
      ppppppuVar9 = local_130;
      pppppuVar13 = local_140;
      pcVar12 = pcStack_138;
      if (local_140 == (undefined *****)0x8000000000000000) {
        pcStack_98 = pcStack_f8;
        local_a0 = (undefined *****)local_100;
        local_88 = local_e8;
        local_90 = (undefined ******)local_f0;
        local_d0 = (undefined *****)0x8000000000000000;
        pppppuStack_78 = (undefined4 *****)&local_d0;
        local_80 = local_e0;
        auVar16 = FUN_100000888(&local_a0);
        if ((auVar16._0_8_ & 1) == 0) {
          if ((long)local_88 - (long)pcStack_98 != 0) {
            uVar11 = (ulong)((long)local_88 - (long)pcStack_98) / 0x18;
            pcVar12 = pcStack_98 + 8;
            do {
              if (*(long *)(pcVar12 + -8) != 0) {
                __rustc[de2ca18b4c54d5b8]::__rust_dealloc
                          (*(undefined8 *)pcVar12,*(long *)(pcVar12 + -8),1);
              }
              pcVar12 = pcVar12 + 0x18;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          if (local_90 != (undefined ******)0x0) {
            __rustc[de2ca18b4c54d5b8]::__rust_dealloc(local_a0,(long)local_90 * 0x18,8);
          }
          pppppuVar10 = (undefined *****)0x0;
          ppppuVar6 = (undefined ****)0x4;
          pppppuVar15 = (undefined *****)0x0;
        }
        else {
          __rustc[de2ca18b4c54d5b8]::__rust_no_alloc_shim_is_unstable_v2();
          ppppuVar6 = (undefined ****)__rustc[de2ca18b4c54d5b8]::__rust_alloc(0x10,4);
          if (ppppuVar6 == (undefined ****)0x0) {
                    /* WARNING: Subroutine does not return */
            alloc::raw_vec::handle_error(4,0x10,&PTR_s__LOCAL_HOME__rustup_too_100048040);
          }
          *(int *)ppppuVar6 = auVar16._8_4_;
          local_b8 = (undefined *****)0x4;
          local_a8 = (undefined *****)0x1;
          pcStack_138 = pcStack_98;
          local_140 = local_a0;
          local_128 = (undefined *****)local_88;
          local_130 = local_90;
          pppppuStack_118 = pppppuStack_78;
          local_120 = (undefined ****)local_80;
          local_b0 = ppppuVar6;
          while( true ) {
            pppppuVar10 = local_a8;
            auVar16 = FUN_100000888(&local_140);
            if ((auVar16._0_8_ & 1) == 0) break;
            if (pppppuVar10 == local_b8) {
              FUN_100033e14(&local_b8,pppppuVar10);
              ppppuVar6 = local_b0;
            }
            *(int *)((long)ppppuVar6 + (long)pppppuVar10 * 4) = auVar16._8_4_;
            local_a8 = (undefined *****)((long)pppppuVar10 + 1);
          }
          if ((long)local_128 - (long)pcStack_138 != 0) {
            uVar11 = (ulong)((long)local_128 - (long)pcStack_138) / 0x18;
            pcVar12 = pcStack_138 + 8;
            do {
              if (*(long *)(pcVar12 + -8) != 0) {
                __rustc[de2ca18b4c54d5b8]::__rust_dealloc
                          (*(undefined8 *)pcVar12,*(long *)(pcVar12 + -8),1);
              }
              pcVar12 = pcVar12 + 0x18;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
          }
          ppppuVar6 = local_b0;
          pppppuVar15 = local_b8;
          if (local_130 != (undefined ******)0x0) {
            __rustc[de2ca18b4c54d5b8]::__rust_dealloc(local_140,(long)local_130 * 0x18,8);
            ppppuVar6 = local_b0;
            pppppuVar15 = local_b8;
          }
        }
        pppppuVar13 = local_d0;
        if (local_d0 == (undefined *****)0x8000000000000000) {
          if (pppppuVar1 != (undefined *****)0x0) {
            __rustc[de2ca18b4c54d5b8]::__rust_dealloc(pcVar3,pppppuVar1,1);
          }
          local_140 = pppppuVar4;
          pcStack_138 = pcVar8;
          local_130 = (undefined ******)0x1;
          local_110 = uVar2;
          local_128 = pppppuVar15;
          local_120 = ppppuVar6;
          pppppuStack_118 = (undefined4 *****)pppppuVar10;
          if (*pcVar8 == (code)0x62) {
            <rust_tuesday::HashLookup_as_rust_tuesday::PairSearch>::find
                      (&local_b8,1,ppppuVar6,pppppuVar10,pcVar5);
          }
          else {
            if (*pcVar8 != (code)0x61) {
              local_a0 = (undefined *****)&PTR_s_internal_error__entered_unreacha_100048088;
              pcStack_98 = (code *)0x1;
              local_88 = (code *)0x0;
              local_80 = 0;
              local_90 = (undefined ******)0x8;
                    /* WARNING: Subroutine does not return */
              core::panicking::panic_fmt(&local_a0,&PTR_s_src_main_rs_100048098);
            }
            <rust_tuesday::BruteForce_as_rust_tuesday::PairSearch>::find
                      (&local_b8,1,ppppuVar6,pppppuVar10,pcVar5);
          }
          if ((int)local_b8 == 1) {
            local_d8 = local_b0;
            local_d0 = local_a8;
            local_100 = (undefined4 *****)&local_d8;
            pcStack_f8 = core::fmt::num::imp::<impl_core::fmt::Display_for_usize>::fmt;
            local_f0 = (undefined4 *****)&local_d0;
            local_e8 = core::fmt::num::imp::<impl_core::fmt::Display_for_usize>::fmt;
            local_a0 = (undefined *****)&DAT_1000480d0;
            pcStack_98 = (code *)0x3;
            local_90 = (undefined ******)&local_100;
            local_88 = (code *)0x2;
            local_80 = 0;
            std::io::stdio::_print(&local_a0);
          }
          else {
            local_a0 = (undefined *****)&PTR_s_none_1000480c0;
            pcStack_98 = (code *)0x1;
            local_88 = (code *)0x0;
            local_80 = 0;
            local_90 = (undefined ******)&DAT_00000008;
            std::io::stdio::_print(&local_a0);
          }
          if (pppppuVar4 != (undefined *****)0x0) {
            __rustc[de2ca18b4c54d5b8]::__rust_dealloc(pcVar8,pppppuVar4,1);
          }
          if (pppppuVar15 != (undefined *****)0x0) {
            __rustc[de2ca18b4c54d5b8]::__rust_dealloc(ppppuVar6,(long)pppppuVar15 << 2,4);
          }
          return 0;
        }
        pcVar5 = local_c8;
        ppppppuVar9 = (undefined ******)pppppuStack_c0;
        pcVar12 = local_c8;
        if (pppppuVar15 != (undefined *****)0x0) {
          __rustc[de2ca18b4c54d5b8]::__rust_dealloc(ppppuVar6,(long)pppppuVar15 << 2,4);
        }
      }
      uVar11 = (ulong)pcVar12 >> 0x20;
      if (pppppuVar1 != (undefined *****)0x0) {
        __rustc[de2ca18b4c54d5b8]::__rust_dealloc(pcVar3,pppppuVar1,1);
      }
    }
    else {
LAB_100000f84:
      __rustc[de2ca18b4c54d5b8]::__rust_no_alloc_shim_is_unstable_v2();
      pcVar5 = (code *)__rustc[de2ca18b4c54d5b8]::__rust_alloc(0x37,1);
      if (pcVar5 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
        alloc::raw_vec::handle_error(1,0x37,&PTR_s__LOCAL_HOME__rustup_too_100048070);
      }
      *(undefined8 *)(pcVar5 + 8) = 0x646e69662d726961;
      *(undefined8 *)pcVar5 = 0x70203a6567617375;
      *(undefined8 *)(pcVar5 + 0x18) = 0x7465677261743c20;
      *(undefined8 *)(pcVar5 + 0x10) = 0x3e627c613c207265;
      *(undefined8 *)(pcVar5 + 0x28) = 0x693a737265626d75;
      *(undefined8 *)(pcVar5 + 0x20) = 0x6e5b203e3233693a;
      uVar11 = (ulong)pcVar5 >> 0x20;
      bVar14 = true;
      *(char (*) [8])(pcVar5 + 0x2f) = (char  [8])0x5d2e2e2e20323369;
      ppppppuVar9 = (undefined ******)0x37;
      pppppuVar13 = (undefined *****)0x37;
    }
    if (pppppuVar4 != (undefined *****)0x0) {
      __rustc[de2ca18b4c54d5b8]::__rust_dealloc(pcVar8,pppppuVar4,1);
    }
    if (!bVar14) goto LAB_100000fe4;
  }
  if ((long)local_e8 - (long)pcStack_f8 != 0) {
    uVar7 = (ulong)((long)local_e8 - (long)pcStack_f8) / 0x18;
    pcVar8 = pcStack_f8 + 8;
    do {
      if (*(long *)(pcVar8 + -8) != 0) {
        __rustc[de2ca18b4c54d5b8]::__rust_dealloc(*(undefined8 *)pcVar8,*(long *)(pcVar8 + -8),1);
      }
      pcVar8 = pcVar8 + 0x18;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  if (local_f0 != (undefined4 *****)0x0) {
    __rustc[de2ca18b4c54d5b8]::__rust_dealloc(local_100,(long)local_f0 * 0x18,8);
  }
LAB_100000fe4:
  pcStack_98 = (code *)((ulong)pcVar5 & 0xffffffff | uVar11 << 0x20);
  local_100 = (undefined4 *****)&local_a0;
  pcStack_f8 = FUN_100000c64;
  local_140 = (undefined *****)&DAT_100048100;
  pcStack_138 = (code *)0x2;
  local_130 = (undefined ******)&local_100;
  local_128 = (undefined *****)0x1;
  local_120 = (undefined ****)0x0;
  local_a0 = pppppuVar13;
  local_90 = ppppppuVar9;
  std::io::stdio::_eprint(&local_140);
  if (local_a0 != (undefined *****)0x0) {
    __rustc[de2ca18b4c54d5b8]::__rust_dealloc(pcStack_98,local_a0,1);
  }
  return 2;
}
