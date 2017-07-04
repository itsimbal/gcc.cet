/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */
/* { dg-final { scan-assembler-times "\tcall\[ \t]+" 1 } } */
/* { dg-final { scan-assembler-times "notrack call\[ \t]+" 1 } } */

int (*fptr) (int a) __attribute__ ((notrack));

int foo (int arg)
{
int a, b;
  a = (*fptr) (arg); /* notrack call.  */
  b = (*(fptr+4)) (arg); /* no prefix.  */
  return arg+b;
}
