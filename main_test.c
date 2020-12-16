/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:19:48 by mmaj              #+#    #+#             */
/*   Updated: 2020/12/16 16:01:24 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libasm.h"


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
	char s2[] = {"j'aime jnljbljbmbmb!vkhkmefvqefbqbegbeb"};
	char d[300];

	printf("-------TEST_FT_STRCPY------\n\n");
	printf("-------regular_string------\n\n");
	printf("check strcpy = \"%s\"\n", strcpy(d, s2));
	printf("check ft_strcpy = \"%s\"\n\n", ft_strcpy(d, s2));
	printf("-------empty_string------\n\n");
	printf("check strcpy = \"%s\"\n", strcpy(d, ""));
	printf("check ft_strcpy = \"%s\"\n\n", ft_strcpy(d, ""));
	printf("------------------------------------\n\n");
}

void	test_ft_strcmp(const char *s1, const char *s2)
{
	printf("check ft_strcmp = %d\n", ft_strcmp(s1, s2));
	printf("check strcmp = %d\n\n", strcmp(s1, s2));
}

void	test_ft_write(int fd, const void *buf, ssize_t n)
{
	int d;

	printf("write output | ");
	errno = 0;
	d =	write(fd, buf, n);
	printf("return value is : %d | errno = %d\n", d, errno);
	printf("ft_write output | ");
	errno = 0;
	d =	ft_write(fd, buf, n);
	printf("return value is : %d | errno = %d\n", d, errno);
}

void	test_ft_read(char *file, int n)
{
	char buf1[300];
	char buf2[300];
	int  i;
	int  fd;
	int  ret;

	i = 0;
	while (i < 300)
	{
		buf1[i] = 0;
		buf2[i++] = 0;
	}
	errno = 0;
	fd = open(file, O_RDONLY);
	ret = read(fd, buf1, n); 
	printf("read_buf = \"%s\"\n", buf1);
	printf("read_ret = %d\n", ret);
	printf("read_errno = %d\n", errno);
	close(fd);

	errno = 0;
	fd = open(file, O_RDONLY);
	ret = ft_read(fd, buf2, n);
	printf("ft_read_buf = \"%s\"\n", buf2);
	printf("ft_read_ret = %d\n", ret);
	printf("ft_read_errno = %d\n", errno);
	close(fd);
}

void	test_ft_strdup(const char *s)
{
	char	*m_str;
	char	*m_str2;

	errno = 0;
	m_str = strdup(s);
	printf("strdup = \"%s\"\n", m_str);
	printf("errno = %d\n", errno);
	free(m_str);
	errno = 0;
	m_str2 = ft_strdup(s);
	printf("ft_strdup = \"%s\"\n", m_str2);
	printf("errno = %d\n", errno);
	free(m_str2);
}

int		main()
{
	test_ft_strlen();
	test_ft_strcpy();

	printf("-------TEST_FT_STRCMP------\n\n");
	printf("equals_strings------\n");
	test_ft_strcmp("bonjour", "bonjour");
	printf("first_str_shorter------\n");
	test_ft_strcmp("bonj", "bonjour");
	printf("second_str_shorter------\n");
	test_ft_strcmp("bonjour", "bonjo");
	printf("first_str_null------\n");
	test_ft_strcmp("", "bonjour");
	printf("second_str_null------\n");
	test_ft_strcmp("bonj", "");
	printf("both_str_null------\n");
	test_ft_strcmp("", "");

	printf("-------TEST_FT_WRITE------\n\n");
	printf("regular_stdout------\n");
	test_ft_write(1, "Im regular output\n", 18);
	printf("\nregular_stderr------\n");
	test_ft_write(2, "Im stderr  output\n", 18);
	printf("\nnegative len------\n");
	test_ft_write(1, "Im negative len output\n", -23);
	printf("\nnegative fd------\n");
	test_ft_write(-2, "Im negative fd output\n", 22);

	printf("\n-------TEST_FT_READ------\n");
	printf("\nlen > file_size------\n");
	test_ft_read("test.txt", 250);
	printf("\nlen < file_size------\n");
	test_ft_read("test.txt", 25);
	printf("\nlen < 0------\n");
	test_ft_read("test.txt", -50);

	printf("\n-------TEST_FT_STRDUP------\n");
	printf("\nregular str------\n");
	test_ft_strdup("j'aime le fromage");
	printf("\nempty str------\n");
	test_ft_strdup("");
	return (0);
}
