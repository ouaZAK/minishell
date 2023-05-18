/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:52:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/18 13:09:12 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_search(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == ' ' || line[i] == '\'' || line[i] == '\"' 
			|| line[i] == '>' || line[i] == '<' || line[i] == '|'))
			return (1);
		i++;
	}
	return (0);
}

void	tfri9a(t_list **head, char *line)
{
	int	i;
	int end;
	int start;
	// (void)head;
	i = 0;
	end = 0;
	start = 0;
	while (line[i])
	{
		// printf("c = [%s]\n",line);
		start = end;
		// printf("end = %d\n", end);
		while (line[end])
		{
			if ((line[end] == ' ' || line[end] == '\'' || line[end] == '\"' 
				|| line[end] == '>' || line[end] == '<' || line[end] == '|'
				|| line[end] == '\t'))
			{
				// printf("c[%d] = [%c]\n", end, line[end]);
				break ;
			}
			end++;
		}
		if (end - start != 0)
			ft_lstadd_back(head, ft_lstnew(ft_substr(line, start, end - start)));
		// if (end == (int)(ft_strlen(line)) && !ft_search(line))
		// 	ft_lstadd_back(head, ft_lstnew(line));
		if (line[end])
			ft_lstadd_back(head, ft_lstnew(ft_substr(&line[end], 0, 1)));
		// printf("line[%d]= [%s]    sub[%s]\n", end, &line[end], ft_substr(&line[end], 0, 1));
		end++;
		// printf("line = %s\n", (*head)->str);
		i = end;
		// printf("c = [%c]   end = %d\n",line[end], end);
		
	}
}

int main()
{
	t_list	*head;
	char *line;
	char **str;
	int	 i;

	i = 0;
	str = NULL;
	head = NULL;
	while (1)
	{
		line = readline("> ");
		add_history(line);
		// str = ft_split(line, ':');
		tfri9a(&head, line);
		if (head)
		{
			while (head->next)
			{
				if (!*head->str)
					printf("ha  ");
				printf("head = [%s]   \n", head->str);
				head = head->next;
			}
			printf("head last = [%s]   \n", head->str);
			ft_lstclear(&head);
			// while (head->prev)
			// {
			// 	printf("head = %s\n", head->str);
			// 	head = head->prev;
			// }
			// printf("head = %s   \n", head->str);
		}
	}
}