/* Copyright (C) 2015-2017 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#if !defined _IMMINTRIN_H_INCLUDED
# error "Never use <cetintrin.h> directly; include <x86intrin.h> instead."
#endif

#ifndef _CETINTRIN_H_INCLUDED
#define _CETINTRIN_H_INCLUDED

#ifndef __CET__
#pragma GCC push_options
#pragma GCC target ("cet")
#define __DISABLE_CET__
#endif /* __CET__ */

#ifndef __RDSSP__
#pragma GCC push_options
#pragma GCC target ("cet")
#define __DISABLE_RDSSP__
#endif /* __RDSSP__ */

extern __inline unsigned int
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_rdsspd_u32 (void)
{
  return __builtin_ia32_rdsspd ();
}

extern __inline unsigned long long
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_rdsspq_u64 (void)
{
  return __builtin_ia32_rdsspq ();
}
#ifdef __DISABLE_RDSSP__
#undef __DISABLE_RDSSP__
#pragma GCC pop_options
#endif /* __DISABLE_RDSSP__ */

#ifndef __INCSSP__
#pragma GCC push_options
#pragma GCC target ("cet")
#define __DISABLE_INCSSP__
#endif /* __INCSSP__ */
extern __inline void
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_incsspd (unsigned int __B)
{
  __builtin_ia32_incsspd (__B);
}

extern __inline void
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_incsspq (unsigned long long __B)
{
  __builtin_ia32_incsspq (__B);
}
#ifdef __DISABLE_INCSSP__
#undef __DISABLE_INCSSP__
#pragma GCC pop_options
#endif /* __DISABLE_INCSSP__ */

#ifdef __DISABLE_CET__
#undef __DISABLE_CET__
#pragma GCC pop_options
#endif /* __DISABLE_CET__ */

#endif /* _CETINTRIN_H_INCLUDED.  */
