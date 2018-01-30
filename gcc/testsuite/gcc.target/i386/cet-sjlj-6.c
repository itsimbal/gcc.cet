/* { dg-do compile } */
/* { dg-options "-O -fcf-protection -mcet -mx32" } */
/* { dg-final { scan-assembler-times "endbr64" 2 } } */
/* { dg-final { scan-assembler-times "movq\t.*buf\\+12" 1 } } */
/* { dg-final { scan-assembler-times "subq\tbuf\\+12" 1 } } */
/* { dg-final { scan-assembler-times "rdsspq" 2 } } */
/* { dg-final { scan-assembler-times "incsspq" 2 } } */

void *buf[5];

void raise0(void)
{
  __builtin_longjmp (buf, 1);
}

void execute(int cmd)
{
  __builtin_setjmp (buf);
}
