/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:38:54 by akalombo          #+#    #+#             */
/*   Updated: 2019/07/26 17:55:06 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <time.h>      //working with the time and the ctime functions
# include <dirent.h>    //working with the opendir, readdir and closedir functions
# include <sys/stat.h>  //working with the stat function and lstat functions
# include <sys/types.h> //
# include <pwd.h>       //working with the passwd struct;
# include <uuid/uuid.h> //working with the uuid_t data type
# include <sys/xattr.h> //working with the listaxttr and the getxattr functions
# include <stdlib.h>    //working with the malloc, exit and free functions
# include <string.h>    //working with the strerror function
# include <stdio.h>     //working with the perror function
# include <errno.h>
# include <stdio.h>     //remember to remove
# define POTENTIAL_FLAG '-'
# define HIDDEN_FILES 'a'
# define FILE_DETAILS 'l'
# define RECURSIVE_LS 'R'
# define SORT_LAST_MODI 't'
# define SORT_REV_LEXO 'r'
char 	**bubble_sort(char **str);
void	revers_flag(int argc, char **content);
void	no_flags(int argc, char **content);
void	hidden_flag(int argc, char **content, char *argv);
void    get_content(int tot, int argc, char *argv);
void    count_content(struct dirent *files, DIR *mydir, int argc, char *argv);
void	file_info(char **content, char  *argv);
enum output
{
    SUCCESS,
    FAILED = -1
};
#endif
