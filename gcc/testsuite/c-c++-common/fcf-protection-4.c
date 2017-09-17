/* { dg-do compile } */
/* { dg-options "-fcf-protection=none" } */
/* { dg-bogus "'-fcf-protection=none' is not supported for this target" "" { target { "i?86-*-* x86_64-*-*" } } 0 } */
/* { dg-bogus "'-fcf-protection=none' is not supported for this target" "" { target { ! "i?86-*-* x86_64-*-*" } } 0 } */
