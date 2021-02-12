/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "math/ga_mat4f.h"

#include <cassert>

void ga_mat4f_tests()
{
	ga_mat4f m1, m2, m3;

	m1.make_identity();

	m2 = { { { 1, 0, 0, 0 },{ 0, 1, 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 1 } } };

	assert(m1.equal(m2));

	m1.transpose();

	assert(m1.equal(m2));

	m1 = { { { 2, 0, 0, 0 },{ 0, 2, 0, 0 },{ 0, 0, 2, 0 },{ 0, 0, 0, 1 } } };

	m2.make_scaling(2);

	assert(m1.equal(m2));

	m1 = { { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } } };

	m1.transpose();

	m2 = { { { 1, 5, 9, 13 },{ 2, 6, 10, 14 },{ 3, 7, 11, 15 },{ 4, 8, 12, 16 } } };

	assert(m1.equal(m2));

	m1.make_identity();

	m2.make_rotation_x(0.0f);

	assert(m1.equal(m2));

	m1.make_rotation_x(GA_PI / 2.0f);

	m2 = { { { 1, 0, 0, 0 },{ 0, 0, 1, 0 },{ 0, -1, 0, 0 },{ 0, 0, 0, 1 } } };

	assert(m1.equal(m2));

	m1.make_rotation_y(GA_PI / 2.0f);

	m2 = { { { 0, 0, -1, 0 },{ 0, 1, 0, 0 },{ 1, 0, 0, 0 },{ 0, 0, 0, 1 } } };

	assert(m1.equal(m2));

	m1.make_rotation_z(GA_PI / 2.0f);

	m2 = { { { 0, 1, 0, 0 },{ -1, 0, 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 1 } } };

	assert(m1.equal(m2));

	m1.rotate_x(2 * GA_PI);

	assert(m1.equal(m2));

	m1.rotate_y(2 * GA_PI);

	assert(m1.equal(m2));

	m1.rotate_z(2 * GA_PI);

	assert(m1.equal(m2));

	ga_vec3f v1, v2;

	m1.make_rotation_z(GA_PI);

	v1 = { 1, 0, 0 };

	v2 = m1.transform_vector(v1);

	assert(v2.equal({ -1, 0, 0 }));

	m1.make_rotation_x(-GA_PI / 2);

	v1 = { 0, 1, 0 };

	v2 = m1.transform_vector(v1);

	assert(v2.equal({ 0, 0, -1 }));

	v2 = m1.transform_point(v1);

	assert(v2.equal({ 0, 0, -1 }));

	m1.make_translation({ 2, 0, 3 });

	v2 = m1.transform_vector(v1);

	assert(v2.equal(v1));

	v2 = m1.transform_point(v1);

	assert(v2.equal({ 2, 1, 3 }));

	m1.make_rotation_x(GA_PI);

	m2.make_rotation_x(GA_PI / 4);

	m3 = m2 * m2 * m2 * m2;

	assert(m1.equal(m3));

	m1.make_translation({ 1, 0, -1 });

	m2.make_translation({ 1, 0, 0 });

	m3 = m2;

	m2.make_translation({ 0, 0, -1 });

	m3 *= m2;

	assert(m1.equal(m3));

	m1.make_rotation_y(GA_PI / 2);
	m1.translate({ 2, -3, 0 });

	m2 = { { { 0, 0, -1, 0 },{ 0, 1, 0, 0 },{ 1, 0, 0, 0 },{ 2, -3, 0, 1 } } };

	assert(m1.equal(m2));

	m1.make_translation({ 2, -3, 0 });
	m1.rotate_y(GA_PI / 2);

	m2 = { { { 0, 0, -1, 0 },{ 0, 1, 0, 0 },{ 1, 0, 0, 0 },{ 0, -3, -2, 1 } } };

	assert(m1.equal(m2));
}