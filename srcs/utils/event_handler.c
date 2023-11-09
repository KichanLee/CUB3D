/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:28:39 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 16:44:15 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exit_event_handler(int key_code, void *param);
int			press_event_handler(int key_code, t_key *key);
int			release_event_handler(int key_code, t_key *key);
void		exception_handler(t_err errno);
static char	*ft_strerror(t_err errno);

int	exit_event_handler(int key_code, void *param)
{
	(void)key_code;
	(void)param;
	exit(0);
}

int	press_event_handler(int key_code, t_key *key)
{
	if (key_code == KEY_W)
		key->w = TRUE;
	if (key_code == KEY_S)
		key->s = TRUE;
	if (key_code == KEY_A)
		key->a = TRUE;
	if (key_code == KEY_D)
		key->d = TRUE;
	if (key_code == KEY_LEFT)
		key->left = TRUE;
	if (key_code == KEY_RIGHT)
		key->right = TRUE;
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int	release_event_handler(int key_code, t_key *key)
{
	if (key_code == KEY_W)
		key->w = FALSE;
	if (key_code == KEY_S)
		key->s = FALSE;
	if (key_code == KEY_A)
		key->a = FALSE;
	if (key_code == KEY_D)
		key->d = FALSE;
	if (key_code == KEY_LEFT)
		key->left = FALSE;
	if (key_code == KEY_RIGHT)
		key->right = FALSE;
	return (0);
}

void	exception_handler(t_err errno)
{
	char	*err_msg;

	err_msg = ft_strerror(errno);
	if (!err_msg)
		printf("Error\n");
	else
		printf("Error: %s\n", err_msg);
	exit(errno);
}

static char	*ft_strerror(t_err errno)
{
	if (errno == err_arg)
		return ("Check argument");
	else if (errno == err_file)
		return ("Check file");
	else if (errno == err_id)
		return ("Check element");
	else if (errno == err_img)
		return ("Check image path");
	else if (errno == err_rgb)
		return ("Check RGB values");
	else if (errno == err_map)
		return ("Check Map");
	else if (errno == err_wall)
		return ("Wall is not closed");
	else if (errno == err_player)
		return ("player is not ready");
	else if (errno == err_general)
		return ("Fatal: Error");
	else
		return (0);
}
