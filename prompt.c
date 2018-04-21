/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:36 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 14:19:27 by jecombe     ###    #+. /#+    ###.fr     */
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
char		*ft_epure_echo2(char *str)
{
	int i;
	int ok;
	int ok2;
	ok2 = 0;
	char	*result;
	int j  = 0;
	ok = 0;
	i = 0;
	if (str[i] == ' ')
		while (str[i] == ' ')
			i++;
	while (str[i])
	{
		if (str[i] == '"')
			ok++;
		if (str[i] == ' ' && ft_is_prime(ok) == 1)
			while (str[i + 1] == ' ')
				i++;
		str[j] = str[i];
		j++;
		i++;
	}
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
	return (ft_strsplit(cmd, '"'));
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
char		*ft_ajout_quote(char *str)
{
	int i = 0;
	int ok = 0;
	int j = 0;
	int ok2 = 0;
	while (str[i])
	{
		if (str[i] == '"')
			ok++;
		if (str[i] == ' ' && ft_is_prime(ok) == 1)
		{
			ok2++;
			if (str[i + 1] != '"')
			{
				if (ok2 == 1)
				{
					str[i] = ' ';
					i++;
				}
				str[i] = '"';
				i++;
			}
		}
		i++;
	}
	str[i] = '"';
	str[i + 1] = '\0';
	return(str);

}

char		*ft_ajout_quote2(char *str)
{
	int i = 0;
	int ok = 0;
	int j = 0;
	int ok2 = 0;
	char	*result;
	result =ft_strnew(4096);

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '"')
		{
			if (ft_is_prime(ok) == 0)
			{
				//i = i - 1;
			}
			else
				i++;
			ok++;
		}
		if (str[i] == ' ' && ft_is_prime(ok) == 1 && str[i + 1] != '"')
		{

			result[j] = '"';
			i++;
			j++;
		}
		result[j] = str[i];
		i++;
		j++;
	}
	if (result[j - 1] != '"')
	{
		result[j] = '"';
		j++;
	}
result[j] = '\0';
	return(result);

}

char			*delete(char **cmd)
{
	int u;
	int i;

	u = 0;
	i = 0;
	while (cmd[0][u] != ' ')
	{
		cmd[0][i] = cmd[0][u];
		u++;
		i++;
	}
	cmd[0][i] = '\0';
	return(cmd[0]);


}
void		aff_prompt(t_minishell *shell)
{
	char *cmd;
	char *buff;
	int ret;
	int u = 0;
	int i = 0;
	int t = 0;
	int e = 0;
	int co;
	int prime;

	cmd = (char *)malloc(sizeof(char) * (4096));
	buff = (char *)malloc(sizeof(char) * (4096));
	ft_putstr_color("[", 10);
	ft_putstr(STOP);
	ft_putstr_color(user, 14);
	ft_putstr(STOP);
	ft_putstr_color("]", 10);
	ft_putstr(STOP);
	ft_putstr_color("==> ", 9);
	ft_putstr(STOP);
	if ((ret = (read(0, buff, READ_SIZE))) != -1)
	{
		/*if (ft_strchr(buff, ';'))
		{
			printf("yes %s\n", buff);
			shell->test = ft_strsplit(buff, ';');
			int rr;
			rr = 0;
			while (shell->test[rr])
			{
				printf("--> %s\n", shell->test[rr]);
				rr++;
			}
		}*/
		if (ft_strchr(buff, (int)'/') != NULL)
		{
			cmd = ft_epure(buff);
		if (buff[0] == '/')
		{
			g_p = 1;
			//cmd = ft_epure(buff);
			while (cmd[t] != '\0')
			{
				if (cmd[t] == ' ' && cmd[t + 1] == '\n')
					cmd[t] = '\n';
				t++;
			}
			shell->cmd = ft_str_cmd(cmd, shell);
			ft_builtin(cmd, shell);
			return;
		}
	}
		if (ret == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		if (ft_check_space(buff) == 0)
			return;

		co = ft_check_quote(buff);
		prime = ft_is_prime(co);
		if (prime != 1)
			return;
		if (co > 1 && prime == 1)
		{
			ft_check_quote(buff);
			cmd = ft_epure_echo2(buff);
			//printf("apres epure: %s\n", cmd);
			cmd = ft_ajout_quote2(cmd);
			//printf("apres ajout: %s\n", cmd);
			shell->cmd = ft_str_cmd_spec(cmd, shell);
			/*while (shell->cmd[e])
				e++;
			while (shell->cmd[e - 1][u])
				u++;
			shell->cmd[e - 1][u - 1] = '\0';
			shell->cmd[0] = delete(shell->cmd);
			int o = 0;
			while (shell->cmd[o])
			{
				if (ft_isprint((int)shell->cmd[o][0]) == 0)
					u = o;
				o++;
			}
			//shell->cmd[u] = NULL;*/
		}
		else
		{
			cmd = ft_epure(buff);
			while (cmd[t])
			{
				if (cmd[t] == ' ' && cmd[t + 1] == '\n')
					cmd[t] = '\n';
				t++;
			}
			shell->cmd = ft_str_cmd(cmd, shell);
			t = 0;
			e = 0;
			while (shell->cmd[t])
			{
				/*while (shell->cmd[t][e])
				{
					printf("-/-/-/-/-/-/ %c\n", shell->cmd[t][e]);
					e++;
				}*/
				e = 0;
				t++;
			}

		}
		if (ft_builtin(cmd, shell) == 1)
			return;
		ft_fork(shell);
	}

}
