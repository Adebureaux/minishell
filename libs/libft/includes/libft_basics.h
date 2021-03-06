/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_basics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:05:47 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 21:10:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BASICS_H
# define LIBFT_BASICS_H

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dest, void *src, size_t len);
void				*ft_memccpy(void *dest, void *src, int c, size_t len);
void				*ft_memmove(void *dest, void *src, size_t len);
void				*ft_memchr(void *str, int c, size_t len);
int					ft_memcmp(void *s1, void *s2, size_t len);
size_t				ft_strlen(char *str);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
void				ft_strcat(char *dest, char *src);
void				ft_strncat(char *dest, char *src, size_t n);
size_t				ft_strlcat(char *dst, char *src, size_t size);
char				*ft_strchr(char *s, char c);
char				*ft_strrchr(char *str, char c);
char				*ft_strstr(char *str, char *find);
char				*ft_strnstr(char *str, char *find, size_t len);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, size_t n);
bool				ft_strcmp_c(char *p_src, char p_target);
int					ft_atoi(char *str);
bool				ft_is_even(int nbr);
bool				ft_isalpha(int c);
bool				ft_isdigit(int c);
bool				ft_isalnum(int c);
bool				ft_isascii(int c);
bool				ft_isprint(int c);
bool				ft_isnum(int c);
bool				ft_strisalpha(char *str);
bool				ft_strisdigit(char *str);
bool				ft_strisalnum(char *str);
bool				ft_strisascii(char *str);
bool				ft_strisprint(char *str);
bool				ft_strisnum(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
int					ft_strequ(char *s1, char *s2);
int					ft_strnequ(char *s1, char *s2, size_t n);
char				*ft_strsub(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s);
char				**ft_split(char *s, char c);
char				**ft_strtok(char *s, char *sep);
char				*ft_itoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_add_to_tab(void *to_add, void ***tab);
void				ft_tab_cpy(void **dst, void **src);
void				ft_tab_dup(void **dst, void **src);
void				ft_tab_free(char **tab);
void				ft_sort_tab(void **tab, int size);
int					ft_tab_len(void	**tab);
void				**ft_tab_new(int size);
int					*ft_intparse_tab(char **tab);
int					**ft_inttab_new(int size);
int					*ft_int_str_new(int size);
void				ft_inttab_cpy(int **dest, int **src);
void				ft_print_str_tab(char *p_name, char **p_tab);
void				ft_add_to_front_tab(void *to_add, void ***tab);
void				ft_print_int_tab(char *p_name, int **p_tab);
void				ft_putinttab(int **tab, int len);
int					ft_abs(int src);
void				ft_swap_int(int *a, int *b);
void				ft_swap_float(float *a, float *b);
void				ft_swap_tab(void **sort, int i);
int					ft_min(int nb_number, ...);
int					ft_max(int nb_number, ...);
bool				ft_strcchr(char *str, char c);
char				*ft_strcut(char **src, char delim);
int					nbr_len(long long n, int base);
void				ft_str_replace_front(char *s2, char **s1);
void				ft_str_replace_back(char **s1, char *s2);
void				ft_target_strncat(char *s1, char *s2,
						size_t start, size_t len);
void				ft_str_toupper(char *str);
char				*ft_str_fill(char	*str, char c, int i);
char				*ft_strnew_c(size_t len, char c);
char				*ft_itoa_base(long long n, int base);
char				*ft_uitoa_base(unsigned long long n, int base);
char				*ft_uitoa(unsigned long long n);
void				ft_str_replace_front(char *s2, char **s1);
void				ft_str_replace_back(char **s1, char *s2);

#endif
