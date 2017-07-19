/* i386 implementation of __Unwind_shadow_stack.  */

extern void __Unwind_shadow_stack (unsigned int);

/* Attempt to Unwind the shadow stack for EH.  */

void
__Unwind_shadow_stack (unsigned int num_frames __attribute__((__unused__)))
{
#ifdef __x86_64__
  __builtin_ia32_incsspq (num_frames);
#else
  __builtin_ia32_incsspd (num_frames);
#endif
}
