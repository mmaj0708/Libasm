/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:19:48 by mmaj              #+#    #+#             */
/*   Updated: 2020/12/12 17:19:18 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libasm.h"


void	test_ft_strlen()
{
	char s[] = {"bonjour"};
	char empt_s[] = {""};
	
	printf("------------------------------------\n\n");
	printf("\n-------TEST_FT_STRLEN------\n\n");
	printf("-------regular_string------\n\n");
	printf("check ft_strlen = %lu\n", ft_strlen(s));
	printf("check strlen =    %lu\n\n", strlen(s));
	printf("-------empty_string------\n\n");
	printf("check ft_strlen = %lu\n", ft_strlen(empt_s));
	printf("check strlen =    %lu\n\n", strlen(empt_s));
	printf("------------------------------------\n\n");
}

void	test_ft_strcpy()
{
	char s1[] = {"blabla"};
	char s2[] = {"j'aime jnljbljbmbmb!vkhkmefvqefbqbegbebebebaetbaetbaetbaetbaetb"};
	char empt_s[] = {""};
	char d[300];

	printf("-------TEST_FT_STRCPY------\n\n");
	printf("-------regular_string------\n\n");
	printf("check strcpy = %s\n", strcpy(d, s2));
	printf("check ft_strcpy = %s\n\n", ft_strcpy(d, s2));
	printf("-------empty_string------\n\n");
	printf("check strcpy = %s\n", strcpy(d, ""));
	printf("check ft_strcpy = %s\n\n", ft_strcpy(d, ""));
	printf("------------------------------------\n\n");
}

void	test_ft_strcmp()
{
	char *str1 = {"bonj"};
	char *str2 = {"bon"};
	int d;

	printf("-------TEST_FT_STRCMP------\n\n");
	printf("-------equals_strings------\n\n");
	printf("check ft_strcmp = %d\n", ft_strcmp("bonj", "bon"));
	d = strcmp(str1, str2);
	printf("check strcmp = %d\n\n", d);

	printf("-------first_str_shorter------\n\n");
	printf("check ft_strcmp = %d\n", ft_strcmp(str1, str2));
	printf("check strcmp = %d\n\n", strcmp(str1, str2));
	
	printf("-------second_str_shorter------\n\n");
	printf("check ft_strcmp = %d\n", ft_strcmp("bonjour", "bon"));
	printf("check strcmp = %d\n\n", strcmp("bonjour", "bon"));

	printf("-------first_str_null------\n\n");
	printf("check ft_strcmp = %d\n", ft_strcmp("", "bon"));
	printf("check strcmp = %d\n\n", strcmp("", "bon"));
	
	printf("-------second_str_null------\n\n");
	printf("check ft_strcmp = %d\n", ft_strcmp("bonjour", ""));
	printf("check strcmp = %d\n\n", strcmp("bonjour", ""));	

	printf("-------both_str_null------\n\n");
	printf("check ft_strcmp = %d\n", ft_strcmp("", ""));
	printf("check strcmp = %d\n\n", strcmp("", ""));

	printf("------------------------------------\n\n");
}

void	test_ft_write()
{
	printf("-------TEST_FT_WRITE------\n\n");
	printf("check write ret = %zd\n", write(1, "im writing\n", 11));
	printf("check ft_write ret = %zd\n\n", ft_write(1, "im writing\n", 11));

	printf("------------------------------------\n\n");
}

void	test_ft_read()
{
	char *buf;
	int  fd;
	int  ret;

	printf("-------TEST_FT_READ------\n\n");
	fd = open("Makefile", O_RDONLY);
	buf = malloc(5);
	ret = read(fd, buf, 5);
	buf[ret] = 0;
	printf("check read_ret = %d\ncheck read_buf = %s\n\n", ret, buf);
	ret = ft_read(fd, buf, 5);
	buf[ret] = 0;
	printf("check ft_read_ret = %d\ncheck ft_read_buf = %s\n\n", ret, buf);
	free(buf);
	close(fd);
}

void	test_ft_strdup()
{
	char	*str = {"bonjour\n"};
	char	*m_str;
	char	*str2 = {"bonjour\n"};
	char	*m_str2;

	m_str = strdup(str);
	m_str2 = ft_strdup(str2);
	printf("-------TEST_FT_STRDUP------\n\n");
	printf("check strdup = %s", m_str);
	printf("check ft_strdup = %s\n\n", m_str2);
	free(m_str);
	free(m_str2);

	printf("------------------------------------\n\n");
}

int		main()
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	return (0);
}
