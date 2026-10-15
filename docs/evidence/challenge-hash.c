
/* WARNING: Unknown calling convention: __rustcall */
/* <rust_tuesday::HashLookup as rust_tuesday::PairSearch>::find */

void __rustcall
<rust_tuesday::HashLookup_as_rust_tuesday::PairSearch>::find
          (undefined8 *param_1,undefined8 param_2,int *param_3,long param_4,int param_5)

{
  byte bVar1;
  undefined1 (*pauVar2) [16];
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  int *piVar15;
  ulong uVar17;
  long lVar18;
  byte bVar19;
  byte bVar20;
  undefined8 uVar21;
  long *local_90;
  ulong uStack_88;
  long local_80;
  long lStack_78;
  undefined1 local_70 [16];
  int *piVar16;

  pauVar2 = (undefined1 (*) [16])
            (*std::hash::random::RandomState::new::KEYS::{{constant}}::{{closure}}::VAL)();
  if (pauVar2[1][0] == '\x01') {
    local_70 = *pauVar2;
  }
  else {
    local_70 = std::sys::random::hashmap_random_keys();
    *(long *)(*pauVar2 + 8) = local_70._8_8_;
    pauVar2[1][0] = 1;
  }
  *(long *)*pauVar2 = local_70._0_8_ + 1;
  uStack_88 = 0;
  local_90 = (long *)&DAT_10003b408;
  lStack_78 = 0;
  local_80 = 0;
  if (param_4 == 0) {
    *param_1 = 0;
    return;
  }
  lVar8 = 0;
  piVar15 = param_3;
  lVar18 = 0;
LAB_1000016d4:
  piVar16 = piVar15 + 1;
  uVar17 = (ulong)*piVar15;
  uVar9 = local_70._8_8_ ^ 0x646f72616e646f6d;
  if (lVar8 == 0) {
    uVar10 = uVar9 + (local_70._0_8_ ^ 0x736f6d6570736575);
    uVar11 = uVar10 >> 0x20 | uVar10 << 0x20;
    uVar10 = uVar10 ^ (uVar9 >> 0x33 | uVar9 << 0xd);
    uVar9 = uVar10 >> 0x2f | uVar10 << 0x11;
  }
  else {
    lVar13 = 0;
    uVar14 = (long)param_5 - uVar17;
    uVar12 = local_70._8_8_ ^ uVar14 ^ 0x7465646279746573;
    uVar11 = uVar9 + (local_70._0_8_ ^ 0x736f6d6570736575);
    uVar10 = uVar11 ^ (uVar9 >> 0x33 | uVar9 << 0xd);
    uVar3 = uVar12 + (local_70._0_8_ ^ 0x6c7967656e657261);
    uVar6 = uVar10 + uVar3;
    uVar3 = uVar3 ^ (uVar12 >> 0x30 | uVar12 << 0x10);
    uVar11 = uVar11 >> 0x20 | uVar11 << 0x20;
    uVar9 = uVar10 >> 0x2f | uVar10 << 0x11;
    uVar12 = uVar6 ^ uVar9;
    uVar4 = uVar3 + uVar11 ^ (uVar3 >> 0x2b | uVar3 << 0x15);
    uVar5 = uVar4 ^ 0x800000000000000;
    uVar3 = (uVar3 + uVar11 ^ uVar14) + uVar12;
    uVar7 = uVar3 ^ (uVar12 >> 0x33 | uVar12 << 0xd);
    uVar6 = uVar5 + (uVar6 >> 0x20 | uVar6 << 0x20);
    uVar12 = uVar6 + uVar7;
    uVar6 = uVar6 ^ (uVar5 >> 0x30 | uVar4 << 0x10);
    uVar3 = uVar6 + (uVar3 >> 0x20 | uVar3 << 0x20);
    uVar5 = uVar12 ^ (uVar7 >> 0x2f | uVar7 << 0x11);
    uVar4 = uVar3 ^ (uVar6 >> 0x2b | uVar6 << 0x15);
    uVar3 = (uVar3 ^ 0x800000000000000) + uVar5;
    uVar5 = uVar3 ^ (uVar5 >> 0x33 | uVar5 << 0xd);
    uVar6 = uVar4 + ((uVar12 >> 0x20 | uVar12 << 0x20) ^ 0xff);
    uVar12 = uVar5 + uVar6;
    uVar6 = uVar6 ^ (uVar4 >> 0x30 | uVar4 << 0x10);
    uVar5 = uVar12 ^ (uVar5 >> 0x2f | uVar5 << 0x11);
    uVar3 = uVar6 + (uVar3 >> 0x20 | uVar3 << 0x20);
    uVar4 = uVar5 + uVar3;
    uVar3 = uVar3 ^ (uVar6 >> 0x2b | uVar6 << 0x15);
    uVar5 = uVar4 ^ (uVar5 >> 0x33 | uVar5 << 0xd);
    uVar6 = uVar3 + (uVar12 >> 0x20 | uVar12 << 0x20);
    uVar12 = uVar5 + uVar6;
    uVar6 = uVar6 ^ (uVar3 >> 0x30 | uVar3 << 0x10);
    uVar5 = uVar12 ^ (uVar5 >> 0x2f | uVar5 << 0x11);
    uVar3 = uVar6 + (uVar4 >> 0x20 | uVar4 << 0x20);
    uVar4 = uVar3 ^ (uVar6 >> 0x2b | uVar6 << 0x15);
    uVar5 = uVar5 + uVar3 ^ (uVar5 >> 0x33 | uVar5 << 0xd);
    uVar3 = uVar4 + (uVar12 >> 0x20 | uVar12 << 0x20);
    uVar6 = uVar5 + uVar3;
    uVar3 = uVar3 ^ (uVar4 >> 0x30 | uVar4 << 0x10);
    uVar6 = (uVar3 >> 0x2b | uVar3 << 0x15) ^ (uVar5 >> 0x2f | uVar5 << 0x11) ^
            (uVar6 >> 0x20 | uVar6 << 0x20) ^ uVar6;
    bVar1 = (byte)(uVar6 >> 0x39);
    uVar6 = uVar6 & uStack_88;
    uVar21 = *(undefined8 *)((long)local_90 + uVar6);
    uVar3 = CONCAT17(-((byte)((ulong)uVar21 >> 0x38) == bVar1),
                     CONCAT16(-((byte)((ulong)uVar21 >> 0x30) == bVar1),
                              CONCAT15(-((byte)((ulong)uVar21 >> 0x28) == bVar1),
                                       CONCAT14(-((byte)((ulong)uVar21 >> 0x20) == bVar1),
                                                CONCAT13(-((byte)((ulong)uVar21 >> 0x18) == bVar1),
                                                         CONCAT12(-((byte)((ulong)uVar21 >> 0x10) ==
                                                                   bVar1),CONCAT11(-((byte)((ulong)
                                                  uVar21 >> 8) == bVar1),-((byte)uVar21 == bVar1))))
                                               )))) & 0x8080808080808080;
    while( true ) {
      for (; uVar3 != 0; uVar3 = uVar3 - 1 & uVar3) {
        uVar12 = (uVar3 >> 7 & 0xff00ff00ff00ff00) >> 8 | (uVar3 >> 7 & 0xff00ff00ff00ff) << 8;
        uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
        uVar12 = uVar6 + ((ulong)LZCOUNT(uVar12 >> 0x20 | uVar12 << 0x20) >> 3) & uStack_88;
        if (uVar14 == local_90[uVar12 * -2 + -2]) {
          param_1[1] = local_90[uVar12 * -2 + -1];
          param_1[2] = lVar18;
          *param_1 = 1;
          goto joined_r0x000100001b3c;
        }
      }
      bVar19 = NEON_umaxv(CONCAT17(-((char)((ulong)uVar21 >> 0x38) == -1),
                                   CONCAT16(-((char)((ulong)uVar21 >> 0x30) == -1),
                                            CONCAT15(-((char)((ulong)uVar21 >> 0x28) == -1),
                                                     CONCAT14(-((char)((ulong)uVar21 >> 0x20) == -1)
                                                              ,CONCAT13(-((char)((ulong)uVar21 >>
                                                                                0x18) == -1),
                                                                        CONCAT12(-((char)((ulong)
                                                  uVar21 >> 0x10) == -1),
                                                  CONCAT11(-((char)((ulong)uVar21 >> 8) == -1),
                                                           -((char)uVar21 == -1)))))))),1);
      if ((bVar19 & 1) != 0) break;
      lVar13 = lVar13 + 8;
      uVar6 = uVar6 + lVar13 & uStack_88;
      uVar21 = *(undefined8 *)((long)local_90 + uVar6);
      uVar3 = CONCAT17(-((byte)((ulong)uVar21 >> 0x38) == bVar1),
                       CONCAT16(-((byte)((ulong)uVar21 >> 0x30) == bVar1),
                                CONCAT15(-((byte)((ulong)uVar21 >> 0x28) == bVar1),
                                         CONCAT14(-((byte)((ulong)uVar21 >> 0x20) == bVar1),
                                                  CONCAT13(-((byte)((ulong)uVar21 >> 0x18) == bVar1)
                                                           ,CONCAT12(-((byte)((ulong)uVar21 >> 0x10)
                                                                      == bVar1),
                                                                     CONCAT11(-((byte)((ulong)uVar21
                                                                                      >> 8) == bVar1
                                                                               ),-((byte)uVar21 ==
                                                                                  bVar1)))))))) &
              0x8080808080808080;
    }
  }
  lVar13 = 0;
  uVar6 = local_70._8_8_ ^ uVar17 ^ 0x7465646279746573;
  uVar3 = uVar6 + (local_70._0_8_ ^ 0x6c7967656e657261);
  uVar10 = uVar10 + uVar3;
  uVar3 = uVar3 ^ (uVar6 >> 0x30 | uVar6 << 0x10);
  uVar9 = uVar10 ^ uVar9;
  uVar6 = uVar11 + uVar3 ^ (uVar3 >> 0x2b | uVar3 << 0x15);
  uVar12 = uVar6 ^ 0x800000000000000;
  uVar11 = (uVar11 + uVar3 ^ uVar17) + uVar9;
  uVar3 = uVar11 ^ (uVar9 >> 0x33 | uVar9 << 0xd);
  uVar9 = uVar12 + (uVar10 >> 0x20 | uVar10 << 0x20);
  uVar10 = uVar3 + uVar9;
  uVar9 = uVar9 ^ (uVar12 >> 0x30 | uVar6 << 0x10);
  uVar11 = uVar9 + (uVar11 >> 0x20 | uVar11 << 0x20);
  uVar6 = uVar10 ^ (uVar3 >> 0x2f | uVar3 << 0x11);
  uVar3 = uVar11 ^ (uVar9 >> 0x2b | uVar9 << 0x15);
  uVar9 = (uVar11 ^ 0x800000000000000) + uVar6;
  uVar6 = uVar9 ^ (uVar6 >> 0x33 | uVar6 << 0xd);
  uVar10 = ((uVar10 >> 0x20 | uVar10 << 0x20) ^ 0xff) + uVar3;
  uVar11 = uVar6 + uVar10;
  uVar10 = uVar10 ^ (uVar3 >> 0x30 | uVar3 << 0x10);
  uVar6 = uVar11 ^ (uVar6 >> 0x2f | uVar6 << 0x11);
  uVar9 = uVar10 + (uVar9 >> 0x20 | uVar9 << 0x20);
  uVar3 = uVar6 + uVar9;
  uVar9 = uVar9 ^ (uVar10 >> 0x2b | uVar10 << 0x15);
  uVar6 = uVar3 ^ (uVar6 >> 0x33 | uVar6 << 0xd);
  uVar10 = uVar9 + (uVar11 >> 0x20 | uVar11 << 0x20);
  uVar11 = uVar6 + uVar10;
  uVar10 = uVar10 ^ (uVar9 >> 0x30 | uVar9 << 0x10);
  uVar6 = uVar11 ^ (uVar6 >> 0x2f | uVar6 << 0x11);
  uVar9 = uVar10 + (uVar3 >> 0x20 | uVar3 << 0x20);
  uVar3 = uVar9 ^ (uVar10 >> 0x2b | uVar10 << 0x15);
  uVar6 = uVar6 + uVar9 ^ (uVar6 >> 0x33 | uVar6 << 0xd);
  uVar9 = uVar3 + (uVar11 >> 0x20 | uVar11 << 0x20);
  uVar10 = uVar6 + uVar9;
  uVar9 = uVar9 ^ (uVar3 >> 0x30 | uVar3 << 0x10);
  uVar10 = (uVar6 >> 0x2f | uVar6 << 0x11) ^ (uVar9 >> 0x2b | uVar9 << 0x15) ^
           (uVar10 >> 0x20 | uVar10 << 0x20) ^ uVar10;
  bVar1 = (byte)(uVar10 >> 0x38);
  bVar19 = bVar1 >> 1;
  uVar11 = uVar10 & uStack_88;
  uVar21 = *(undefined8 *)((long)local_90 + uVar11);
  uVar9 = CONCAT17(-((byte)((ulong)uVar21 >> 0x38) == bVar19),
                   CONCAT16(-((byte)((ulong)uVar21 >> 0x30) == bVar19),
                            CONCAT15(-((byte)((ulong)uVar21 >> 0x28) == bVar19),
                                     CONCAT14(-((byte)((ulong)uVar21 >> 0x20) == bVar19),
                                              CONCAT13(-((byte)((ulong)uVar21 >> 0x18) == bVar19),
                                                       CONCAT12(-((byte)((ulong)uVar21 >> 0x10) ==
                                                                 bVar19),CONCAT11(-((byte)((ulong)
                                                  uVar21 >> 8) == bVar19),-((byte)uVar21 == bVar19))
                                                  )))))) & 0x8080808080808080;
  do {
    if (uVar9 == 0) {
LAB_1000019a0:
      bVar20 = NEON_umaxv(CONCAT17(-((char)((ulong)uVar21 >> 0x38) == -1),
                                   CONCAT16(-((char)((ulong)uVar21 >> 0x30) == -1),
                                            CONCAT15(-((char)((ulong)uVar21 >> 0x28) == -1),
                                                     CONCAT14(-((char)((ulong)uVar21 >> 0x20) == -1)
                                                              ,CONCAT13(-((char)((ulong)uVar21 >>
                                                                                0x18) == -1),
                                                                        CONCAT12(-((char)((ulong)
                                                  uVar21 >> 0x10) == -1),
                                                  CONCAT11(-((char)((ulong)uVar21 >> 8) == -1),
                                                           -((char)uVar21 == -1)))))))),1);
      if ((bVar20 & 1) == 0) break;
      if (local_80 == 0) {
        hashbrown::raw::RawTable<T,A>::reserve_rehash(&local_90,1,local_70,1);
        uVar10 = uStack_88 & uVar10;
        lVar8 = *(long *)((long)local_90 + uVar10);
        uVar9 = CONCAT17(-(lVar8 < 0),
                         CONCAT16(-((char)((ulong)lVar8 >> 0x30) < '\0'),
                                  CONCAT15(-((char)((ulong)lVar8 >> 0x28) < '\0'),
                                           CONCAT14(-((char)((ulong)lVar8 >> 0x20) < '\0'),
                                                    CONCAT13(-((char)((ulong)lVar8 >> 0x18) < '\0'),
                                                             CONCAT12(-((char)((ulong)lVar8 >> 0x10)
                                                                       < '\0'),CONCAT11(-((char)((
                                                  ulong)lVar8 >> 8) < '\0'),-((char)lVar8 < '\0'))))
                                                  ))));
      }
      else {
        uVar10 = uStack_88 & uVar10;
        lVar8 = *(long *)((long)local_90 + uVar10);
        uVar9 = CONCAT17(-(lVar8 < 0),
                         CONCAT16(-((char)((ulong)lVar8 >> 0x30) < '\0'),
                                  CONCAT15(-((char)((ulong)lVar8 >> 0x28) < '\0'),
                                           CONCAT14(-((char)((ulong)lVar8 >> 0x20) < '\0'),
                                                    CONCAT13(-((char)((ulong)lVar8 >> 0x18) < '\0'),
                                                             CONCAT12(-((char)((ulong)lVar8 >> 0x10)
                                                                       < '\0'),CONCAT11(-((char)((
                                                  ulong)lVar8 >> 8) < '\0'),-((char)lVar8 < '\0'))))
                                                  ))));
      }
      if (uVar9 == 0) {
        lVar8 = 8;
        do {
          uVar10 = uVar10 + lVar8 & uStack_88;
          lVar13 = *(long *)((long)local_90 + uVar10);
          uVar9 = CONCAT17(-(lVar13 < 0),
                           CONCAT16(-((char)((ulong)lVar13 >> 0x30) < '\0'),
                                    CONCAT15(-((char)((ulong)lVar13 >> 0x28) < '\0'),
                                             CONCAT14(-((char)((ulong)lVar13 >> 0x20) < '\0'),
                                                      CONCAT13(-((char)((ulong)lVar13 >> 0x18) <
                                                                '\0'),CONCAT12(-((char)((ulong)
                                                  lVar13 >> 0x10) < '\0'),
                                                  CONCAT11(-((char)((ulong)lVar13 >> 8) < '\0'),
                                                           -((char)lVar13 < '\0'))))))));
          lVar8 = lVar8 + 8;
        } while (uVar9 == 0);
      }
      uVar9 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
      uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2;
      uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8;
      uVar9 = (uVar9 & 0xffff0000ffff0000) >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10;
      uVar9 = uVar10 + ((ulong)LZCOUNT(uVar9 >> 0x20 | uVar9 << 0x20) >> 3) & uStack_88;
      uVar10 = (ulong)*(char *)((long)local_90 + uVar9);
      if (-1 < *(char *)((long)local_90 + uVar9)) {
        lVar8 = *local_90;
        uVar9 = CONCAT17(-(lVar8 < 0),
                         CONCAT16(-((char)((ulong)lVar8 >> 0x30) < '\0'),
                                  CONCAT15(-((char)((ulong)lVar8 >> 0x28) < '\0'),
                                           CONCAT14(-((char)((ulong)lVar8 >> 0x20) < '\0'),
                                                    CONCAT13(-((char)((ulong)lVar8 >> 0x18) < '\0'),
                                                             CONCAT12(-((char)((ulong)lVar8 >> 0x10)
                                                                       < '\0'),CONCAT11(-((char)((
                                                  ulong)lVar8 >> 8) < '\0'),-((char)lVar8 < '\0'))))
                                                  ))));
        uVar9 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
        uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2;
        uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8;
        uVar9 = (uVar9 & 0xffff0000ffff0000) >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10;
        uVar9 = (ulong)LZCOUNT(uVar9 >> 0x20 | uVar9 << 0x20) >> 3;
        uVar10 = (ulong)*(byte *)((long)local_90 + uVar9);
      }
      *(byte *)((long)local_90 + uVar9) = bVar1 >> 1;
      *(byte *)((long)local_90 + (uVar9 - 8 & uStack_88) + 8) = bVar1 >> 1;
      local_80 = local_80 - (uVar10 & 1);
      local_90[uVar9 * -2 + -2] = uVar17;
      local_90[uVar9 * -2 + -1] = lVar18;
      lVar8 = lStack_78 + 1;
      lStack_78 = lVar8;
      goto LAB_100001a3c;
    }
LAB_100001974:
    uVar3 = (uVar9 >> 7 & 0xff00ff00ff00ff00) >> 8 | (uVar9 >> 7 & 0xff00ff00ff00ff) << 8;
    uVar3 = (uVar3 & 0xffff0000ffff0000) >> 0x10 | (uVar3 & 0xffff0000ffff) << 0x10;
    if (local_90[(uVar11 + ((ulong)LZCOUNT(uVar3 >> 0x20 | uVar3 << 0x20) >> 3) & uStack_88) * -2 +
                 -2] == uVar17) goto LAB_100001a3c;
    uVar9 = uVar9 - 1 & uVar9;
  } while( true );
  lVar13 = lVar13 + 8;
  uVar11 = uVar11 + lVar13 & uStack_88;
  uVar21 = *(undefined8 *)((long)local_90 + uVar11);
  uVar9 = CONCAT17(-((byte)((ulong)uVar21 >> 0x38) == bVar19),
                   CONCAT16(-((byte)((ulong)uVar21 >> 0x30) == bVar19),
                            CONCAT15(-((byte)((ulong)uVar21 >> 0x28) == bVar19),
                                     CONCAT14(-((byte)((ulong)uVar21 >> 0x20) == bVar19),
                                              CONCAT13(-((byte)((ulong)uVar21 >> 0x18) == bVar19),
                                                       CONCAT12(-((byte)((ulong)uVar21 >> 0x10) ==
                                                                 bVar19),CONCAT11(-((byte)((ulong)
                                                  uVar21 >> 8) == bVar19),-((byte)uVar21 == bVar19))
                                                  )))))) & 0x8080808080808080;
  if (uVar9 != 0) goto LAB_100001974;
  goto LAB_1000019a0;
LAB_100001a3c:
  piVar15 = piVar16;
  lVar18 = lVar18 + 1;
  if (piVar16 == param_3 + param_4) {
    *param_1 = 0;
joined_r0x000100001b3c:
    if (uStack_88 == 0) {
      return;
    }
    lVar8 = uStack_88 * 0x11 + 0x19;
    if (lVar8 == 0) {
      return;
    }
    __rustc[de2ca18b4c54d5b8]::__rust_dealloc(local_90 + uStack_88 * -2 + -2,lVar8,8);
    return;
  }
  goto LAB_1000016d4;
}
