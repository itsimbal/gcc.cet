/* Verify that CET works.  */
/* { dg-do compile } */
/* { dg-options "-O -mcet" } */
/* { dg-final { scan-assembler-times "endbr32|endbr64" 3 } } */

int func (int arg)
{
  static void *array[] = { &&foo, &&bar };

  goto *array[arg];
foo:
  return arg*111;
bar:
  return arg*777;
}
