/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:21:14 by algaspar          #+#    #+#             */
/*   Updated: 2022/09/02 17:33:06 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

enum {
	CMD,
	PIPE,
	DCHL,
	DCHR,
	CHR,
	CHL,
	SQUOTE,
	DQUOTE,
};

typedef struct s_shell
{
	char	**env;
	int		shlvl;
	char	**parsed_line;
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