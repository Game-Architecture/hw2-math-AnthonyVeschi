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
		(*this).x = -(*this).x;
		(*this).y = -(*this).y;
		(*this).z = -(*this).z;
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
		ga_vec3f result;
		result.x = (*this).x + b.x;
		result.y = (*this).y + b.y;
		result.z = (*this).z + b.z;
		return result;
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
		ga_vec3f result;
		result.x = (*this).x - b.x;
		result.y = (*this).y - b.y;
		result.z = (*this).z - b.z;
		return result;
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
		ga_vec3f result;
		result.x = (*this).x * s;
		result.y = (*this).y * s;
		result.z = (*this).z * s;
		return result;
	}
	
	/*
	** Compute the squared magnitude of the vector. \
	*/
	inline float mag2() const
	{
		float result = (*this).dot((*this));
		return result;
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
		float mag = (*this).mag();
		(*this).x /= mag;
		(*this).y /= mag;
		(*this).z /= mag;
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
		float result = ((*this).x * b.x) + ((*this).y * b.y) + ((*this).z * b.z);
		return result;
	}

	/*
	** Compute the cross product between two vectors.
	*/
	inline ga_vec3f cross(const ga_vec3f& __restrict b) const
	{
		ga_vec3f result;
		result.x = ((*this).y * b.z) - ((*this).z * b.y);
		result.y = ((*this).z * b.x) - ((*this).x * b.z);
		result.z = ((*this).x * b.y) - ((*this).y * b.x);
		return result;
	}

	/*
	** Project this vector onto another and return the result.
	*/
	inline ga_vec3f project_onto(const ga_vec3f& __restrict b) const
	{
		ga_vec3f result;
		result = b.scale_result(((*this).dot(b) / b.mag2()));
		return result;
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
