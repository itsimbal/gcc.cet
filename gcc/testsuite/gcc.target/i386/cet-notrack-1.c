/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */
/* { dg-final { scan-assembler-times "notrack call\[ \t]+" 0 } } */

extern void foo (void) __attribute__((notrack));

void
bar (void)
{
  foo ();
}
