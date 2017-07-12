/* Verify that CET works.  */
/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */
/* { dg-final { scan-assembler-times "notrack jmp\[ \t]+\[*]" 1 } } */

void func2 (int);

int func1 (int arg)
{
  switch (arg)
  {
    case 1: func2 (arg*100);
    case 2: func2 (arg*300);
    case 5: func2 (arg*500);
    case 8: func2 (arg*700);
    case 7: func2 (arg*900);
    case -1: func2 (arg*-100);
    case -2: func2 (arg*-300);
    case -5: func2 (arg*-500);
    case -7: func2 (arg*-700);
    case -9: func2 (arg*-900);
  }
  return 0;
}
