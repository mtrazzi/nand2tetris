tab = {'local':'LCL', 'argument':'ARG', 'this':'THIS', 'that':'THAT', 'temp':'TMP'} 

def push(pars):
    if (pars.arg1() in tab):
        return push_addr(tab[pars.arg1()], pars.arg2())
    elif (pars.arg1() == 'constant'):
        return push_constant(pars.arg2())
    elif (pars.arg1() == 'pointer' and pars.arg2() == '0'):
        return push_addr('pointer0', 0)
    elif (pars.arg1() == 'pointer' and pars.arg2() == '1'):
        return push_addr('pointer1', 0)
    elif (pars.arg1() == 'static'):
        return push_static(pars, pars.arg2())
    else:
        return '//TO DO (PUSH)\n'

def pop(pars):
    if (pars.arg1() in tab):
        return pop_addr(tab[pars.arg1()], pars.arg2())
    elif (pars.arg1() == 'pointer' and pars.arg2() == '0'):
        return pop_addr('pointer0', 0)
    elif (pars.arg1() == 'pointer' and pars.arg2() == '1'):
        return pop_addr('pointer1', 0)
    elif (pars.arg1() == 'static'):
        return pop_static(pars, pars.arg2())
    else:
        return '//TO DO (POP)\n'

def get_addr(addr):
    s =  '@' + str(addr) + '\n'
    s += 'A=M\n'
    return s

def get_addr_d(addr):
    d = {'TMP': '5', 'pointer0': '3', 'pointer1': '4'}
    if (addr in d):
        return '@' + d[addr] + '\n' + 'D=A\n'
    s =  '@' + str(addr) + '\n'
    s += 'D=M\n'
    return s

def push_addr(addr, i): #receives LCL, ARG, THIS, THAT
    """ 
    pseudo-code :
        addr = segmentPointer + i, *SP = *addr, SP++
    """
    s =  get_addr_d(addr) 
    s += add_constant(i)
    s += 'A=D\n'
    s += 'D=M\n'                # D = *(mem_seg_bas_add + i) 
    s += get_addr('SP')
    s += 'M=D\n'                # *SP = D
    s += change_content('SP', '+1')
    return s

def pop_addr(addr, i): #receives LCL, ARG, THIS, THAT
    """
    pseudo-code :
        addr = segmentPointer + i, SP--, *addr = *SP (pop segment i)
    """
    s = change_content('SP', '-1') 
    s +=  get_addr_d(addr) 
    s += add_constant(i)         
    s += '@R13\n'
    s += 'M=D\n'                # R13 = (mem_seg_bas_add + i)
    s += get_addr('SP')         
    s += 'D=M\n'                # D = *SP 
    s += '@R13\n'
    s += 'A=M\n'
    s += 'M=D\n'                # *R13 = D
    return s

def change_content(addr, incr): #incr is +1 or -1
    """
    pseudo-code : *addr = *addr + incr
    """
    s = '@' + str(addr) + '\n'
    s += 'M=M' + incr + '\n'
    return s

def add_constant(i):
    """
    pseudo-code : D=D+i
    """
    s = '@' + str(i) + '\n'
    s += 'D=D+A\n'
    return s

def push_constant(i):
    """
    pseudo-code :
        *SP = i, SP++
    """
    s = '@' + str(i) + '\n'
    s += 'D=A\n'
    s += '@SP\n'
    s += 'A=M\n'
    s += 'M=D\n'
    s += change_content('SP', '+1')
    return s

def push_static(p, i):
    s =  '@' + p.file_name.split('/')[-1] + '.' + str(i) + '\n'
    s += 'D=M\n'
    s += get_addr('SP')
    s += 'M=D\n'
    s +=  change_content('SP', '+1')
    return s

def pop_static(p, i):
    s =  change_content('SP', '-1')
    s += get_addr('SP')
    s += 'D=M\n' 
    s += '@' + p.file_name.split('/')[-1] + '.' + str(i) + '\n'
    s += 'M=D\n'
    return s
