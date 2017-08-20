import constants as c
import push_pop
import parser

class CodeWriter: 
    def __init__(self, file_name):
        new_name = file_name.split('.')[0] + '.asm'
        self.file = open(new_name, 'w')
    def write_arithmetic(self, p):
        return
    def write_push_pop(self, p):
        self.file.write('// ' +  p.command)
        if (p.command_type() == c.C_PUSH):
            self.file.write(push_pop.push(p))
