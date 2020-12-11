/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:19:48 by mmaj              #+#    #+#             */
/*   Updated: 2020/12/11 16:11:23 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	test_ft_strdup()
{
	char	*str = {"bonjour\n"};
	char	*m_str;
	char	*str2 = {"bonjour\n"};
	char	*m_str2;

	m_str = strdup(str);
	m_str2 = ft_strdup(str2);
	printf("-------test_ft_strdup------\n\n");
	printf("check strdup = %s", m_str);
	printf("check ft_strdup = %s\n\n", m_str2);
}

void	test_ft_strlen()
{
	char s[] = {"bonjour"};
	
	printf("\n-------test_ft_strlen------\n\n");
	printf("check ft_strlen = %lu\n", ft_strlen(s));
	printf("check strlen =    %lu\n\n", strlen(s));
}

void	test_ft_strcpy()
{
	char s1[] = {"oooooo"};
	char s2[] = {"ooooodht"};

	printf("-------test_ft_strcpy------\n\n");
	printf("check ft_strcpy = %s\n", ft_strcpy(s1, s2));
	printf("check strcpy = %s\n\n", strcpy(s1, s2));
}

void	test_ft_strcmp()
{
	char *str1 = {""};
	char *str2 = {"g"};

	printf("-------test_ft_strcmp------\n\n");
	printf("check ft_strcmp = %d\n", ft_strcmp(str1, str2));
	printf("check strcmp = %d\n\n", strcmp(str1, str2));
}

void	test_ft_write()
{
	printf("-------test_ft_write------\n\n");
	printf("check write ret = %zd\n", write(1, "im writing\n", 11));
	printf("check ft_write ret = %zd\n\n", ft_write(1, "im writing\n", 11));
}

int		main()
{
	char s[] = {"bonjour"};
	char s1[] = {"oooooo"};
	char s2[] = {"ooooodht"};
	char *str1 = {""};
	char *str2 = {"g"};
	char *buf;
	int  fd;
	int  ret;

	test_ft_strlen();

	test_ft_strcpy();

	test_ft_strcmp();

	test_ft_write();
		
	printf("-------test_ft_read------\n\n");
	fd = open("Makefile", O_RDONLY);
	buf = malloc(5);
	ret = read(fd, buf, 5);
	buf[ret] = 0;
	printf("check read_ret = %d\ncheck read_buf = %s\n\n", ret, buf);
	ret = ft_read(fd, buf, 5);
	buf[ret] = 0;
	printf("check ft_read_ret = %d\ncheck ft_read_buf = %s\n\n", ret, buf);
	free(buf);

	test_ft_strdup();

	// free(s1);
	return (0);
}
