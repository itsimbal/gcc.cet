/* { dg-do compile } */
/* { dg-options "-finstrument-control-flow" } */
/* { dg-error "'-finstrument-control-flow' requires CET support on this target. Use -mcet options to enable CET" "" { target { "i?86-*-* x86_64-*-*" } } 0 } */
