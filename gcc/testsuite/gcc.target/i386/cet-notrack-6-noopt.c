/* { dg-do compile } */
/* { dg-options "-finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */
/* { dg-final { scan-assembler-times "\tcall\[ \t]+" 1 } } */
/* { dg-final { scan-assembler-times "notrack call\[ \t]+" 1 } } */

int foo (int arg);

int func (int arg)
{
int (*fptrl) (int a) __attribute__ ((notrack)) = foo;

  /* the first call is notrack, the second is not.  */
  return (*fptrl)(arg) + (*(fptrl+4))(arg);
}
