/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 4 } } */
/* { dg-final { scan-assembler-times "rdssp\[dq]" 2 } } */
/* { dg-final { scan-assembler-times "incssp\[dq]" 1 } } */

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int bar (int);

int
foo (int i)
{
  int j = i * 11;

  if (!__builtin_setjmp (buf))
    {
      j += 33;
      printf ("After setjmp: j = %d\n", j);
      bar (j);
    }

  return j + i;
}

int
bar (int i)
{
int j = i;

  j -= 111;
  printf ("In longjmp: j = %d\n", j);
  __builtin_longjmp (buf, 1);

  return j;
}

int
main ()
{
  foo (10);
  return 0;
}
