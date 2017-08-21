import constants as c
import push_pop
import arithmetic
import parser

class CodeWriter: 
    def __init__(self, file_name):
        new_name = file_name.split('.')[0] + '.asm'
        self.file = open(new_name, 'w')
    def write_arithmetic(self, p):
        self.file.write('//' + p.command)
        self.file.write(arithmetic.arithmetic(p))
        return
    def write_push_pop(self, p):
        self.file.write('// ' +  p.command)
        if (p.command_type() == c.C_PUSH):
            self.file.write(push_pop.push(p))
        else:
            self.file.write(push_pop.pop(p))
    def close(self):
        self.file.close()

