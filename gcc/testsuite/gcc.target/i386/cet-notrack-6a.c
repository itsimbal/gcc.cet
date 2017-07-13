/* { dg-do compile } */
/* { dg-options "-O2 -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */
/* { dg-final { scan-assembler-times "\t(?:call|jmp)\[ \t]+foo" 1 } } */
/* { dg-final { scan-assembler-not "notrack call\[ \t]+" } } */

int foo (int arg);

int func (int arg)
{
  int (*fptrl) (int a) __attribute__ ((notrack)) = foo;

  return (*fptrl)(arg);
}
