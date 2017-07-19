/* i386 implementation of __Unwind_Shadow_Stack.  */

/* Attempt to Unwind the shadow stack for EH.  */

#ifdef __x86_64__
  #define __Unwind_Shadow_Stack(x) __builtin_ia32_incsspq ((x))
#else
  #define __Unwind_Shadow_Stack(x) __builtin_ia32_incsspd ((x))
#endif
