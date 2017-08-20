tab = {'local':'LCL', 'argument':'ARG', 'this':'THIS', 'that':'THAT', 'temp':'5'} 

def push(pars):
    if (pars.arg1() in ['local', 'argument', 'this', 'that', 'temp']):
        return push_addr(tab[pars.arg1()], pars.arg2())
    elif (pars.arg1() == 'constant'):
        return push_constant(pars.arg2())
    elif (pars.arg1() == 'pointer' and pars.arg2() == '0'):
        return push_addr('THIS', 0)
    elif (pars.arg1() == 'pointer' and pars.arg2() == '1'):
        return push_addr('THAT', 0)
    elif (pars.arg1() == 'static'):
        return push_static(pars, i)
    else:
        return '//TO DO\n'

def pop(pars):
    if (pars.arg1() in ['locale', 'argument', 'this', 'that', 'temp']):
        return pop_addr(tab[pars.arg1()], pars.arg2())
    elif (pars.arg1() == 'pointer' and pars.arg2() == '0'):
        return pop_addr('THIS', 0)
    elif (pars.arg1() == 'pointer' and pars.arg2() == '1'):
        return pop_addr('THAT', 0)
    elif (pars.arg1() == 'static'):
        return pop_static(pars, i)
    else:
        return '//TO DO\n'

def get_addr(addr):
    s =  '@' + str(addr) + '\n'
    s += 'A=M\n'
    return s

def push_addr(addr, i): #receives LCL, ARG, THIS, THAT
    """ 
    pseudo-code :
        addr = segmentPointer + i, *SP = *addr, SP++
    """
    s =  get_addr(addr) 
    s += 'D=M\n'
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
    s +=  get_addr(addr) 
    s += 'D=M\n'
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
    return s

def push_static(p, i):
    s =  '@' + p.file_name + '.' + str(i) + '\n'
    s += 'D=M\n'
    s += get_addr('SP')
    s += 'M=D\n'
    s +=  change_content('SP', '+1')

def pop_static(p, i):
    s =  change_content('SP', '-1')
    s += get_addr('SP')
    s += 'D=M\n' 
    s += '@' + p.file_name + '.' + str(i) + '\n'
    s += 'M=D\n'
