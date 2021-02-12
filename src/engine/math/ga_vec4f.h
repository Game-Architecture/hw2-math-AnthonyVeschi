#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

/*
** Four component floating point vector.
*/
struct ga_vec4f
{
	union
	{
		struct { float x, y, z, w; };
		float axes[4];
	};

	static ga_vec4f zero_vector();
	static ga_vec4f one_vector();
	static ga_vec4f x_vector();
	static ga_vec4f y_vector();
	static ga_vec4f z_vector();
	static ga_vec4f w_vector();
};
