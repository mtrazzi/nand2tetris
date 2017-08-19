tab = {'locale':'LCL', 'argument':'ARG', 'this':'THIS', 'that':'THAT'} 

def push(pars):
    if (pars.arg1() in ['locale', 'argument', 'this', 'that'])
       s = push_addr(pars. 
    
def push_addr(addr, i): #receives LCL, ARG, THIS, THAT
"""
pseudo-code :
    addr = segmentPointer + i, *SP = *addr, SP++
assembly :
    @'segmentPointer' e.g. LCL, ARG, ...
    A=M
    D=M
    @i
    D=A+D
    @SP
    A=M
    M=D
    A=A+1
"""
    s = @ + str(addr) + '\n'
    s += 'A=M\n'
    s += 'D=M\n'
    s + ='@SP\n'
    s += 'A=M\n'
    s += 'M=D\n'
    s += 'A=A+1\n'
    return s

def pop_addr(addr, i): #receives LCL, ARG, THIS, THAT
"""
pseudo-code :
    addr = segmentPointer + i, SP--, *addr = *SP (pop segment i)
assembly :
    @SP
    M=M-1
    A=M
    D=M
    @addr
    M=D
"""
    addr = seg_pointer + i
    s = '@SP\n'
    s += 'M=M-1'
    s += 'A=M\n'
    s += 'D=M\n'
    s += '@' + str(addr) + '\n'
    s += 'M=D\n'
    return s

def pop_constant(i):
"""
pseudo-code :
    *SP = i, SP++
assembly :
    @i
    D=A
    @SP
    A=M
    M=D
"""
    s = '@' + str(i) + '\n'
    s += 'D=A\n'
    s += '@SP\n'
    s += 'A=M\n'
    s += 'M=D\n'
    return s
