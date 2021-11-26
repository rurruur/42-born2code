/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:00:58 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/26 15:02:20 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*last_match;

	tmp = (char *)s;
	last_match = 0;
	while (*tmp)
	{
		if (*tmp == (char)c)
			last_match = tmp;
		tmp++;
	}
	if (!c)
		return (tmp);
	return (last_match);
}
