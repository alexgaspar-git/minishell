/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:21:14 by algaspar          #+#    #+#             */
/*   Updated: 2022/09/02 00:08:24 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_f_parsing
{
	char *s_character;
	int switch_button;
}			t_f_parsing;

typedef struct s_shell
{
	char	**env;
	int		shlvl;
	int n_element;
	char	**parsed_line;
	t_f_parsing *parsing;
}	t_shell;


size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, char *s2);
void	*ft_malloc(size_t size);
int		ft_strcmp(const char *s1, char *s2);


#endif