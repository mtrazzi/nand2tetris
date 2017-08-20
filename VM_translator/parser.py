import constants as c

class Parser:
    def __init__(self, file_name):
        with open(file_name) as f:
            self.lines = [line for line in f]
        self.cursor = -1
        self.command = ""
        self.file_name = file_name.split('.')[0]
    def __str__(self):
        return "\tcursor: {CURSOR}\n\tcommand: {COMMAND}".format(CURSOR=self.cursor, COMMAND=self.command)
    def has_more_commands(self):
        return self.cursor < len(self.lines) - 1
    def advance(self):
        if (self.has_more_commands()):
            self.cursor += 1
            self.command = self.lines[self.cursor]
    def command_type(self):
        if (len(self.lines[self.cursor].split(None)) == 0):
            return c.C_WHITESPACE 
        cmd = self.lines[self.cursor].split(None, 1)[0]
        return c.dic[cmd]
    def arg1(self):
        c_type = self.command_type()
        if (c_type == c.C_RETURN):
            return
        elif (c_type == c.C_ARITHMETIC):
            return self.command.split(None)[0]
        return self.lines[self.cursor].split(None)[1]
    def arg2(self):
        return self.lines[self.cursor].split(None)[2]
