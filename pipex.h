/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:29:06 by kkilitci          #+#    #+#             */
/*   Updated: 2023/08/14 15:47:30 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipex {
	int		pipe[2];
	char	**envp;
	char	*path;
	char	*path2;
	char	**left_cmd;
	char	**right_cmd;
	int		infile_fd;
	int		outfile_fd;
	int		exit_state;
	int		execev_error;
}				t_pipex;

char	*ft_strtrim(char *s1, char *set);
int		find_replace(char *argv);
int		ft_wordcount(const char *s, char c);
char	**ft_wordput(const char *s, char c, char **strs);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_nullchecker(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_get_path(char **envp);
char	*ft_access(char *args, char *allpath);
int		error_check(t_pipex *pipexx);
void	retur_exit(t_pipex *pipexx);
void	msg_error(char *err);
int		msg(char *err);
void	free_acces(char **command_paths, char *trim);
void	ft_struct_two(t_pipex *pipexx, char **argv, char **envp);

#endif
