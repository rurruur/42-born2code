/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:00:58 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/09 18:07:07 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	char	*tmp;
	char	*last_match;

	tmp = (char *)str;
	last_match = 0;
	while (*tmp)
	{
		if (*tmp == ch)
			last_match = tmp;
		tmp++;
	}
	if (!ch)
		return (tmp);
	return (last_match);
}
