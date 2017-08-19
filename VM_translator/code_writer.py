import constants
import push_pop
import parser

class CodeWriter: 
    def __init__(self, file_name, parser):
        new_name = file_name.rsplit('.', 1)[1] + '.asm' 
        self.file = open(new_name, 'w')
        self.parser = parser
    def write_arithmetic(self):
        
    def write_push_pop(self, command):
        if (self.parser.command_type() == C_PUSH):
            push(self.parser)
    
             
        
        
