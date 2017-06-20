/* Verify that CET works.  */
/* { dg-do compile } */
/* { dg-options "-O -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */
/* { dg-final { scan-assembler-times "notrack call\[ \t]+" 3 } } */

int func (int a) __attribute__ ((notrack));
int (*fptr) (int a) __attribute__ ((notrack));

int foo (int arg)
{
int a, b;
  a = func (arg);
  b = (*fptr) (arg);
  return a+b;
}

int func (int arg)
{
int (*fptrl) (int a) __attribute__ ((notrack));
  return arg*(*fptrl)(arg);
}
