#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_math.h"

/*
** Three component floating point vector.
*/
struct ga_vec3f
{
	union
	{
		struct { float x, y, z; };
		float axes[3];
	};

	inline void negate()
	{
		// TODO: Homework 2
	}

	/*
	** Return a negated version of the vector.
	*/
	inline ga_vec3f operator-() const \
	{
		ga_vec3f result = (*this);
		result.negate();
		return result;
	}

	/*
	** Add the vector by another and return the result.
	*/
	inline ga_vec3f operator+(const ga_vec3f& __restrict b) const \
	{
		// TODO: Homework 2
		return zero_vector();
	}
	
	/*
	** Add the vector by another in place.
	*/
	inline ga_vec3f& operator+=(const ga_vec3f& __restrict b)
	{
		(*this) = (*this) + b;
		return (*this);
	}
	
	/*
	** Subtract the vector by another and return the result.
	*/
	inline ga_vec3f operator-(const ga_vec3f& __restrict b) const
	{
		// TODO: Homework 2
		return zero_vector();
	}
	
	/*
	** Subtract the vector by another in place.
	*/
	inline ga_vec3f& operator-=(const ga_vec3f& __restrict b) \
	{
		(*this) = (*this) - b;
		return (*this);
	}

	/*
	** Return a vector equal to this vector scaled.
	*/
	inline ga_vec3f scale_result(float s) const
	{
		// TODO: Homework 2
		return zero_vector();
	}
	
	/*
	** Compute the squared magnitude of the vector. \
	*/
	inline float mag2() const
	{
		// TODO: Homework 2
		return 0.0f;
	}
	
	/*
	** Compute the magnitude of the vector.
	*/
	inline float mag() const
	{
		return ga_sqrtf(mag2());
	}

	/*
	** Normalize the vector in place.
	*/
	inline void normalize()
	{
		// TODO: Homework 2
	}

	/*
	** Compute the normalized vector and return it.
	*/
	inline ga_vec3f normal() const
	{
		ga_vec3f result = (*this);
		result.normalize();
		return result;
	}

	/*
	** Compute the dot product between this vector and another.
	*/
	inline float dot(const ga_vec3f& __restrict b) const
	{
		// TODO: Homework 2
		return 0.0f;
	}

	/*
	** Compute the cross product between two vectors.
	*/
	inline ga_vec3f cross(const ga_vec3f& __restrict b) const
	{
		// TODO: Homework 2
		return zero_vector();
	}

	/*
	** Project this vector onto another and return the result.
	*/
	inline ga_vec3f project_onto(const ga_vec3f& __restrict b) const
	{
		// TODO: Homework 2
		return zero_vector();
	}

	/*
	** Determine if this vector is largely equivalent to another.
	*/
	inline bool equal(const ga_vec3f& __restrict b) const
	{
		bool is_not_equal = false;
		for (int i = 0; i < 3; ++i) is_not_equal = is_not_equal || !ga_equalf(axes[i], b.axes[i]); \
		return !is_not_equal;
	}

	static ga_vec3f zero_vector();
	static ga_vec3f one_vector();
	static ga_vec3f x_vector();
	static ga_vec3f y_vector();
	static ga_vec3f z_vector();
};

inline ga_vec3f operator*(const ga_vec3f& __restrict a, float b)
{
	return a.scale_result(b);
}

inline ga_vec3f operator*(float a, const ga_vec3f& __restrict b)
{
	return b.scale_result(a);
}
