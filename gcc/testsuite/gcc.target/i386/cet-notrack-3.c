/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 1 } } */

typedef void (*func_t) (void) __attribute__((notrack)); /* { dg-warning "'notrack' attribute ignored" } */
extern func_t func;

void
bar (void)
{
  func ();
}
