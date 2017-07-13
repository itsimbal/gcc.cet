/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */
/* { dg-final { scan-assembler-not "\tcall\[ \t]+" } } */
/* { dg-final { scan-assembler-times "notrack call\[ \t]+" 1 } } */

int (*fptr) (int) __attribute__ ((notrack));

int
foo (int arg)
{
  int a;
  a = (*fptr) (arg); /* notrack call.  */
  return arg+a;
}
