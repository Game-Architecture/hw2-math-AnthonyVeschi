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
	(*this) = { { { 1, 0, 0, 0 },{ 0, 1, 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 1 } } };
}

void ga_mat4f::make_translation(const ga_vec3f& __restrict t)
{
	(*this) = { { { 1, 0, 0, 0 },{ 0, 1, 0, 0 },{ 0, 0, 1, 0 },{ t.x, t.y, t.z, 1 } } };
}

void ga_mat4f::make_scaling(float s)
{
	(*this) = { { { s, 0, 0, 0 },{ 0, s, 0, 0 },{ 0, 0, s, 0 },{ 0, 0, 0, 1 } } };
}

void ga_mat4f::make_rotation_x(float angle)
{
	(*this) = { { { 1, 0, 0, 0 },{ 0, cos(angle), sin(angle), 0 },{ 0, -sin(angle), cos(angle), 0 },{ 0, 0, 0, 1 } } };
}

void ga_mat4f::make_rotation_y(float angle)
{
	(*this) = { { { cos(angle), 0, -sin(angle), 0 },{ 0, 1, 0, 0 },{ sin(angle), 0, cos(angle), 0 },{ 0, 0, 0, 1 } } };
}

void ga_mat4f::make_rotation_z(float angle)
{
	(*this) = { { { cos(angle), sin(angle), 0, 0 },{ -sin(angle), cos(angle), 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 1 } } };
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
	ga_mat4f result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.data[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				result.data[i][j] += data[i][k] * b.data[k][j];
			}
		}
	}

	return result;
}

ga_mat4f& ga_mat4f::operator*=(const ga_mat4f& __restrict m)
{
	(*this) = (*this) * m;
	return (*this);
}

ga_vec4f ga_mat4f::transform(const ga_vec4f& __restrict in) const
{
	float temp[4] = { 0, 0, 0, 0 };
	float inn[4];
	inn[0] = in.x;
	inn[1] = in.y;
	inn[2] = in.z;
	inn[3] = in.w;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[i] += data[j][i] * inn[j];
		}
	}

	ga_vec4f result;
	result.x = temp[0];
	result.y = temp[1];
	result.z = temp[2];
	result.w = temp[3];
	return result;
}

ga_vec3f ga_mat4f::transform_vector(const ga_vec3f& __restrict in) const
{
	ga_vec4f temp;
	temp.x = in.x;
	temp.y = in.y;
	temp.z = in.z;
	temp.w = 0;

	ga_vec4f result = transform(temp);
	ga_vec3f resultt;
	resultt.x = result.x;
	resultt.y = result.y;
	resultt.z = result.z;
	return resultt;
}

ga_vec3f ga_mat4f::transform_point(const ga_vec3f& __restrict in) const
{
	ga_vec4f temp;
	temp.x = in.x;
	temp.y = in.y;
	temp.z = in.z;
	temp.w = 1;

	ga_vec4f result = transform(temp);
	ga_vec3f resultt;
	resultt.x = result.x;
	resultt.y = result.y;
	resultt.z = result.z;
	return resultt;
}

void ga_mat4f::transpose()
{
	ga_mat4f result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.data[i][j] = data[j][i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] = result.data[i][j];
		}
	}
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
