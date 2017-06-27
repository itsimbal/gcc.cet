/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 4 } } */
/* { dg-final { scan-assembler "rdssp\[dq]\[ \t]+(%|)eax" } } */
/* { dg-final { scan-assembler "rdssp\[dq]\[ \t]+(%|)rax" } } */
/* { dg-final { scan-assembler "incssp\[dq]\[ \t]+(%|)edi" } } */
/* { dg-final { scan-assembler "incssp\[dq]\[ \t]+(%|)rdi" } } */

#include <immintrin.h>

unsigned int f1 ()
{
  return __builtin_ia32_rdsspd ();
}

unsigned long long f2 ()
{
  return __builtin_ia32_rdsspq ();
}

void f3 (unsigned int _a)
{
  __builtin_ia32_incsspd (_a);
}

void f4 (unsigned long long _a)
{
  __builtin_ia32_incsspq (_a);
}
