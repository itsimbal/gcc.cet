/* { dg-do compile } */
/* { dg-options "" } */

int var1 __attribute__((notrack)); /* { dg-warning "'notrack' attribute ignored" } */
int *var2 __attribute__((notrack)); /* { dg-warning "'notrack' attribute ignored" } */
void (**var3) (void) __attribute__((notrack)); /* { dg-warning "'notrack' attribute ignored" } */
