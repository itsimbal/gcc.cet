// syscall_linux_s390x.go -- GNU/Linux s390x specific support

// Copyright 2014 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package syscall

import "unsafe"

func (r *PtraceRegs) PC() uint64 { return r.Psw.addr }

func (r *PtraceRegs) SetPC(pc uint64) { r.Psw.addr = pc }

func PtraceGetRegs(pid int, regsout *PtraceRegs) (err error) {
	return ptrace(PTRACE_GETREGS, pid, 0, uintptr(unsafe.Pointer(regsout)))
}

func PtraceSetRegs(pid int, regs *PtraceRegs) (err error) {
	return ptrace(PTRACE_SETREGS, pid, 0, uintptr(unsafe.Pointer(regs)))
}
