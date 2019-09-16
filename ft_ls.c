/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <akalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:51:16 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 11:50:35 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"
#include <stdio.h> //remember to remove

//method that will be used to check if the parsed file is a folder or not
void valid_file(char **content, char **args)
{
	int i;
	int j;
	int found;

	i = 0;
	found = 0;
	while (args[i])
	{
		printf("====%s", args[i]);
		i++;
	}
	i = 0;
	while (args[i])
	{
		j = 0;
		while (content[j])
		{
			//printf(">>>%s\n", content[j]);
			printf("+++here\n");
			if ((ft_strcmp(args[i], content[j])) == 0)
			{
				ft_putstr(args[i]);
				found = 1;
			}
			j++;
		}
		i++;
	}
	if (found == 0)
		ft_putstr(" : no such file or directory\n");
}

//method that will be used to display the content
void print_content(char **content, t_flags *flags)
{
	int i;

	i = 0;
	while (content[i] && flags->l != 1)
	{
		if (flags->a == 1 && content[i][0] == '.')
		{
			ft_putstr(content[i]);
			ft_putchar('\n');
		}
		else if (content[i][0] != '.')
		{
			ft_putstr(content[i]);
			ft_putchar('\n');
		}
		i++;
	}
}

//method that will be used to get files that are not folders
int num_files(int argc, char **argv)
{
	int count;
	int i;
	DIR *mydir;

	i = 1;
	count = 0;
	while (argv[i] && argc > 1)
	{
		mydir = opendir(argv[i]);
		//printf("here\n");
		if (!mydir)
		{
			if (argv[i][0] != '-')
				count++;
		}
		else
			closedir(mydir);
		i++;
	}
	return (count);
}

//method that will be used o find the number of dirs passed to the program
int num_dir(int argc, char **argv)
{
	int count;
	int i;
	DIR *mydir;

	i = 0;
	count = 0;
	while (argv[i])
	{
		mydir = opendir(argv[i]);
		if (mydir)
		{
			count++;
			closedir(mydir);
		}
		i++;
	}
	return (count);
}

//method that will be used to save the other files that are not folders
char **save_files(int argc, char **argv)
{
	int tot;
	char **dir;
	DIR *mydir;
	int i;
	int j;

	tot = num_files(argc, argv);
	if (tot > 0)
		dir = (char **)malloc(sizeof(char *) * (tot));
	dir[tot] = NULL;
	i = 0;
	j = 1;
	while (j < argc)
	{
		mydir = opendir(argv[j]);
		if (!mydir)
		{
			if (argv[j][0] != '-')
			{
				dir[i] = argv[j];
				i++;
			}
		}
		else
			closedir(mydir);

		j++;
	}
	return (dir);
}

//method that will be used to save the dirs passed to programe
char **save_dirs(int argc, char **argv)
{
	int tot;
	char **dir;
	DIR *mydir;
	int i;
	int j;

	tot = num_dir(argc, argv);
	dir = (char **)malloc(sizeof(char *) * (tot));
	dir[tot] = NULL;
	i = 0;
	j = 1;
	while (j <= argc)
	{
		mydir = opendir(argv[j]);
		if (mydir)
		{
			dir[i] = argv[j];
			i++;
		}
		j++;
	}
	return (dir);
}

//method that will loop through each folder
void ft_ls(char *folder, struct dirent *files, t_flags flags, char **content)
{
	DIR *mydir;
	int tot;
	//folder = ft_strdup();
	//printf(">>>>%d\n", num_dir(argc, argv));
	mydir = opendir(folder);
	if (!mydir)
		printf("fail to open\n");
	tot = count(files, mydir, folder);
	content = get_content(tot, folder, flags);
	print_content(content, &flags);
	closedir(mydir);
}

int main(int argc, char **argv)
{
	char **content;
	t_flags flags;
	int tot;
	char **dirs;
	char **sFiles;
	int i;
	struct dirent *files;

	tot = check_flags(argc, argv, &flags);
	printf(">>>%d\n", num_files(argc, argv));
	int s = 0;
	if ((num_files(argc, argv)) > 0)
	{
		sFiles = save_files(argc, argv);
		int j = 0;
		//if ((num_files(argc, argv)) > 0)
		//	valid_file(content, sFiles);
		while (sFiles[j])
		{
			printf("--------%s\n", sFiles[j]);
			j++;
		}
	}
	printf(">>>output == %d\n", tot);
	if (tot == INVALID_FLAG)
		dirs = save_dirs(argc, argv);
	if ((num_dir(argc, argv)) == 0 && tot == INVALID_FLAG)
	{
		ft_putstr("invalid input\n");
		return (INVALID_FLAG);
	}
	else if ((tot = num_dir(argc, argv)) == 0)
		ft_ls(".", files, flags, content);
	else
	{
		i = 0;
		while (i < tot)
		{
			//valid_file(save_(tot, dirs[i]), sFiles);
			content = save_(dirs[i]);
			// while (content[s])
			// {
			// 	printf(">>>>>%s\n", content[s]);
			// 	s++;
			// }

			ft_putchar('\n');
			ft_ls(dirs[i], files, flags, content);
			ft_putchar('\n');
			i++;
		}
	}
	return (SUCCESS);
}