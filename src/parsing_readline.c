/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_readline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:29:04 by gbierny           #+#    #+#             */
/*   Updated: 2022/09/02 00:14:21 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_double_tab(char *s, int *i, t_shell *shell)
{
	char **new_double_tab;
	int current_element;

	current_element = 0;
	new_double_tab = malloc(sizeof(char *) * (++shell->n_element));
	while (current_element < shell->n_element)
	{
		ft_strlcpy(new_double_tab[current_element], shell->parsed_line[current_element++])
	}
	new_double_tab[current_element] =
	
}

int	check_special_character(char c, t_shell *parsing)
{
    char *special_character;

    special_character = "|:$:<:>:\:<<:>>: ";
	if (s[i] == '<')
}

void	deal_with_quote(char *s, int *i, t_shell *shell)
{
	int	current_quote;
	int n_character;
	int j;

	j = *i;
	current_quote = 0;
	n_character = 0;
	while (s[j] && current_quote < 2)
		n_character++;
	if (!s[j])
		exit (0);
	else
		update_double_tab(i, j, shell);
	*i = j + 1;
}

void	split_readline(char *s, t_shell *shell)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        while ((s[i] >= 9 && s[i] <= 13 )|| s[i] == 43)
            i++;
        if (s[i] != '"' || s[i] != '\'')
            deal_with_quote(s, &i, shell);
        if (s[i])
            update_double_tab(s, i, shell->parsing);
    }
}