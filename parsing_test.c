/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:52:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/20 14:56:29 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int	ft_search(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if ((line[i] == ' ' || line[i] == '\'' || line[i] == '\"' 
// 			|| line[i] == '>' || line[i] == '<' || line[i] == '|'))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	quote_func(t_vars *va, char *line, int *i)
{
	// if (line[*i] == va->q && (line[*i + 1] == ' ' || line[*i + 1] == '\t' || line[*i + 1] == '|' 
	// 	|| line[*i + 1] == '>' || line[*i + 1] == '<'))
	// 	{
	// 		va->quote = 0;
	// 		return (va->quote);
	// 	}
	// while (line[*i] && line[*i] != va->q)
	// 	(*i)++;
	// if (line[*i] == va->q && (line[*i + 1] == ' ' || line[*i + 1] == '\t' || line[*i + 1] == '|' 
	// || line[*i + 1] == '>' || line[*i + 1] == '<'))
	// {
	// 	va->quote = 0;
	// 	return (va->quote);
	// }
	// va->quote = 1;
	if (line[*i + 1] == '\0')
		return (0);
	if (va->q == line[*i])
		(*i)++;
	while (line[*i] && line[*i] != va->q)
		(*i)++;
	return (0);
}

void	tfri9a(t_vars *va)
{
	while (va->line[va->i])
	{
		va->start = va->end;
		while (va->line[va->end])
		{
			va->q = va->line[va->end];
			if (va->line[va->end] == '\'' || va->line[va->end] == '"')
				quote_func(va, va->line, &va->end);
			if (!va->quote && (!va->line[va->end] || va->line[va->end] == ' ' || va->line[va->end] == '>' || va->line[va->end] == '<' 
				|| va->line[va->end] == '|' || va->line[va->end] == '\t'))
				break ;
			va->end++;
		}
		if (va->end - va->start != 0)
			ft_lstadd_back(&va->head, ft_lstnew(ft_substr(va->line, va->start, va->end - va->start)));
		if (va->line[va->end] && va->line[va->end] != ' ' && va->line[va->end] != '\t')
			ft_lstadd_back(&va->head, ft_lstnew(ft_substr(&va->line[va->end], 0, 1)));
		va->end++;
		va->i = va->end;
	}
}

void	init(t_vars *va)
{
	va = NULL;
	va->dollar = 0;
	va->i = 0;
	va->end = 0;
	va->start = 0;
	va->head = NULL;
	va->line = NULL;
}

int main()
{
	t_vars	va;

	init(&va);
	while (1)
	{
		va.line = readline("> ");
		add_history(va.line);
		tfri9a(&va);
		if (va.head)
		{
			while (va.head->next)
			{
				if (!*va.head->str)
					printf("ha  ");
				printf("va.head = [%s]   \n", va.head->str);
				va.head = va.head->next;
			}
			printf("va.head last = [%s]   \n", va.head->str);
			ft_lstclear(&va.head);
			// while (head->prev)
			// {
			// 	printf("head = %s\n", head->str);
			// 	head = head->prev;
			// }
			// printf("head = %s   \n", head->str);
		}
	}
}