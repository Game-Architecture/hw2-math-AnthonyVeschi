/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "math/ga_vec3f.h"

#include <cassert>

void ga_vec3f_tests()
{
	ga_vec3f a{ 1.0f, 0.0f, -1.0f };
	ga_vec3f b{ 3.0f, -2.0f, 5.0f };

	assert((-a).equal({ -1.0f, 0.0f, 1.0f }));

	assert((a + b).equal({ 4.0f, -2.0f, 4.0f }));
	assert((a + b).equal(b + a));
	assert((a + a).equal(2.0f * a));
	assert((a + -a).equal(ga_vec3f::zero_vector()));

	assert((a - b).equal({ -2.0f, 2.0f, -6.0f }));
	assert((a + -b).equal((a - b)));
	assert((a - a).equal(ga_vec3f::zero_vector()));

	assert((2.0f * a).equal({ 2.0f, 0.0f, -2.0f }));
	assert((1.0f * b).equal(b));
	assert((0.0f * b).equal(ga_vec3f::zero_vector()));

	assert((5.0f * ga_vec3f::x_vector()).normal().equal(ga_vec3f::x_vector()));
	assert((5.0f * a).normal().equal(a.normal()));
	assert(ga_vec3f::x_vector().normal().equal(ga_vec3f::x_vector()));
	assert(ga_vec3f::x_vector().normal().equal(ga_vec3f::x_vector()));

	assert(ga_equalf(a.dot(b), -2.0f));
	assert(ga_equalf(b.dot(a), -2.0f));
	assert(ga_equalf(b.dot(-a), 2.0f));

	assert(ga_equalf(ga_vec3f::zero_vector().mag(), 0.0f));
	assert(ga_equalf(ga_vec3f::x_vector().mag(), 1.0f));
	assert(ga_equalf((-a).mag(), a.mag()));
	assert(ga_equalf((5.0f * ga_vec3f::x_vector()).mag(), 5.0f));
	assert(ga_equalf((5.0f * ga_vec3f::x_vector()).mag2(), (5.0f * ga_vec3f::x_vector()).dot(5.0f * ga_vec3f::x_vector())));

	assert(a.cross(b).equal({ -2.0f, -8.0f, -2.0f }));
	assert(b.cross(a).equal({ 2.0f, 8.0f, 2.0f }));
	assert(b.cross(-a).equal({ -2.0f, -8.0f, -2.0f }));

	assert(a.project_onto(ga_vec3f::x_vector()).equal({ a.x, 0.0f, 0.0f }));
	assert(a.project_onto(ga_vec3f::y_vector()).equal({ 0.0f, a.y, 0.0f }));
	assert(a.project_onto(ga_vec3f::z_vector()).equal({ 0.0f, 0.0f, a.z }));
	assert(a.project_onto(b).equal(a.project_onto(-b)));
}