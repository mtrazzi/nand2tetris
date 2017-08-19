import sys
import constants
import code_writer
import parser

file_name = sys.argv[1]
p = Parser(file_name)
while (p.has_more_commands()):
    p.advance()
    c = CodeWriter(file_name, parser)
    c_type = p.command_type()
    if (c_type == C_ARITHMETIC)
        write_arithmetic(p.command)
    else if (c_type in [C_PUSH, C_COMMENT])
        write_push_pop(p.command)
