/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */

int var1 __attribute__((notrack)); /* { dg-warning "'notrack' attribute ignored" } */
int *var2 __attribute__((notrack)); /* { dg-warning "'notrack' attribute ignored" } */
void (**var3) (void) __attribute__((notrack)); /* { dg-warning "'notrack' attribute ignored" } */
