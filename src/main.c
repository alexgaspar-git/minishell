/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:13:43 by algaspar          #+#    #+#             */
/*   Updated: 2022/09/01 22:37:48 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_size(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

void	init_shell(t_shell **shell, char **envp)
{
	int	i;

	i = 0;

	*shell = ft_malloc(sizeof(t_shell));
	(*shell)->env = ft_malloc(sizeof(char *) * env_size(envp));
	while (envp[i])
	{
		(*shell)->env[i] = ft_strdup(envp[i]);
		i++;
	}
	(*shell)->env[i] = NULL;
	(*shell)->shlvl = 1;

}

void	parsing(t_shell **shell, char *line)
{
	
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	char	*line;

	if (argc != 1)
		return (1);
	(void)argv;
	init_shell(&shell, envp);
	while (1)
	{
		line = readline("mini$hell~");
		add_history(line);
		parsing(&shell, line);
		execution(shell);
		free(line);
	}
	return (0);
}