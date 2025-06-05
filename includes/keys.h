/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:04:36 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/05 12:37:35 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include <X11/keysym.h>

# define CLOSING_X 17

enum e_keyhook {
	KEY_ESC = XK_Escape,
	KEY_W = XK_w,
	KEY_A = XK_a,
	KEY_S = XK_s,
	KEY_D = XK_d,
	KEY_UP = XK_Up,
	KEY_DOWN = XK_Down,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
	KEY_PLUS = XK_equal,
	KEY_MINUS = XK_minus,
	KEY_PLUS_NUMPAD = XK_KP_Add,
	KEY_MINUS_NUMPAD = XK_KP_Subtract,
	KEY_1 = XK_1,
	KEY_2 = XK_2,
	KEY_3 = XK_3,
	KEY_4 = XK_4,
	KEY_5 = XK_5,
	KEY_1_NUMPAD = XK_KP_End,
	KEY_2_NUMPAD = XK_KP_Down,
	KEY_3_NUMPAD = XK_KP_Page_Down,
	KEY_4_NUMPAD = XK_KP_Left,
	KEY_5_NUMPAD = XK_KP_Begin,
	KEY_R = XK_r,
	KEY_G = XK_g,
	KEY_B = XK_b,
	KEY_E = XK_e,
	KEY_F = XK_f,
	KEY_V = XK_v,
	KEY_P = XK_p,
	KEY_M = XK_m,
};

enum e_mousehook {
	LEFT_CLICK = 1,
	MID_CLICK = 2,
	RIGHT_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
};

#endif