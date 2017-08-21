def arithmetic(p):
    d1 = {"add": add, "sub": sub, "neg": neg, "and": _and, "or": _or, "not": _not}
    d2 = {"eq": eq, "lt": lt, "gt": gt}
    if p.arg1() in d1:
        return d1[p.arg1()]()
    elif p.arg1() in d2:
        return d2[p.arg1()](str(p.cursor))
    else:
        return '//TO DO (ARITHMETIC)\n'

def operation_two_arg(operation):
    s =  '@SP\n'
    s += 'AM=M-1\n'
    s += 'D=M\n'
    s += 'A=A-1\n'
    s += 'M=' + operation + '\n'
    return s

def operation_one_arg(operation):
    s =  '@SP\n'
    s += 'A=M-1\n'
    s += 'M=' + operation + '\n'
    return s

def add():
    return operation_two_arg('D+M')

def sub():
    return operation_two_arg('M-D')

def neg():
    return operation_one_arg('-M')

def _and():
    return operation_two_arg('D&M')

def _or():
    return operation_two_arg('D|M')

def _not():
    return operation_one_arg('!M')

def condition(name, suffix): #suffix to make label unique
    """
    pseudo-code :
        if (RAM[SP-1] == RAM[SP]) return -1 else return 0
    assembly :
        @SP
        AM=M-1
        D=M
        A=A-1
        D=M-D
        @TRUE
        D;"name"
        @SP
        A=M-1
        M=0
        @END
        0;JMP
        (TRUE)
        @SP
        A=M-1
        M=-1
        (END)
    """
    s =  '@SP\n'
    s += 'AM=M-1\n'
    s += 'D=M\n'
    s += 'A=A-1\n'
    s += 'D=M-D\n'
    s += '@' + 'TRUE' + suffix + '\n' 
    s += 'D;' + name + '\n'
    s += '@SP\n'
    s += 'A=M-1\n'
    s += 'M=0\n'
    s += '@' + 'END' + suffix + '\n'
    s += '0;JMP\n'
    s += '(TRUE' + suffix + ')\n'
    s += '@SP\n'
    s += 'A=M-1\n'
    s += 'M=-1\n'
    s += '(END' + suffix +  ')\n'
    return s

def eq(suffix):
    return condition('JEQ', suffix)

def lt(suffix):
    return condition('JLT', suffix)

def gt(suffix):
    return condition('JGT', suffix)
