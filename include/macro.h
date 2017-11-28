/*
** macro.h for  in /home/fabian/rendu/lib_lapin/wolf3d/include
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Wed May 18 17:41:51 2016 Zouz
** Last update Sun Jun  5 16:14:17 2016 Zouz Le Maux
*/

#ifndef _MACRO_H_

#include <lapin.h>

# define _MACRO_H_

# define UNUSED			__attribute__((unused))
# define WIN_SIZE_X		1920
# define WIN_SIZE_Y		1080
# define FPS			60
# define wiew			0.523599
# define STEPE			5
# define STEP_HIT		5
# define WALL_SIZE		100
# define SIZE_SCREEN		(WIN_SIZE_X * WIN_SIZE_Y)
# define CAMERA_HIGH		(SIZE_WALL / 2)
# define ABS(x)			((x > 0) ? (x) : (-x))
# define ROTATION_SPEED		0.2
# define CAMERA_FIELD_D		60
# define CAMERA_FIELD_R         (M_PI * (CAMERA_FIELD_D)) / 180
# define CAMERA_MAX_FIELD	CAMERA_FIELD_R + (CAMERA_FILED_R / 2)
# define CAMERA_MIN_FIELD	CAMERA_FIELD_R - (CAMERA_FILED_R / 2)
# define DISTANCE_SCR_CAM	277
# define PROJECTION_CENTER_X	WIN_SIZE_X / 2
# define PROJECTION_CENTER_Y	WIN_SIZE_Y / 2
# define ANGLE_BTW_VECTOR	CAMERA_FIELD_D / WIN_SIZE_X
# define WALL_COLOR_SIDE_1	RED
# define WALL_COLOR_SIDE_2	GREEN
# define SKY_COLOR		BLUE
# define FLOOR_COLOR		PINK
# define LVL			"level1"
# define F_NAME			"name"
# define F_TILE_SIZE		"tile_size"
# define F_WIDTH		"width"
# define F_HEIGHT		"height"
# define F_DATA			"data"
# define F_START_POS		"start_position"

#endif /* !MACRO_H_ */
