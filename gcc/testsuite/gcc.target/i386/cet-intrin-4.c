/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mshstk" } */
/* { dg-final { scan-assembler "rdsspd|incsspd\[ \t]+(%|)eax" { target ia32 } } } */
/* { dg-final { scan-assembler "rdssp\[dq]\[ \t]+(%|)\[re]ax"  { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "incssp\[dq]\[ \t]+(%|)\[re]di" { target { ! ia32 } } } } */

#include <immintrin.h>

unsigned int f1 ()
{
  return _rdsspd_u32 ();
}

void f3 (unsigned int _a)
{
  _incsspd (_a);
}

#ifdef __x86_64__
unsigned long long f2 ()
{
  return _rdsspq_u64 ();
}

void f4 (unsigned long long _a)
{
  _incsspq (_a);
}
#endif
