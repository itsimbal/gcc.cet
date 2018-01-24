/* { dg-do compile } */
/* { dg-options "-O -fcf-protection -mcet" } */
/* { dg-final { scan-assembler "rdsspd\[ \t]+(%|)eax" { target ia32 } } } */
/* { dg-final { scan-assembler "rdsspq\[ \t]+(%|)rax" { target { ! ia32 } } } } */

#include <immintrin.h>

void * f1 ()
{
  return _get_ssp ();
}
