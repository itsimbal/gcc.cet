/* Verify that CET works.  */
/* { dg-do compile } */
/* { dg-options "-O -finstrument-control-flow -mcet" } */
/* { dg-final { scan-assembler-times "endbr32" 3 { target ia32 } } } */
/* { dg-final { scan-assembler-times "endbr64" 3 { target { ! ia32 } } } } */

int func (int arg)
{
  static void *array[] = { &&foo, &&bar };

  goto *array[arg];
foo:
  return arg*111;
bar:
  return arg*777;
}
