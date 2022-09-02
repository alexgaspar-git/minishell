/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:21:14 by algaspar          #+#    #+#             */
/*   Updated: 2022/09/02 23:06:54 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

enum {
	CMD,
	PIPE,
	DCHL,
	DCHR,
	CHR,
	CHL,
	SQ,
	DQ,
	DLR,
};

typedef struct s_fpars
{
	int current_type;
	char *current_elem;
	int current_space;
	int switch_squote;
	char *rl_ret;
}			t_fpars;

typedef struct s_shell
{
	char	**env;
	int		shlvl;
	char	**parsed_line;
	t_fpars *parsing;
}	t_shell;

typedef struct s_node
{
	int				type;
	char			*elem;
	int				space;
	struct s_node	*next;
}	t_node;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, char *s2);
void	*ft_malloc(size_t size);
int		ft_strcmp(const char *s1, char *s2);

#endif