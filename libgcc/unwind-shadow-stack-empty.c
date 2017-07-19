/* Dummy implementation of __Unwind_shadow_stack.  */

extern void __Unwind_shadow_stack (unsigned int);

/* Attempt to Unwind the shadow stack for EH.  */

void
__Unwind_shadow_stack (unsigned int num_frames __attribute__((__unused__)))
{
}
