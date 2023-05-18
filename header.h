/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:52:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/18 11:36:11 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include<unistd.h>
#include <string.h>
#include <stdlib.h>
#include<dirent.h>
#include <readline/readline.h>

typedef struct s_list {
	char			*str;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;


t_list	*ft_lstnew(char	*str);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);


char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);


#endif