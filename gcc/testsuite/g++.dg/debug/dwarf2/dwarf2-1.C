/* { dg-bogus "-feliminate-dwarf2-dups is broken for C\\+\\+, ignoring" "broken -feliminate-dwarf2-dups" { xfail *-*-* } } */
// Copyright (C) 2006 Free Software Foundation, Inc.
// Contributed by Nathan Sidwell 6 Jan 2006 <nathan@codesourcery.com>

// PR 24824
// Origin:   	 wanderer@rsu.ru

// { dg-options "-gdwarf -feliminate-dwarf2-dups" }

namespace N
{
  struct Base
  {
    int m;
  };

  struct Derived : Base
  {
    using Base::m;
  };
}

N::Derived thing;
