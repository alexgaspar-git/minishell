/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_readline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:29:04 by gbierny           #+#    #+#             */
/*   Updated: 2022/09/03 00:01:45 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	lst_add_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (node && new)
	{
		if (!*node)
			*node = new;
		else
		{
			last = last_node(*node);
			last->next = new;
		}
		new->next = NULL;
	}
}

create_list(t_fpars *parsing, *i, j, s)
{
	t_node list;
	list.type = parsing->current_type;
	if (parsing->current_type && parsing->current_type != DLR)
		list.elem = NULL;
	if (list.type == DCHL)
		(*i)++;
	if (list.type == DCHR)
		(*i)++;
	if ()
	list.space = parsing->current_space;
	list.next = NULL;
}

int	check_special_character(char c, t_shell *shell)
{
    char *special_character;

	if (s[i] == '<')
	{
		shell->parsing->current_elem = NULL;
		if (s[i + 1] == '<')
			lst_add_back(create_list(ca))
		else if (s[i + 1] == '>')
			shell->parsing->current_type = CHL;
			lst_add_back(create_list());
		else
	}
	else if (s[i] == '>')
	{
		if (s[i + 1] == '>')
			shell->parsing->current_type == DCHR;
		else
	}
}

int	til_special(char *s, char c)
{
	while (s++)
	{
		if (c == *s)
			return (1);
	}
	return (0);
}

char	*ft_strndup(const char *s, int i, int j)
{
	char	*dst;

	dst = malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, i);
	return (dst);
}

void change_read_line(t_shell *sl, char *s, int i, int j)
{
	int k;
	char *end_line;
	char *new_read_line;
	k = 0;
	end_line = ft_strdup(sl->parsing->rl_ret + i + j);
	while (s[i] == '=')
		i++;
	while (s[++i])
		k++;
	new_read_line = malloc(sizeof(char) * (i + k + ft_strlen(s + j) + 1))
	if (!new_read_line)
		error_message("error: erreur de malloc");
	
}

replace_with_env(t_shell *sl, char *s, int *i)
{
	int curr_env_el;
	int j;
	char *env_v;
	j = (*i) + 1;
	curr_env_el = 0;
	while (s[j] && !til_special("<>$| ", s[j]))
		j++;
	j = j - (*i);
	env_v = ft_strndup(s + (*i), j));
	while (sl->env[curr_env_el])
	{
		if (!ft_strncmp(sl->env[curr_env_el], env_v))
			return (change_read_line(sl, sl->env[curr_env_el])); //remplace les dollars par la valeur env;
		j++;
	}
}

deal_with_dollar(t_shell *sl, int i)
{
	while (sl->parsing->rl_ret[i])
	{
		if (sl->parsing->rl_ret[i] == '\'')
		{
			if (!sl->parsing->switch_squote)
				sl->parsing->switch_squote = 1;
			else
				sl->parsing->switch_squote = 0;
		}
		if (sl->parsing->rl_ret[i] = '$')
		{
			if (sl->parsing->rl_ret[i + 1] == '?')
				deal_with_?();
		}
		else
			replace_with_env(sl, i);
		
		
	}
}

void	deal_with_quote(int *i, t_shell *sl)
{
	int	current_quote;
	int n_character;
	int j;
	char *elem;
	j = *i;
	current_quote = 0;
	n_character = 0;
	sl->parsing->current_type = DQ;
	while (sl->parsing->rl_ret[j] && current_quote < 2)
		n_character++;
	if (!sl->parsing->rl_ret[j])
	{
		ft_strlcpy(elem, sl->parsing->rl_ret + (*i), j -(*i))

		lst_add_back(create_list(elem, ));
	}
	else
		lst_add_back(create_list(i, j, sl));
	*i = j + 1;
}

void	split_readline(t_shell *shell)
{
    int i;
    
    i = 0;
    while (shell->parsing->rl_ret[i])
    {
		shell->parsing->current_space = 0;
        while ((shell->parsing->rl_ret[i] >= 9 && shell->parsing->rl_ret[i] <= 13 )|| shell->parsing->rl_ret[i] == 43)
		{
			shell->parsing->current_space = 1;	
            i++;
		}
        if (shell->parsing->rl_ret[i] != '"' || shell->parsing->rl_ret[i] != '\'')
            deal_with_quote(&i, shell); //
        else if (check_special_character(shell->parsing->rl_ret[i]))
			;
		else
			deal_basic_char(i, shell);
    }
}