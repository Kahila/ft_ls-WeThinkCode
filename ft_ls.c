/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:16 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/09 12:31:07 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
#include <stdio.h>//remember to remove

int main(int argc, char **argv)
{
	DIR *mydir;
	struct dirent *files=NULL;
	mydir = opendir(".");
	count_content(files, mydir, argc,argv[1]);
	closedir(mydir);
	// if (valid_flag(argc, argv) == INVALID_FLAG)
	// 	return (INVALID_FLAG);
	printf(">>%s", get_flags(argc, argv));
	return (SUCCESS);
}