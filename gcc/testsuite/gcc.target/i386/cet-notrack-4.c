/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */

int var1 __attribute__((notrack)); /* { dg-warning "'notrack' attribute only applies to function types" } */
int *var2 __attribute__((notrack)); /* { dg-warning "'notrack' attribute only applies to function types" } */
void (**var3) (void) __attribute__((notrack)); /* { dg-warning "'notrack' attribute only applies to function types" } */
