/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/14 14:10:52 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 16:34:08 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:36 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 14:09:46 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_space(char *buff)
{
	int i;
	i = 0;
	while (buff[i] == ' ' || buff[i] == '\n')
		i++;
	if ((buff[i] >= 'a' && buff[i] <= 'z') || (buff[i] >= 'A' && buff[i] <= 'Z'))
		return (1);
	else
		return (0);
}

char		*ft_epure(char *str)
{
	int i;
	int j;

	if (!str)
		return(0);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			str[j] = str[i];
			j++;
			if (str[i + 1] ==  ' ' || str[i + 1] == '\t')
			{
				str[j] = ' ';
				j++;
			}
		}
	}
	str[j] = '\0';
	if (str[j - 1] == ' ')
		str[j - 1] = '\0';
	return (str);
}

int			ft_verif_quote(char *str)
{
	int i = 0;
	int ok = 0;
	while (str[i] != '"')
	{
		if (str[i + 1] == '"' && str[i] != ' ')
		{
			return (0);
			ok = 1;
		}
		i++;
	}
	return (1);

}

int			ft_check_slahsn(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\n' && str[i] == ' ')
	{
		i++;
	}
	return (i);
}
char		*ft_epure_echo(char *str)
{
	int i;
	int ok;
	int j;
	int k = 0;

	if (!str)
		return(0);
	i = 0;
	j = 0;
	ok = 0;
	if (str[i] == ' ')
		while(str[i] == ' ')
			i++;
	k = i;
	while (str[i])
	{
		str[j]  = str[i];
		if (str[i] == ' ')
		{
			i = i + 1;
			while (str[i] == ' ')
			{
				i++;
			}
			if (str[i + 1] == ' ')
			{
				str[j] = str[i + 1];
			}
			j++;
			str[j] = str[i];
			j++;
			i++;
			while (str[i] != '\n')
			{
				if (str[i] == 34 && str[i + 1] == ' ')
				{
					/*printf("mais sa passe la\n");
					int test = ft_check_slahsn(str + i + 1);
					if (test > 0)
					{
					printf("ppppppppp %c\n", str[i]);
						str[i + 1] = str[i];
					printf("ppppppppp %c\n", str[i + 1]);
					}*/
					int test = ft_check_slahsn(str + i  + 1);
					if (test > 0)
					{
						str[i + 1] = str[i];
					}
					str[j] = str[i];
					j++;
					str[j] = ' ';
					j = j + 1;
					i++;
					while (str[i] != '"')
						i++;
					str[j] = str[i];
				}
				str[j] = str[i];
				i++;
				j++;
			}
			str[j] = '\0';
			j = 0;
			//while (str[j])
			return (str);
		}
		i++;
		j++;
	}
	//printf("EPUR %s\n", str);
	str[j] = '\0';
	return (str);
}

int			ft_count2(char *cmd)
{
	int i;
	int co;

	co = 0;
	i = 0;
	while (cmd[i + 1] != '\n')
	{
		co++;
		i++;
	}
	return (co);
}
int g_ok;
char			**ft_str_cmd_spec(char *cmd, t_minishell *shell)
{
	int count;
	count = 0;
	int i= 0;
	int b = 0;
	(void)shell;
	//count = ft_count2(cmd);
	/*printf("TT %d\n", count);
	  shell->cmd = malloc(sizeof(char *) * (count) + 1);
	  printf("PUTIN\n");
	  while (cmd[b + 1] != '\n')
	  {
	  shell->cmd[0][b] = cmd[b];
	  b++;
	  }
	  shell->cmd[0][b] = '\0';
	  printf("****> %s\n", shell->cmd[0]);
	  return (shell->cmd);
	  }*/
	//count  = ft_count2(cmd);
	return (ft_strsplit(cmd, '"'));
	}
int g_p;
char			*ft_check_before(char *cmd)
{
	int i = 0;
	while (cmd[i] != '"')
	{
		i++;
	}
	if (cmd[i - 1] != ' ' && cmd[i] == '"' && cmd[i + 1] != '"')
	{
		g_p = 1;
	}
	else if (cmd[i - 1] != ' ' && cmd[i] == '"' && cmd[i + 1] == '"')
	{
		g_p = 2;
	}
	return (cmd);
}

int			ft_check_quote(char *buff)
{
	int i;
	int co;

	i = 0;
	co  =0;
	while (buff[i])
	{
		if (buff[i] == 34 || buff[i] == 39)
			co++;
		i++;
	}
	return (co);
}

int			ft_is_prime(int nb)
{
	return ((nb % 2 == 0) ? 1 : 0);

}
void		aff_prompt(t_minishell *shell)
{
	char *cmd;
	char *buff;
	int ret;
	int ok = 0;
	int u = 0;
	int i = 0;
	int y = 0;
	int t = 0;
	(void)shell;

	cmd = (char *)malloc(sizeof(char) * (READ_SIZE));
	buff = (char *)malloc(sizeof(char) * (4096));
	ft_putstr("🤠 $> ");
if ((ret = (read(0, buff, READ_SIZE))) != -1)
	{
		if (buff[0] == '/')
		{
		g_p = 1;
			ok = 1;
		cmd = ft_epure(buff);
			while (cmd[t] != '\0')
			{
				if (cmd[t] == ' ' && cmd[t + 1] == '\n')
				{
					cmd[t] = '\n';
				}
			t++;
			}
			shell->cmd = ft_str_cmd(cmd, shell);
			t = 0;
		ft_builtin(cmd, shell);
			return;
		}

		if (ret == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		if (ft_check_space(buff) == 0)
			return;
	
		int co = ft_check_quote(buff);
		int test = ft_is_prime(co);
		if (ft_is_prime(co) != 1)
			return;
		if (co > 1 && ft_is_prime(co) == 1)
		{
			g_a++;
			ft_check_quote(buff);
			cmd = ft_epure_echo(buff);
			cmd = ft_check_before(cmd);
			shell->cmd = ft_str_cmd_spec(cmd, shell);
			int e = 0;
			while (shell->cmd[e])
			{
				if (shell->cmd[e + 1] == NULL)
					//shell->cmd[e + 1] = shell->cmd[e];
				//printf("--------------------> %s\n", shell->cmd[e - 1]);
				if (shell->cmd[e][0] == ' ')
				{
					int u = 0;
					while (shell->cmd[e][u] == ' ')
					{
						u++;
					}
					if (shell->cmd[e][u] == '\0')
						shell->cmd[e] = NULL;
				}
				e++;
			}
			i = 0;
			if (g_p == 1)
			{
				if (shell->cmd[0])
				{
				ft_strcat(shell->cmd[0], shell->cmd[1]);
				}
			}
			if (g_p == 2)
			{
				if (shell->cmd[0])
				{
					int r = 0;
					while (shell->cmd[0][r])
					{
						r++;
					}
					shell->cmd[0][r] = '\0';
					shell->cmd[1] = NULL;
					shell->cmd = shell->cmd;
				}
			}
			else if (g_p == 0)
			{
				while (shell->cmd[0][i] != ' ')
				{
					shell->cmd[0][i] = shell->cmd[0][i];
					i++;
				}
				shell->cmd[0][i] = '\0';

			}
		}
		else
		{
		t = 0;
			cmd = ft_epure(buff);
			while (cmd[t] != '\0')
			{
				if (cmd[t] == ' ' && cmd[t + 1] == '\n')
				{
					cmd[t] = '\n';
				}
			t++;
			}
			shell->cmd = ft_str_cmd(cmd, shell);
			t = 0;
			while(shell->cmd[t])
			{
			t++;

			}
		}
		if (ft_builtin(cmd, shell) == 1)
		{
			return;
		}
		ft_fork(shell);
	}

}
