/* { dg-do compile } */
/* { dg-options "-O -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 4 } } */
/* { dg-final { scan-assembler "rdssp\[dq]\[ \t]+(%|)eax" } } */
/* { dg-final { scan-assembler "rdssp\[dq]\[ \t]+(%|)rax" } } */
/* { dg-final { scan-assembler "incssp\[dq]\[ \t]+(%|)edi" } } */
/* { dg-final { scan-assembler "incssp\[dq]\[ \t]+(%|)rdi" } } */

#include <immintrin.h>

unsigned int f1 ()
{
  return _rdsspd_u32 ();
}

unsigned long long f2 ()
{
  return _rdsspq_u64 ();
}

void f3 (unsigned int _a)
{
  _incsspd (_a);
}

void f4 (unsigned long long _a)
{
  _incsspq (_a);
}
