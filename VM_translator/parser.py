import constants

class Parser:
    def __init__(self, file_name):
        with open(file_name) as f:
            self.lines = [line for line in f]
        self.cursor = 0
        self.command = ""
    def has_more_commands(self):
        return self.line_nb < len(self.lines)
    def advance(self):
        if (self.has_more_commands()):
            self.command = self.lines[self.cursor]
            self.cursor += 1
    def command_type(self):
        d = {'add': C_ARITHMETIC, 'sub': C_ARITHMETIC, 'neg': C_ARITHMETIC,\
             'eq': C_ARITHMETIC,  'gt': C_ARITHMETIC, 'lt': C_ARITHMETIC, \
             'and': C_ARITHMETIC, 'or': C_ARITHMETIC, 'not': C_ARITHMETIC, \
             'push': C_PUSH, 'pop': C_POP, '//':C_COMMENT, 'function':C_FUNCTION, \
             'return':C_RETURN, 'label':C_LABEL, 'call':C_CALL, 'goto':C_GOTO]}
        cmd = self.line[self.cursor].split(None, 1)[0]
        return d[cmd] if cmd in d else C_WHITESPACE
    def arg1(self):
        c_type = self.command_type()
        if (c_type == C_RETURN)
            return
        else if (c_type == C_ARITHMETIC)
            return self.command.split(None, 1)[0]
        return (self.line[self.cursor].split(None, 1)[1]
    def arg2(self):
        return (self.line[self.cursor].split(None, 1)[2]
