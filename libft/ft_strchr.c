/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:26:12 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/11 21:28:19 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	char	*tmp;

	tmp = (char *)str;
	if (!ch)
		return (tmp);
	while (*tmp)
	{
		if (*tmp == ch)
			return (tmp);
		tmp++;
	}
	return (0);
}
