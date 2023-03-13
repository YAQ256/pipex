/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlastchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:36:24 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/13 16:22:11 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlastchr(char *s1, char c)
{
	size_t	len_prefix;
	char	*new_string;

	len_prefix = ft_strlen(s1);
	new_string = malloc(sizeof(char) * (len_prefix + 1) + 1);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, len_prefix + 2);
	free (s1);
	new_string[len_prefix] = c;
	new_string[len_prefix + 1] = '\0';
	return (new_string);
}
