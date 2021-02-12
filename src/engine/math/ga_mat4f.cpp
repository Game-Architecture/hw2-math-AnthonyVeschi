/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "math/ga_mat4f.h"

#include "math/ga_math.h"

#include <cmath>

void ga_mat4f::make_identity()
{
	// TODO: Homework 2
}

void ga_mat4f::make_translation(const ga_vec3f& __restrict t)
{
	// TODO: Homework 2
}

void ga_mat4f::make_scaling(float s)
{
	// TODO: Homework 2
}

void ga_mat4f::make_rotation_x(float angle)
{
	// TODO: Homework 2
}

void ga_mat4f::make_rotation_y(float angle)
{
	// TODO: Homework 2
}

void ga_mat4f::make_rotation_z(float angle)
{
	// TODO: Homework 2
}

void ga_mat4f::translate(const ga_vec3f& __restrict t)
{
	ga_mat4f tmp;
	tmp.make_translation(t);
	(*this) *= tmp;
}

void ga_mat4f::scale(float s)
{
	ga_mat4f tmp;
	tmp.make_scaling(s);
	(*this) *= tmp;
}

void ga_mat4f::rotate_x(float angle)
{
	ga_mat4f tmp;
	tmp.make_rotation_x(angle);
	(*this) *= tmp;
}

void ga_mat4f::rotate_y(float angle)
{
	ga_mat4f tmp;
	tmp.make_rotation_y(angle);
	(*this) *= tmp;
}

void ga_mat4f::rotate_z(float angle)
{
	ga_mat4f tmp;
	tmp.make_rotation_z(angle);
	(*this) *= tmp;
}

ga_mat4f ga_mat4f::operator*(const ga_mat4f& __restrict b) const
{
	// TODO: Homework 2

	return (*this);
}

ga_mat4f& ga_mat4f::operator*=(const ga_mat4f& __restrict m)
{
	(*this) = (*this) * m;
	return (*this);
}

ga_vec4f ga_mat4f::transform(const ga_vec4f& __restrict in) const
{
	// TODO: Homework 2

	return ga_vec4f::zero_vector();
}

ga_vec3f ga_mat4f::transform_vector(const ga_vec3f& __restrict in) const
{
	// TODO: Homework 2

	return ga_vec3f::zero_vector();
}

ga_vec3f ga_mat4f::transform_point(const ga_vec3f& __restrict in) const
{
	// TODO: Homework 2

	return ga_vec3f::zero_vector();
}

void ga_mat4f::transpose()
{
	// TODO: Homework 2
}

bool ga_mat4f::equal(const ga_mat4f& __restrict b)
{
	bool is_not_equal = false;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			is_not_equal = is_not_equal || !ga_equalf(data[i][j], b.data[i][j]);
		}
	}
	return !is_not_equal;
}
