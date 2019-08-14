/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:18:49 by akalombo          #+#    #+#             */
/*   Updated: 2019/08/13 11:51:20 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h" 

//this method will be used to get the number of links for each file/folder
int             get_nLinks(char *content)
{
    int i;
    int nlinks;
    struct stat buff;
    i = stat(content, &buff);
    nlinks = buff.st_nlink;
    return (nlinks);
}

//this method will tell if a file is a folder or not
int             is_file(int nlinks)
{
    if (nlinks == 1)
        return (IS_FILE);
    else
        return (IS_FOLDER);
}

//method that will be used to get the number of bytes per file/dir
int             nBytes(char *content)
{
    int Bytes;
    int i;
    struct stat buff;
    i = stat(content, &buff);
    Bytes = buff.st_size;
    return (Bytes);
}

//working with lists
//storing all the data about the file within the lst node
void            saveData(int numFiles,char  **content, t_list *lst, char *folder)
{
    char *full_path;
    t_list head;
    int i;

    i = 0;
    head.next = (t_list*)&head;
    head.prev = (t_list*)&head;
    while(i < numFiles)
    {
        full_path = get_path(folder, content[i]);
        lst = (t_list *)malloc(sizeof(t_list));
        lst->fileName = content[i];
        lst->nLinks = get_nLinks(full_path);
        lst->dirORfile = is_file(lst->nLinks);
        lst->nBytes = nBytes(full_path);
        lst->last_modified = last_mod(full_path);
        lst->user = user(full_path);
        lst->group = group(full_path);
        lst->next = head.next;
        lst->permits = permits(full_path);
        head.next = lst;
        lst->prev = &head;
        lst->next->prev = lst;
        i++;
    }
    lst = head.prev;
    while(lst != &head)
    {
       printf("\r%s\t%d\t%s\t%s\t%d\t%s\t%s\n", lst->permits, lst->nLinks, lst->user, lst->group, lst->nBytes, lst->last_modified, lst->fileName);
       lst = lst->prev;
     }
}
