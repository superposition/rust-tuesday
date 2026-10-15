
/* WARNING: Unknown calling convention: __rustcall */
/* <rust_tuesday::BruteForce as rust_tuesday::PairSearch>::find */

void __rustcall
<rust_tuesday::BruteForce_as_rust_tuesday::PairSearch>::find
          (long *param_1,undefined8 param_2,long param_3,long param_4,int param_5)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;

  lVar3 = 0;
  if (param_4 == 0) {
LAB_100001604:
    *param_1 = lVar3;
    return;
  }
  do {
    lVar1 = lVar3 + 1;
    lVar2 = 0;
    while (lVar4 = lVar2, lVar3 != lVar4) {
      lVar2 = lVar4 + 1;
      if ((long)*(int *)(param_3 + lVar3 * 4) + (long)*(int *)(param_3 + lVar4 * 4) == (long)param_5
         ) {
        param_1[1] = lVar4;
        param_1[2] = lVar3;
        lVar3 = 1;
        goto LAB_100001604;
      }
    }
    lVar3 = lVar1;
    if (lVar1 == param_4) {
      *param_1 = 0;
      return;
    }
  } while( true );
}
