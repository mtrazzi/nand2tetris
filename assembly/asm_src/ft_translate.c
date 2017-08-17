#include "asm.h"

char	*ft_translate_a_instruction(char *line)
{
	int 	n;
	int 	i;
	char	*str;

	n = ft_atoi(line + 1);
	i = 0;
	str = ft_strnew(17);
	while (i < 15)
	{
		str[15 - i] = '0' + (n % 2);
		n /= 2;
		i++;
	}
	str[0] = '0';
	str[16] = '\n';
	return (str);
}

void	ft_parse_destination(char *line, t_cins *t)
{
	int			i;

	t->d[0] = '0';
	t->d[1] = '0';
	t->d[2] = '0';
	if (!(ft_strchr(line, '=')))
		return ;
	i = -1;
	while (line[++i] != '=')
	{
		if (line[i] == 'A')
			t->d[0] = '1';	
		if (line[i] == 'D')
		{
			t->d[1] = '1';
		}
		if (line[i] == 'M')
			t->d[2] = '1';
	}
}

void	ft_change_c(char *str, t_cins *t)
{
	t->c[0] = str[0];
	t->c[1] = str[1];
	t->c[2] = str[2];
	t->c[3] = str[3];
	t->c[4] = str[4];
	t->c[5] = str[5];

}

void	ft_change_j(char *str, t_cins *t)
{
	t->j[0] = str[0];
	t->j[1] = str[1];
	t->j[2] = str[2];
}

void	ft_parse_computation(char *line, t_cins *t)
{
	char		*str;

	if (!ft_strchr(line, '=') && !ft_strchr(line, ';'))
		return ;
	if (ft_strchr(line, '='))
		str = ft_strchr(line, '=') + 1;
	else
		str = line;
	if(ft_strchr(str, ';'))
		*(ft_strchr(str, ';')) = '\0';
	t->a = (ft_strchr(str, 'M') ? '1' : '0');
	if (!ft_strcmp(str, "0"))
		ft_change_c("101010", t);
	else if (!ft_strcmp(str, "1"))
		ft_change_c("111111", t);
	else if (!ft_strcmp(str, "-1"))
		ft_change_c("111010", t);
	else if (!ft_strcmp(str, "D"))
		ft_change_c("001100", t);
	else if (!ft_strcmp(str, "A"))
		ft_change_c("110000", t);
	else if (!ft_strcmp(str, "!D"))
		ft_change_c("001101", t);
	else if (!ft_strcmp(str, "!A"))
		ft_change_c("110001", t);
	else if (!ft_strcmp(str, "-D"))
		ft_change_c("001111", t);
	else if (!ft_strcmp(str, "-A"))
		ft_change_c("110011", t);
	else if (!ft_strcmp(str, "D+1"))
		ft_change_c("011111", t);
	else if (!ft_strcmp(str, "A+1"))
		ft_change_c("110111", t);
	else if (!ft_strcmp(str, "D-1"))
		ft_change_c("001110", t);
	else if (!ft_strcmp(str, "A-1"))
		ft_change_c("110010", t);
	else if (!ft_strcmp(str, "D+A"))
		ft_change_c("000010", t);
	else if (!ft_strcmp(str, "D-A"))
		ft_change_c("010011", t);
	else if (!ft_strcmp(str, "A-D"))
		ft_change_c("000111", t);
	else if (!ft_strcmp(str, "D&A"))
		ft_change_c("000000", t);
	else if (!ft_strcmp(str, "D|A"))
		ft_change_c("010101", t);
	else if (!ft_strcmp(str, "M"))
		ft_change_c("110000", t);
	else if (!ft_strcmp(str, "!M"))
		ft_change_c("110001", t);
	else if (!ft_strcmp(str, "-M"))
		ft_change_c("110011", t);
	else if (!ft_strcmp(str, "M+1"))
		ft_change_c("110111", t);
	else if (!ft_strcmp(str, "M-1"))
		ft_change_c("110010", t);
	else if (!ft_strcmp(str, "D+M"))
		ft_change_c("000010", t);
	else if (!ft_strcmp(str, "D-M"))
		ft_change_c("010011", t);
	else if (!ft_strcmp(str, "M-D"))
		ft_change_c("000111", t);
	else if (!ft_strcmp(str, "D&M"))
		ft_change_c("000000", t);
	else if (!ft_strcmp(str, "D|M"))
		ft_change_c("010101", t);
}

void	ft_parse_jump(char *line, t_cins *t)
{
	char *str;

	t->j[0] = '0';
	t->j[1] = '0';
	t->j[2] = '0';
	str = ft_strchr(line, ';');		
	if (!str)
		return ;
	str++;
	if (!ft_strcmp(str, "JGT"))
		ft_change_j("001", t);
	else if (!ft_strcmp(str, "JEQ"))
		ft_change_j("010", t);
	else if (!ft_strcmp(str, "JGE"))
		ft_change_j("011", t);
	else if (!ft_strcmp(str, "JLT"))
		ft_change_j("100", t);
	else if (!ft_strcmp(str, "JNE"))
		ft_change_j("101", t);
	else if (!ft_strcmp(str, "JLE"))
		ft_change_j("110", t);
	else if (!ft_strcmp(str, "JMP"))
		ft_change_j("111", t);
}

t_cins	*ft_parse_c_instruction(char *line)
{
	t_cins	*t;

	t = (t_cins *)ft_memalloc(sizeof(t_cins));
	ft_parse_destination(line, t);
	ft_parse_jump(line, t);
	ft_parse_computation(line, t);
	return (t);	
}
