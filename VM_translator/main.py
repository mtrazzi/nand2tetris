#!/usr/bin/python3
import sys
import constants as c 
import code_writer
import parser

file_name = sys.argv[1]
p = parser.Parser(file_name)
cw = code_writer.CodeWriter(file_name)
while (p.has_more_commands()):
    p.advance()
    c_type = p.command_type()
    if (c_type == c.C_ARITHMETIC):
        cw.write_arithmetic(p)
    elif (c_type in [c.C_PUSH, c.C_POP]):
        cw.write_push_pop(p)
cw.close()
